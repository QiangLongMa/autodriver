#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/int64_multi_array.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/float32.hpp"
#include"std_msgs/msg/int32.hpp"
#include <Eigen/Eigen>
#include<Eigen/Dense>
#include<Eigen/Core>
#include "toolKits.h"
#include "localFuns.h"
#include "lqr.h"
#include "PID.h"
#include "stanley.h"
#include <fstream>
#include"Projectionpointcalculation.h"
#include"pure_pursuit.h"
#include"digital_filter_coefficients.h"
#include"digital_filter.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // 包含 <cstdlib> 头文件以使用 std::abs()
#include "lon_controller.h"
#include <chrono>
#define ts_ 0.02//0.01 car0.02 yijie
#define cutoff_freq 8   //20  ///8  car yijie  
class control_node : public rclcpp::Node{
    public:
        //构造函数,有一个参数为节点名称
        control_node(std::string name) : Node(name){
            RCLCPP_INFO(this->get_logger(), "%s start!", name.c_str());
            //创建话题订阅者，订阅GPS消息
            gps_subscribe = this->create_subscription<std_msgs::msg::Float64MultiArray>("gps", 5, std::bind(&control_node::gps_callback, this, std::placeholders::_1));
            //创建话题订阅者, 订阅者全局路径消息
            local_subscribe = this->create_subscription<std_msgs::msg::Float64MultiArray>("local_to_control_pub", 10, std::bind(&control_node::local_callback, this, std::placeholders::_1));
            
            local_subscribe0 = this->create_subscription<std_msgs::msg::Float64MultiArray>("local_publisher", 10, std::bind(&control_node::local_callback0, this, std::placeholders::_1));
            
            
            sub_global=this->create_subscription<std_msgs::msg::Float64MultiArray>("global_local_topic", 10, std::bind(&control_node::global_callback, this, std::placeholders::_1));
            
            //创建相机目标检测订阅者
            sub_cam = this->create_subscription<std_msgs::msg::Float64MultiArray>("cam_pub", 10, std::bind(&control_node::cam_callback, this, std::placeholders::_1));
            
            
            sub_lidar = this->create_subscription<std_msgs::msg::Float64MultiArray>("pub_control_obses", 1, std::bind(&control_node::lidar_callback, this, std::placeholders::_1));

            pub_can= this->create_publisher<std_msgs::msg::Float32MultiArray>("/control_pub",1);

            sub_DecelerateFlag= this->create_subscription<std_msgs::msg::Int32>("pub_DecelerateFlag", 5, std::bind(&control_node::subDecelerateFlag, this, std::placeholders::_1));

           // sub_global= this->create_publisher<std_msgs::msg::Float64MultiArray>("global_local_topic",10);
            pub_speed = this->create_publisher<std_msgs::msg::Float32>("/speed_topic",1);
            pub_error = this->create_publisher<std_msgs::msg::Float32>("/error_topic",1);

            //创建话题订阅者, 订阅者速度与档位消息
            speed_gears_subscribe = this->create_subscription<std_msgs::msg::Int64MultiArray>("speed_gears_pub", 10, std::bind(&control_node::speed_gears_callback, this, std::placeholders::_1));
            //初始化can
            //can_set();
            //定时发送can报文
            oendTime = std::chrono::steady_clock::now();
            sTime = std::chrono::steady_clock::now();
            // timer_ = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&control_node::timer_can_callback, this));  
            timer0 = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&control_node::timer_can_callback0, this));     
            // control_publisher = this->create_publisher<std_msgs::msg::Float64MultiArray>("control_pub", 10);         
            ofs.open(fileName);
            double kp = 50, ki = 0, kd = 0;
            pid.setPID(kp,ki,kd);    
        }

        void gps_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            auto start = std::chrono::high_resolution_clock::now();  
            if(msg->data.size()!=0){            
                // // GPS Data
                gpsx = msg->data[0]; 
                gpsy = msg->data[1];
                gpsD = msg->data[2];
                gpsS = msg->data[3];
                gpsA = msg->data[7];
                if((optTrajxy.array() != 0.0).any() == 0){
                    //std::cout << "Waiting local traj receive,check local node..." << std::endl;
                    newSpeedRef=0;
                } else {
                    if(!in_flag){
                        std::cout << "Local traj has been generated!" << std::endl;
                        newSpeedRef=0;
                        in_flag = true;
                    }
                    if(run_stop_flag){
                        car.resize(5,1);
                        tool::getCarPosition(gpsx, gpsy, gpsD, gpsS, car);
                        if(optTrajxy.cols()== 1 && optTrajxy.rows() == 1){
                            std::cout<<"optTrajxy in None!!!"<<std::endl;
                            newSpeedRef=0;    
                        }
                        else{
                            int pre_index = (index + 5) > (globalPath.cols()-1) ? 
                                            (globalPath.cols()-1) : (index + 5);//在全局路径向前四个点 也就是2m的距离 
                            //速度较大时，直线段的一种情况 
                            // pre_distance=2;
                            //double kp = 100, ki = 0, kd = 0;
                            //pid.setPID(kp,ki,kd);  
                            prepoint = 0;//弯道时预瞄距离变短两个点的育苗 1m
                            // Q <<500,  0,  0,
                            //     0, 500,  0,
                            //     0,  0, 200;
                            // R << 0, 0, 0, 100;
                            Q <<10,  0,  0,
                                0, 10,  0,
                                0,  0, 9;
                            R << 0, 0, 0, 9;
                            // if (std::abs(globalPath(4, index) < 0.05)){
                            //     pre_distance=2;
                            //     //double kp = 100, ki = 0, kd = 0;
                            //     //pid.setPID(kp,ki,kd);  
                            //     prepoint=0;//弯道时预瞄距离变短
                            //     Q <<10,  0,  0,
                            //         0, 10,  0,
                            //         0,  0, 9;
                            //     R << 0, 0, 0, 5;
                            // }
                            // //弯道 
                            // else if (std::abs(globalPath(4,index) >= 0.05)){
                            //     //pre_distance=2;//纯路径跟踪的预瞄距离 
                            //     //double kp = 100, ki = 0, kd = 0;
                            //     //pid.setPID(kp,ki,kd);  
                            //     prepoint=0;//弯道时预瞄距离变长 
                            //     Q <<10,  0,  0,
                            //         0, 10,  0,
                            //         0,  0, 9;
                            //     R << 0, 0, 0, 5; //4
                            // }
                            //弯道  m
                            local::findClosestPoint(car, optTrajxy, closestIndex);
                            int pre_closestIndex = (closestIndex + prepoint) > (optTrajxy.cols()-1) ? 
                                            (optTrajxy.cols()-1):(closestIndex + prepoint);//预瞄点的数量为2
                            // x y v thea dk 投点计算 
                            std::array<double,5> Projection_point_message = 
                                                Projectionpoint::GetProjectionpoint(closestIndex,optTrajxy,car(0),car(1));
                            
                            double dx = car(0) - optTrajxy(0, pre_closestIndex);
                            double dy = car(1) - optTrajxy(1, pre_closestIndex);
                            double theta = optTrajxy(3, pre_closestIndex);
                            float error = dy * std::cos(theta) - dx * std::sin(theta);
                            std_msgs::msg::Float32 error_msg;
                            error_msg.data = error;
                            pub_error->publish(error_msg);
                            double deltaX =  dx;
                            double deltaY =  dy;
                            double deltaYAW = tool::normalizeAngle(tool::d2r(car(3)) - theta);
                            /***************LQR***********/
                            /*Q中元素的大小表示状态量的重要程度，越大表示越重要，控制的快速性会越好，但会增大输入（能量消耗增多），导致超调、震荡可能会比较明显；
                            控制权重矩阵R中元素的大小表示对能量消耗的关注度，越大表示对该输入的能量消耗越敏感，会减小输入，有效降低超调、震荡，控制过程柔和，但快速性较差；
                            QR的选取是两种约束互相妥协的过程，重点关注调参*/
                            //在轨迹跟踪中，前一项优化目标表示跟踪过程路径偏差的累积大小，第二项优化目标表示跟踪过程控制能量的损耗
                            ref_delta = atan2(car(4) * optTrajxy(4, pre_closestIndex), 1);                     
                            LQR.stateSpaceMatrix(A, B, car, cps, ref_delta, theta);
                            //u = LQR.calcU(car, optTrajxy, pre_closestIndex, A, B, Q, R)(1);
                            u=LQR.calcU(car, optTrajxy, Projection_point_message, A, B, Q, R)(1);
                            u = -(u+ref_delta);//-kx+kl
                            // Q2 << 10      , 0    , 0,
                            //         0      , 10    , 0,
                            //         0      , 0    , 12;
                            // R2 << 5;   
                            // u = LQR.lqrComputeCommand(theta, deltaX, deltaY, deltaYAW, 
                            //                         optTrajxy(4, pre_closestIndex), 3.0,car(4),0.01,Q2,R2);          
                            /***************方向盘限幅*****************/
                            static double last_sw = 0;
                            const double swth = 520.0;
                            //弯道 
                            // if (std::abs(globalPath(4, index)) > 0.03 || std::abs(globalPath(4, pre_index)) > 0.03){
                            //     sw = K * u;
                            // }else{
                            //     sw = K * u;
                            // }
                            sw = K * u;
                            if(sw > swth){
                                sw = swth;
                            } else if (sw < -swth){
                                sw = -swth;
                            } 
                            //newSpeedRef = gpsS + globalPath(6,closestIndex)*0.1; 
                            // std::cout << "u: " <<  u << std::endl;
                            // std::cout << "sw: " << K * u<< std::endl;                                                               
                        }
                    }else{
                        newSpeedRef=0;
                    }
                }            
            }else{
                std::cout << "Local Node gps is none!!!" << std::endl;
                newSpeedRef=0;
            }
            auto end = std::chrono::high_resolution_clock::now();  
            std::chrono::duration<double> duration = end - start;
            //std::cout << "control运行时间: " << duration.count() << " 秒" << std::endl;
        } 
        
        void timer_can_callback0(){
            if(run_stop_flag){
                //没有局部路径规划 
                if((optTrajxy.array() != 0.0).any() == 0||optTrajxy.cols()== 1){
                    return;
                }
                /**********************激光雷达未启动时****************************/
                if ((obs_lidar.array()!=0.0).any()==0){
                    obs_lidar.setOnes(2,1);
                    obs_lidar*=1000;
                }
                Eigen::VectorXd::Index minCol;
                double min_long_dis = obs_lidar.row(0).minCoeff(&minCol);
                int mindex=0;
                // close Car 
                tool::frentPoint car_frent;
                if (car.size()!=0){
                    carfindClosestPoint(car,globalPath,mindex);
                    cartesianToFrenet(car,globalPath,car_frent,mindex);
                    index =mindex;
                }else{
                    return;
                }
                bool UES_PID = false;
                if(!UES_PID){
                    int pre_closestIndex = std::min(static_cast<int>(optTrajxy.cols()-1), closestIndex+1);
                    double a = optTrajxy(6,pre_closestIndex);
                    double target_v = optTrajxy(2,pre_closestIndex);
                    //std::cout<<"target_v: "<<target_v<<std::endl;  
                    //std::cout<<"a: "<<a<<std::endl;  
                    if(std::abs(a) <= 0.01){//当前的加速度为0
                        newSpeedRef = std::abs(target_v) * 3.6;//按照局部路径里的速度进行行驶
                    }else{
                        current_v = current_v + a * 0.01;// v =v +at 
                        //std::cout<<"current_v: "<<current_v<<std::endl;
                        if(a>0){
                            if(target_v==0){
                                current_v = std::min(current_v,target_v);// 不能超过设定的最大速度
                            }else{
                                current_v = std::min(current_v,target_v);// 不能超过设定的最大速度
                            }
                            newSpeedRef = std::ceil((current_v * 3.6));
                        }else if(a<0){
                            current_v = std::min(current_v,target_v);// 不能小于设定的最小速度
                            if(current_v<0){
                                current_v = 0;
                            }
                            newSpeedRef = std::ceil((current_v *3.6));// 
                        }
                        //std::cout<<"newSpeedRef: "<<newSpeedRef<<std::endl;
                    }
                } else {
                    /******************PID************************/
                    // x y theta v  a  解决不掉人为踩刹车 速度累加的行为 
                    double a;
                    std::tuple<double, double, double, double, double> vehicle_state;
                    vehicle_state = std::make_tuple(car(0), car(1), car(3), car(2), gpsA);
                    loncontroller_.Init(closestIndex, vehicle_state, localpath_time);
                    loncontroller_.ComputeControlCommand(optTrajxy, a);
                    //std::cout<<"pid a: "<<a<<std::endl;
                    current_v = current_v + a * 0.01;
                    if(current_v < 0) current_v = 0;
                    newSpeedRef = std::round(current_v * 3.6);
                    //std::cout<<"current_v: "<<current_v<<std::endl;
                }
                //std::cout<<"current_v: "<<current_v*3.6<<std::endl;
                std_msgs::msg::Float32 speed_msg;
                speed_msg.data = current_v;
                pub_speed->publish(speed_msg);
                
                if((std::abs((min_long_dis-car_frent.s) > disOfObsMin) && (std::abs(min_long_dis-car_frent.s) < disOfObsMax) && 
                            (std::fabs(obs_lidar(1, minCol)-car_frent.d) < 1.5))){
                    /*****************************AEB***********************************/
                    /*speed ,gear,sw,brake,flag */
                    SendCan(0,1,0,1,1);
                    std::cout << "Run-Brake!!!" << std::endl;
                }
                else{             
                   // std::cout << "index: " << index << ", maxIndex: " << maxIndex << std::endl;
                    if((index > (maxIndex - 40))){
                        /****************************End Stop*******************************/
                        SendCan(0,1,0,1,0);
                        std::cout << "End-brake!!!" << std::endl;
                        std::cout << "car.v: " << car(2) << std::endl;
                        if(gpsS < 0.03){
                            SendCan(0,1,1,1,0);
                            run_stop_flag = false;
                            std::cout << "End-Stop!!!" << std::endl;
                        }
                    }else{
                        /*****************Driving*******************/
                        std_msgs::msg::Float32MultiArray msg;
                        //接近局部路径的终点 车辆正在减速 3m的距离 
                        double local_length = optTrajxy.cols()*0.5;
                        // if(closestIndex>=static_cast<int>(optTrajxy.cols()-6)&&DecelerateFlag){//3m的距离 
                        //     SendCan(0,1,sw,1,1);//速度为0 刹车 
                        //     std::cout << "stop car!!!!" << std::endl; 
                        
                            //std::cout << "SendCannewSpeedRef: " <<newSpeedRef<< std::endl; 
                        SendCan(std::round(newSpeedRef),2,sw,0,1);    
                        //std::cout << "Driving!!!!" << std::endl; 
                    }      
                    // else if (closestIndex>(optTrajxy.cols()-speedRef*2))
                    // {
                    //     SendCan(0,1,0,1,0);
                    //     std::cout << "End-brake!!!" << std::endl;
                    // }          
                }                        
            }
            else{
                SendCan(0,1,0,1,0);
            }                 
        }
        
        void cam_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            /************************障碍物信息获取与处理*************************/
            Eigen::VectorXd r;
            int cols = 0;
            if(msg->data.size() == 0){//无可识别障碍物
                cols = 1;
                obs_cam.setOnes(5, cols);
                obs_cam*=100;
            }else{ //可识别障碍物
                cols = msg->data.size()/2;
                r.setOnes(cols);
                obs_cam.setZero(5, cols);
                Eigen::Map<Eigen::MatrixXd> obs_cam_pos(msg->data.data(), 2, cols);
                obs_cam.row(0) = obs_cam_pos.row(0);
                obs_cam.row(1) = obs_cam_pos.row(1);
                obs_cam.row(4) = r;
            }            
        }

        void lidar_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            /**获取激光雷达传递过来的信息*/  //min_x max_x min_y max_y thea 
            Eigen::VectorXd r;
            int cols =0;
            if (msg->data.size() == 0)
            {
                obs_lidar.setOnes(2,1); //没有接收到消息 激光雷达的储存队列为1
                obs_lidar*=1000; 
            }
            else{
                cols =msg->data.size()/2;
                obs_lidar.resize(2,cols);
                Eigen::Map<Eigen::MatrixXd> lidar(msg->data.data(),2,cols);
                obs_lidar.row(0)=lidar.row(0);//s
                obs_lidar.row(1)=lidar.row(1);//l
            }
        }
       
        void global_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            if(msg->data.size() != 0) {      
                int cols = msg->data.back();
                msg->data.pop_back();
                globalPath.resize(7, cols);
                Eigen::Map<Eigen::MatrixXd> globalPathReshaped(msg->data.data(), 7, cols);
                maxIndex = cols;
                globalPath= std::move(globalPathReshaped);
                std::cout<<"control golbal size: "<<globalPath.cols()<<std::endl;
            }
        }

        void local_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            if(msg->data.size() == 1 && msg->data[0] < 0)
            {
                /***********************制动***************************/
                optTrajxy.resize(1,1);
                Eigen::Map<Eigen::MatrixXd> optTrajxyReshaped(msg->data.data(), 1, 1);
                optTrajxy= optTrajxyReshaped;
                //std::cout << "No optimal local trajs generation"<< std::endl;
            }else{
                localpath_time = (int)msg->data.back();//获取车辆时间
                msg->data.pop_back();
               // maxIndex = (int)msg->data.back();//全局路径的长度 
                msg->data.pop_back();
                int cols = msg->data.size()/9;
                optTrajxy.resize(8, cols);
                Eigen::Map<Eigen::MatrixXd> optTrajxyReshaped(msg->data.data(), 9, cols);
                optTrajxy= std::move(optTrajxyReshaped);
            } 
           
        }

        void local_callback0(const std_msgs::msg::Float64MultiArray::SharedPtr msg){ 
            if(msg->data.size() == 1 && msg->data[0] < 0){
                /***********************制动***************************/
                optTrajxy0.resize(1,1);
                Eigen::Map<Eigen::MatrixXd> optTrajxyReshaped(msg->data.data(), 1, 1);
                optTrajxy0= optTrajxyReshaped;
                // std::cout << "No optimal local trajs generation 000"<< std::endl;
            }else{
                int cols = msg->data.size()/9;
                optTrajxy0.resize(8, cols);
                Eigen::Map<Eigen::MatrixXd> optTrajxyReshaped(msg->data.data(), 9, cols);
                optTrajxy0= optTrajxyReshaped;
            } 
            // std::cout << "control node_optTrajxy0 : " << std::endl;
            // std::cout << optTrajxy0.transpose() << std::endl;     
        }

        void speed_gears_callback(const std_msgs::msg::Int64MultiArray::SharedPtr msg){                 
            int gear_flag = msg->data[1];
            run_stop_flag = (bool)msg->data[2];
            if(run_stop_flag == true){ //run==true 启动
                speedRef = msg->data[0];
                switch (gear_flag){ //获得档位索引P = 0, N = 1, D = 2, R = 3;
                    case 0:{
                        gearsRef = 0xB;
                        break;
                    }
                    case 1:{
                        gearsRef = 0xA;
                        break;
                    }
                    case 2:{
                        gearsRef = 0x1;
                        break;
                    }
                    case 3:{
                        gearsRef = 0x9;
                        break;
                    }            
                    default:
                        break;
                }
            }
            std::cout << "speedRef:" << speedRef << ", "<< "gearsRef:" << gearsRef << ", "<< "flag:" << run_stop_flag << std::endl;
        }

        void subDecelerateFlag(const std_msgs::msg::Int32::SharedPtr msg){
            if (msg->data==0)
            {
                DecelerateFlag=false;
            }else{
                DecelerateFlag=true;
            }           
        }

        void SendCan(double speed,int gear,double sw_angle,int brake,int flag){
            std_msgs::msg::Float32MultiArray msg;
            msg.data.push_back(speed);//speed
            msg.data.push_back(gear);//gear  0 p     1  n     2 d    3   r
            msg.data.push_back(sw_angle);//sw_angle
            msg.data.push_back(brake);//brake
            msg.data.push_back(flag);//
            pub_can->publish(msg);
        }
        
        void carfindClosestPoint(const Eigen::VectorXd& realPosition, const Eigen::MatrixXd& globalPath, int& minIndex){
            static int startIndex = 0;
            static int end = globalPath.cols();
            double distance, d_min = 999999;
            int i = startIndex;
            for (; i < end; i++) {
                distance = std::abs(globalPath(0, i) - realPosition(0)) + std::abs(globalPath(1, i) - realPosition(1));
                if (distance < d_min) {
                    minIndex = i;
                    d_min = distance;
                    startIndex = i;
                }
            }
            startIndex = startIndex - 20 < 0 ? 0 : startIndex;
            end = startIndex + 100;
            end = end - globalPath.cols() < 0 ? end : globalPath.cols();
        }
        
        void cartesianToFrenet(const Eigen::VectorXd& CAR, const Eigen::MatrixXd& path, tool::frentPoint& carFrent, int& mindex) 
        {
            //findClosestPoint(car, path, minIndex);
            const double dx = CAR(0) - path(0,mindex);
            const double dy = CAR(1) - path(1,mindex);

            const double cos_theta_r = std::cos(path(3,mindex));
            const double sin_theta_r = std::sin(path(3,mindex));

            const double cross_rd_nd = cos_theta_r * dy - sin_theta_r * dx;
            // carFrentPoint.d = std::copysign(std::sqrt(dx * dx + dy * dy), cross_rd_nd);
            carFrent.d = std::copysign(cross_rd_nd, cross_rd_nd);
            carFrent.s = path(6, mindex);
        }
	
    private:
        // 声明gps话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr gps_subscribe;
        // 声明local_trajs话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr local_subscribe;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr local_subscribe0;
        // 声明cam话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_cam;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_lidar;
        // 声明speed_gears话题订阅者
        rclcpp::Subscription<std_msgs::msg::Int64MultiArray>::SharedPtr speed_gears_subscribe;
        //声明control话题发布者
        rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr pub_can;

        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_global;

        // rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr control_publisher;
        
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_DecelerateFlag;


        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_speed;
        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_error;



        // 声名Can定时器指针
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::TimerBase::SharedPtr timer0;

        Eigen::VectorXd car;
        Eigen::MatrixXd optTrajxy;//局部路径
        Eigen::MatrixXd optTrajxy0;//局部路径
        Eigen::MatrixXd optTrajsd;
        Eigen::MatrixXd obs_cam;
        Eigen::MatrixXd obs_lidar;
        Eigen::MatrixXd globalPath;//全局路径


        tool::controlParams cps;
        tool::frentPoint carFrentPoint;
        int closestIndex = 0;

        double gpsx;
        double gpsy;
        double gpsD;
        double gpsS;
        double gpsA;
        //int  index = -1;//最近点下标
        bool in_flag = false; //文本提示输出的标志位
        /*************From HMI**********************/
        bool run_stop_flag = false; //启动停止标志位
        double speedRef = 0; //设定速度
        unsigned short gearsRef = 0xA;
        double realSpeed = 0;//渐加速变量，最大为设定值
        double newSpeedRef=0;
        int prepoint = 0;//预瞄点的数量 

        /****************LQR**********/
        lqr LQR;
        Eigen::Matrix3d  Q;
        Eigen::Matrix2d  R;
        Eigen::MatrixXd Q2 = Eigen::MatrixXd::Zero(3,3);  
        Eigen::MatrixXd R2 = Eigen::MatrixXd::Zero(1,1);
       
        double ref_delta  = 0;
        Eigen::Matrix<double, 3, 3>  A;
        Eigen::Matrix<double, 3, 2>  B;

        Eigen::Matrix<double, 3, 3> Q_new;
        Eigen::Matrix<double, 1, 1> R_new;
        double u = 0.0;
        double K = 165;
        /*****************************/

        /***********stanley****************/
        double delta = 0.0;

        /***********PID*************/
        PID pid;
        /*********pure pursuit*****/

        pure_pursuit PURESUIT;
        double pre_distance =2 ;

        /********Can*********/
        int ret, ret2, ret3, ret4, ret5;
        float vel;
       
        bool exit_flag = true;

        /*************Cam Obs AEB******************/
        double disOfObsMax = 3;  //(单位：m)
        double disOfObsMin = 1;
        bool initstart = true;
        int index = 0;
        int maxIndex = 0;
        double sw=0;
        bool accflag=false;

        /******************************************/
        using time_point = std::chrono::steady_clock::time_point;
        using time_ms = std::chrono::milliseconds;
        time_point t1,t2,tk1,tk2,ntk1,ntk2,oendTime, sTime;
        time_ms ms,dtk,dntk;
        bool KF=true;
        bool NKF=true;

        /*******************/
        // double ts_=0.002; //采样时间 
        // int cutoff_freq=10;  //car yijie   截至频率

        /**********Out File**********/
        std::string fileName = "path1.txt";
        std::ofstream ofs;  //创建输入流对象 

        bool DecelerateFlag=false;
        double current_v;//车辆当前的速度 
        loncontroller loncontroller_;
        double localpath_time;


        double Constant_deceleration = -0.5; 
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<control_node>("control_node");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}