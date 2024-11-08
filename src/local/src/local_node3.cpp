#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "std_msgs/msg/int64_multi_array.hpp"
#include"std_msgs/msg/int32.hpp"
#include "ros2_path_interfaces/srv/path_interfaces.hpp"
#include "visualization_msgs/msg/marker.hpp" // 可视化消息类型
#include "visualization_msgs/msg/marker_array.hpp"
#include "geometry_msgs/msg/point.hpp"
#include"std_msgs/msg/float64.hpp"
#include"std_msgs/msg/string.hpp"
#include"std_msgs/msg/int16_multi_array.hpp"
#include <Eigen/Eigen>
#include "localFuns.h"
#include "toolKits.h"
#include <fstream>
#include"local_dp_qp.h"
#include <iostream>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include"Calobs.h"
#include"QP.h"
#include <limits>
#include<cstdio>
#include "localmath.h"
#define NANOS_PER_SECOND  1e9
using namespace std;

class local_trajs_node : public rclcpp::Node{
    public:
        //构造函数,有一个参数为节点名称
        local_trajs_node(std::string name) : Node(name){
            RCLCPP_INFO(this->get_logger(), "%s start!", name.c_str());
            // 创建服务端
            global_path_service_ = this->create_service<ros2_path_interfaces::srv::PathInterfaces>("global_path_srv", std::bind(&local_trajs_node::handle_response, this, std::placeholders::_1, std::placeholders::_2));
            //创建话题订阅者，订阅GPS消息
            gps_subscribe = this->create_subscription<std_msgs::msg::Float64MultiArray>("gps", 1, std::bind(&local_trajs_node::gps_callback, this, std::placeholders::_1));
            //创建话题订阅者, 订阅者全局路径消息
            global_path_subscribe = this->create_subscription<std_msgs::msg::Float64MultiArray>("global_local_topic", 10, std::bind(&local_trajs_node::global_callback, this, std::placeholders::_1));
            //创建局部路径发布者
            local_to_hmi_publisher = this->create_publisher<std_msgs::msg::Float64MultiArray>("local_publisher", 10);
            //Only to Control_node
            local_to_control_publisher = this->create_publisher<std_msgs::msg::Float64MultiArray>("local_to_control_pub", 10);

            sub_car_local = this->create_publisher<visualization_msgs::msg::MarkerArray>("car_local_points",10);

            pub_rviz_local = this->create_publisher<visualization_msgs::msg::Marker>("pub_rviz_local",10);

            pub_hmi_obses = this->create_publisher<std_msgs::msg::Float64MultiArray>("pub_hmi_obses", 10);

            pub_control_obses = this->create_publisher<std_msgs::msg::Float64MultiArray>("pub_control_obses", 10);

            pub_control_DecelerateFlag = this->create_publisher<std_msgs::msg::Int32>("pub_DecelerateFlag",10);

            pub_stop_line =  this->create_publisher<std_msgs::msg::Float64>("pub_stop_line" ,1);

            pub_global_obses = this->create_publisher<std_msgs::msg::Float64MultiArray>("global_obses", 1);
             //创建话题订阅者, 订阅者速度与档位消息
            speed_gears_subscribe = this->create_subscription<std_msgs::msg::Int64MultiArray>("speed_gears_pub", 10, std::bind(&local_trajs_node::speed_gears_callback, 
                this, std::placeholders::_1));
            //创建相机目标检测订阅者
            sub_cam = this->create_subscription<std_msgs::msg::Float64MultiArray>("cam_pub", 10, std::bind(&local_trajs_node::cam_callback, this, std::placeholders::_1));
            sub_LiDAR_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("lidar_pub",1,std::bind(&local_trajs_node::lidar_callback,this,std::placeholders::_1));
            //Timer_callback std::chrono::milliseconds(50)
            // timer_to_control = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&local_trajs_node::timer_local_callback_to_control, this));
            // timer_to_hmi = this->create_wall_timer(std::chrono::milliseconds(20), std::bind(&local_trajs_node::timer_local_callback_to_hmi, this));
            timer_DecelerateFlag = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&local_trajs_node::pubDecelerateFlag, this));
            timer_getlocalpath=this->create_wall_timer(std::chrono::milliseconds(Slowdowntimethreshold), std::bind(&local_trajs_node::GetLocalPath, this));
            outputFile.open(filename);
        }
        
        void SendControlObs(std::vector<obses_sd> &obses){
            std_msgs::msg::Float64MultiArray msg;
            //msg.data.resize(obses.size()*2);
            for (size_t i = 0; i < obses.size(); ++i)
            {
                msg.data.push_back(obses[i].centre_points.s);
                msg.data.push_back(obses[i].centre_points.l);
            }
            pub_control_obses->publish(msg);
        }

        void SendHmiObs(std::vector<Eigen::VectorXd> &obses){
            std_msgs::msg::Float64MultiArray obs_msg;
            if (obses.size()>0){
                //obs_msg.data.resize(obses.size()*5);
                for (size_t i = 0; i < obses.size(); ++i){
                    obs_msg.data.push_back(obses[i](0));
                    obs_msg.data.push_back(obses[i](1));
                    obs_msg.data.push_back(obses[i](2));
                    obs_msg.data.push_back(obses[i](3));
                    obs_msg.data.push_back(obses[i](4));
                }
                pub_hmi_obses->publish(obs_msg);
            }else{
                pub_hmi_obses->publish(obs_msg);
            }
            
        }
        
        void SendGlobalObses(std::vector<Eigen::VectorXd> &obses){
            std_msgs::msg::Float64MultiArray obs_msg;
            if (obses.size()>0){
                 //obs_msg.data.resize(obses.size()*5);
                for (size_t i = 0; i < obses.size(); ++i){
                    obs_msg.data.push_back(obses[i](0));
                    obs_msg.data.push_back(obses[i](1));
                    obs_msg.data.push_back(obses[i](2));
                    obs_msg.data.push_back(obses[i](3));
                    obs_msg.data.push_back(obses[i](4));
                }
                pub_hmi_obses->publish(obs_msg);
            }else{
                pub_hmi_obses->publish(obs_msg);
            }
            pub_global_obses->publish(obs_msg);
        }

        void gps_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            if(msg->data.size()!=0){
                // // GPS Data
                gpsx = msg->data[0]; 
                gpsy = msg->data[1];
                gpsD = msg->data[2];
                gpsS = msg->data[3];
                //double x_a = msg->data[6];
                double y_a = msg->data[7];
                gpsA_ = y_a;
                car_.resize(5,1);
                tool::getCarPosition(gpsx, gpsy, gpsD, gpsS, car_);
                //car_(5) = gpsA;
            }
            else{car_.resize(1,1);}//没有接受到北斗的消息 
        }

        void lidar_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            /**获取激光雷达传递过来的信息*/  //min_x min_y max_x  max_y thea 
            Eigen::VectorXd r;
            if (msg->data.size()==0) {
                obs_lidar.setOnes(5,1);
                obs_lidar*=1000;
            }
            else{
                Eigen::MatrixXd obs_lidar_;
                int cols =msg->data.size() / 5;
                obs_lidar_.resize(5,cols);
                Eigen::Map<Eigen::MatrixXd> lidar(msg->data.data(),5,cols);  //雷达坐标系 
                obs_lidar_ = lidar;
                //查找在范围内的障碍物 
                car.resize(car_.rows(),car_.cols());
                car = car_;
                if(car.size()==0||car.size()==1||(globalPath.array() != 0.0).any() == 0){return;}//北斗没有消息 没有全局路径信息 
                else{
                    Eigen::MatrixXd T_obs_lidar(obs_lidar_.rows(),obs_lidar_.cols());// = Eigen::MatrixXd::Zero(obs_lidar_.rows(),obs_lidar_.cols());
                    //将雷达坐标系上的点转换到以西门为起点的坐标系上的点  膨胀 
                    double Expansiondistance = 0.2;//10cm *2 一共是二十厘米 
                    // for (size_t i = 0; i < obs_lidar_.cols(); ++i){
                    //    std::cout<<"min_x: "<<obs_lidar_(0, i)<<" "<<"min_y: "<<obs_lidar_(1, i)<<" "
                    //             <<"max_x: "<<obs_lidar_(2, i)<<" "<<"max_y: "<<obs_lidar_(3, i)<<std::endl;
                    // }
                    obs_lidar_.row(0).array() -= Expansiondistance;
                    obs_lidar_.row(1).array() -= Expansiondistance;
                    obs_lidar_.row(2).array() += Expansiondistance;
                    obs_lidar_.row(3).array() += Expansiondistance;
                    // std::cout<<"膨胀之后"<<std::endl;
                    // for (size_t i = 0; i < obs_lidar_.cols(); ++i){
                    //    std::cout<<"min_x: "<<obs_lidar_(0, i)<<" "<<"min_y: "<<obs_lidar_(1, i)<<" "
                    //             <<"max_x: "<<obs_lidar_(2, i)<<" "<<"max_y: "<<obs_lidar_(3, i)<<std::endl;
                    // }
                    double thea = tool::d2r(car(3));
                    double costhea = std::cos(thea); 
                    double sinthea = std::sin(thea);
                    double zhouju = 1.308;
                    double term_x = car(0) + zhouju * costhea; //恢复到车轴中心坐标系下
                    double term_y = car(1) + zhouju * sinthea;
                    T_obs_lidar.row(0) = obs_lidar_.row(0).array() * costhea - obs_lidar_.row(1).array() * sinthea + term_x;
                    T_obs_lidar.row(1) = obs_lidar_.row(0).array() * sinthea + obs_lidar_.row(1).array() * costhea + term_y;
                    T_obs_lidar.row(2) = obs_lidar_.row(2).array() * costhea - obs_lidar_.row(3).array() * sinthea + term_x;
                    T_obs_lidar.row(3) = obs_lidar_.row(2).array() * sinthea + obs_lidar_.row(3).array() * costhea + term_y;
                    T_obs_lidar.row(4) = obs_lidar_.row(4);                    
                    // std::string fileName = "/home/nvidia/v2x6.20/obs/" + std::to_string(obs) + ".txt";
                    // std::remove(fileName.c_str());
                    // std::ofstream outFile;
                    // outFile.open(fileName);
                    // for (size_t i = 0; i < obs_lidar_.cols(); ++i){
                    //     outFile<<obs_lidar_(0,i)<<" "<<obs_lidar_(1,i)<<" "<<obs_lidar_(2,i)<<" "<<obs_lidar_(3,i)<<std::endl;
                    // }
                    // outFile.close(); 
                    // obs=obs+1;  
                    //计算符合范围的障碍物信息               
                    obs::frentPoint FrentPoint_;
                    obs::cartesianToFrenet(car,globalPath,FrentPoint_,obs_car_globalpath_index); //车辆在全局坐标系下的sd 编号 
                    obs::CalculateobsesSD(FrentPoint_,globalPath,T_obs_lidar,obses_limit_SD,LidarcoordinatesystemObsesLimit,obs_lidar_,
                                            GlobalcoordinatesystemObsesLimit,obs_car_globalpath_index);
                    SendHmiObs(LidarcoordinatesystemObsesLimit);
                    SendControlObs(obses_limit_SD);
                    SendGlobalObses(GlobalcoordinatesystemObsesLimit);
                }
            }
        }
        //获取局部路径
        void GetLocalPath(){
            //先判断 //北斗消息
            // car.resize(car_.rows(),car_.cols());
            // car = car_;
            car.resize(car_.rows(),car_.cols());
            car = car_;
            if (car.size() == 0 || car.size() == 1) {
                return;
            } 
            if ((globalPath.array() != 0.0).any() == 0) {
                std::cout << "Waiting global traj generates... " << std::endl;
            } 
            if (!run_stop_flag) {
                    return;
            } else {
                if(in_flag == 0){
                    std::cout << "global traj has been generated" << std::endl;
                    in_flag = true;
                }
                if((obs_lidar.array() != 0.0).any() == 0){
                    obs_lidar.setOnes(5,1);
                    obs_lidar*=1000;
                    std::cout << "LiDAR node can't start, Danger!!" << std::endl;
                }
               
                //开机第一次获取局部路径 
                if(first_run){
                    heading_time_ = Time();
                    local_dp_qp LOCAL_;
                    double gpsA = gpsA_;
                    //1 为找到局部路径 0为未找到 
                    tool::frentPoint FrentPoint_;
                    int first_run_index = 0;
                    tool::cartesianToFrenet(car , globalPath , FrentPoint_ , first_run_index); 
                    index = first_run_index; ///car index
                    double deltaYAW = tool::normalizeAngle(tool::d2r(car(3)) - globalPath(3,first_run_index));
                    double dl =(1 - globalPath(4, first_run_index) * FrentPoint_.d) * tan(deltaYAW);
                    double ptr_kappa = globalPath(4, first_run_index) / (1 - globalPath(4, first_run_index) * FrentPoint_.d);
                    ddl = Caldll(FrentPoint_.d, dl, globalPath(5, first_run_index), globalPath(4, first_run_index), deltaYAW, ptr_kappa);
                    //第一次运行时，只考虑直行  不考虑避障操作 
                    cartofrenet(car,globalPath, index, FrentPoint_);
                    //CalStartCarD(FrentPoint_.d, -1.5, start_l, end_l);
                    delta_l = 0.5; target_v = 10;
                    start_l = -1.5; end_l = -1.5;
                    Decisionflags_.DriveStraightLineFlag = true;
                    LOCAL_.setPatam(gpsA, car(2),FrentPoint_.s,FrentPoint_.d,dl,ddl,globalPath,30,10,index,obses_limit_SD,GlobalcoordinatesystemObsesLimit,
                                    start_l,end_l,delta_l,target_v, 1.5, Decisionflags_,0,true);//最后一位时最近障碍物的位置 
                    none=LOCAL_.GetoptTrajxy(lastOptTrajxy, lastOptTrajsd);
                    if (none){//找到路径再进行之后的操作 确保初始时找到局部路径
                        first_run = false;
                        optTrajsd.clear();
                        optTrajxy.resize(lastOptTrajxy.rows(), lastOptTrajxy.cols());
                        optTrajxy = lastOptTrajxy;
                        optTrajsd = lastOptTrajsd;
                        lastOptTrajsd.clear();
                        timer_local_callback_to_control();
                        //timer_local_callback_to_hmi();
                    } 
                    std::cout<<"first run"<<std::endl; 
                }
                else{
                    //后续的运行
                    heading_time_ = Time(); 
                    std::vector<obses_sd> onlylocalpath; //局部路径规划时使用的障碍物信息 
                    std::vector<Eigen::VectorXd> GlobalcoordinatesystemObsesLimitinlocal;
                    onlylocalpath = obses_limit_SD; 
                    GlobalcoordinatesystemObsesLimitinlocal = GlobalcoordinatesystemObsesLimit;
                    double gpsA = gpsA_;
                    auto start = std::chrono::high_resolution_clock::now();
                    tool::frentPoint FrentPoint_;
                    findClosestPoint(car(0),car(1),globalPath,index);//寻找此时车辆在全局路径的索引 

                    cartofrenet(car,globalPath,index,FrentPoint_);

                    size_t end_index = std::min(index + 120, static_cast<int>(globalPath.cols()));//30m的距离 
                    bool closeroute = Approachingintersection(index,end_index);//判断是否接近路口   

                    //计算最近障碍物 右侧车道中的障碍物 
                    double obsmins,obslength;
                    CalObsMInS(obsmins,globalPath(6,index),obslength,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal);

                    //计算需不需要直接重新规划路径 
                    if(Decisionflags_.ObstacleAvoidanceFlag && obsmins == 1e16){//正在超车 但是右侧车道中无障碍物了
                        Numbercycles = 100;
                    }else if(obsmins != 1e16 && !Decisionflags_.ObstacleAvoidanceFlag){//右侧车道中出现障碍物 在右侧行使时 右侧出现了障碍物 此时需要立刻进行轨迹规划 
                        Numbercycles = 100;
                    }
                    local_dp_qp LOCAL_;
                    //距离车辆最近的索引 
                    local::findClosestPoint(car, optTrajxy, closestIndex);
                    double ey = CalEy(closestIndex);

                    //计算dp的总距离和和单个的距离
                    double DpAllDistance,DpSingleDistance;
                    CalDpLength(DpAllDistance,DpSingleDistance,index);

                    if(DpAllDistance<30){CarCloseTerminalFlag = true;}
                    //阈值判断 决定 起始点 
                    
                    // double deltaYAW=tool::normalizeAngle(tool::d2r(car(3)) - globalPath(3,index));
                    // double dl = (1 - globalPath(4, index) * FrentPoint_.d) * tan(deltaYAW);
                    /******减速过程目前还是存在问题的 1.5 ～ -1.5 寻路这个是不科学的******/
                  
                    //远离终点 车辆远离终点进行的操作 
                    if(!CarCloseTerminalFlag){
                        //首先判断上一次的路径有没有和当前的障碍物进行碰撞    不论正常行驶 还是正在进行避障，都要首先进行上一次路径的碰撞检测 
                        if (ReplanVehiclevertices){                                             
                            if(all_local_pointss.size()!=0){all_local_pointss.clear();}//重新计算时 才会清空 
                            Eigen::MatrixXd car_Fpoint;
                            all_local_pointss.reserve(optTrajxy.cols());
                            for (size_t i = 0; i < optTrajxy.cols(); ++i){
                                obs::get_car_fourpoint(vehicle_length_,vehicle_width_,optTrajxy.col(i),car_Fpoint);//由车辆的中心点 计算局部路径上的每个店对应的车辆的四个顶点
                                all_local_pointss.emplace_back(car_Fpoint);
                            } 
                        }
                        //write();
                        //之前规划的路径没有碰撞或着没有时间超时 //路径点与障碍物有没有碰撞 只有当有碰撞时，且对象车道无障碍物时，才进行借道超车  //没有碰撞 
                        if(obs::HasOverlap(all_local_pointss,GlobalcoordinatesystemObsesLimitinlocal,optTrajxy) == false &&
                                                                                Numbercycles * 0.1 <= threshold_){
                            Numbercycles += 1;
                            ReplanVehiclevertices = false;//如果没有碰撞 或者时间没有超时 不进行车辆顶点的重新计算 
                            return;
                        }                        
                        else{
                            Eigen::VectorXd vehicle_state_(6);
                            vehicle_state_ << car(0), car(1),car(2),car(3),car(4), gpsA;
                            std::cout<<"carx: "<<car(0)<<std::endl;
                            std::cout<<"cary: "<<car(1)<<std::endl;

                            std::cout<<"FrentPoint_.S: "<<FrentPoint_.s<<std::endl;
                            std::cout<<"FrentPoint_.D: "<<FrentPoint_.d<<std::endl;
                            std::cout<<"closestIndex: "<<closestIndex<<std::endl;
                            std::cout<<"index: "<<index<<std::endl;

                            std::array<double, 6> vehicle_state = Decidestartsl(FrentPoint_,closestIndex,closeroute,index,optTrajxy,vehicle_state_,
                                                                                Repeatpreviouspathflag);
                            local_start_s = vehicle_state[0];
                            local_start_l = vehicle_state[1];
                            dl = vehicle_state[2]; 
                            ddl = vehicle_state[3];
                            car(2) = vehicle_state[4];
                            gpsA = vehicle_state[5];
                            std::cout<<"local_start_s: "<<local_start_s<<std::endl;
                            std::cout<<"local_start_l: "<<local_start_l<<std::endl;
                            std::cout<<"dl: "<<dl<<std::endl;
                            std::cout<<"ddl: "<<ddl<<std::endl;
                            std::cout<<"v: "<<car(2)<<std::endl;
                            std::cout<<"a: "<<gpsA<<std::endl;
                            std::cout<<"Trajectory_Splicing_Flag: "<<Trajectory_Splicing_Flag<<std::endl;
                            std::cout<<"Repeatpreviouspathflag: "<<Repeatpreviouspathflag<<std::endl;
                            Slowdowntimethreshold = 100;
                            Repeatpreviouspathflag = false ;
                            //减速过程 
                            if(Decisionflags_.DecelerateFlag && !CarCloseTerminalFlag){ //减速过程 并且不接近终点 这是因为前面有障碍物阻挡停车的
                                Slowdowntimethreshold = 4000;
                                //减速之前处在直线行使，这是因为当前车道无法通行 并且无法借到超车
                                if (Decisionflags_.DriveStraightLineFlag) {
                                    double target_l;
                                    if (!closeroute) {
                                        start_l = -1.0; end_l = -2.0;
                                        delta_l = 0.5; target_v = 5; target_l = -1.5;
                                    } else {
                                        start_l = -1.0; end_l = -1.0;
                                        delta_l = 0.5; target_v = 5; target_l = -1.0;
                                    }
                                    LOCAL_.setPatam(gpsA, car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,DpAllDistance,DpAllDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_, 0, false);
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                    if(none == 1 && obsmins == 1e16){ //找到路径 不使用此次路径 下次进行规划 直线行使状态下 
                                        Decisionflags_.DecelerateFlag = false;
                                        Numbercycles = 100;
                                        ReplanVehiclevertices = true;
                                        return ;
                                    } 
                                     //判断能不能借道超车 
                                    if (!closeroute) {
                                        start_l = 1.5; end_l = 1.5;
                                        delta_l = 0.5; target_v = 10;
                                        target_l = 1.5;
                                    } else {
                                        start_l = 1.0; end_l = 1.0;
                                        delta_l = 0.5; target_v = 5;
                                        target_l = 1.0;
                                    } 
                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,DpAllDistance,DpAllDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_, 0, false);
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                    if (none == 1) { //可以借到超车 
                                        Decisionflags_.DecelerateFlag = false;
                                        Numbercycles = 100;
                                        ReplanVehiclevertices = true;
                                        return ;
                                    } else { //既不能直线行使也不能超车 
                                        if (!closeroute) {
                                            start_l = -1.5; end_l = -1.5;
                                            delta_l = 0.5; target_v = 0;
                                            target_l = -1.5;
                                        } else {
                                            start_l = -1.0; end_l = -1.0;
                                            delta_l = 0.5; target_v = 0;
                                            target_l = -1.0;
                                        } 
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,20,20,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                        if (none == 0) {
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_, 0, false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            if (none == 0){
                                                Pathplanningduringdeceleration(GlobalcoordinatesystemObsesLimitinlocal); //减速规划 
                                                DecelerationPathRelease(optTrajxy); 
                                                return ;
                                            }
                                        } 
                                    }
                                } else if (Decisionflags_.Overtakinginlaneflag) {//车道中超车状态下  这个应该不会执行 
                                    start_l = -1.0; end_l = -2.0;
                                    delta_l = 0.5; target_v = 7;
                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,DpAllDistance,DpAllDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,-1.5,Decisionflags_, 0, false);
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                    if (none == 1) {
                                        Decisionflags_.DecelerateFlag = false;
                                        Numbercycles = 100;
                                        ReplanVehiclevertices = true;
                                        return ;
                                    }
                                } else if (Decisionflags_.ObstacleAvoidanceFlag || 
                                            Decisionflags_.righttoleftlane) { //借道超车状态下的减速停车
                                    double target_l;
                                    if (obsmins == 1e16) { //右侧车道此时无障碍物
                                        Decisionflags_.DecelerateFlag = false;
                                        Numbercycles = 100;
                                        ReplanVehiclevertices = true;
                                        return;
                                    } else if (obsmins != 1e16) {
                                        if (!closeroute) {
                                            start_l = 1.5; end_l = 1.5;
                                            delta_l = 0.5; target_v = 5;
                                            target_l = 1.5;
                                        } else {
                                            start_l = 1.0; end_l = 1.0;
                                            delta_l = 0.5; target_v = 5;
                                            target_l = 1.0;
                                        } 
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,DpAllDistance,DpAllDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l, target_v, target_l, Decisionflags_, 0, false);
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                        if (none == 1){ //可以继续超车 
                                            Decisionflags_.DecelerateFlag = false;
                                            Numbercycles = 100;
                                            ReplanVehiclevertices = true;
                                            return ;
                                        } else {  // 中间避让车辆 
                                            start_l = 0; end_l = 0.5;
                                            target_l = 0.0;
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_, 0, false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            if (none == 0) {
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_, 0, false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                if (none == 0) {
                                                    Pathplanningduringdeceleration(GlobalcoordinatesystemObsesLimitinlocal);
                                                    DecelerationPathRelease(optTrajxy);
                                                    return ; 
                                                }
                                            }
                                        }
                                    }
                                }
                                else{ //依旧没有路
                                    Pathplanningduringdeceleration(GlobalcoordinatesystemObsesLimitinlocal);
                                    DecelerationPathRelease(optTrajxy);
                                    Decisionflags_.DecelerateFlag = true;
                                    return ; 
                                    // for (size_t i = 0; i < optTrajxy.cols(); i++)
                                    // {
                                    //     std::cout<<"s: "<<optTrajxy(5, i)<<" v: "<<optTrajxy(2, i)<<" a: "<<optTrajxy(6, i)<<std::endl;
                                    // }
                                    //timer_local_callback_to_hmi();
                                    std::cout<<"减速"<<std::endl;                                    
                                }
                                if (none){//找到路径再进行之后的操作 确保初始时找到局部路径
                                    optTrajsd.clear();
                                    optTrajxy.resize(lastOptTrajxy.rows(), lastOptTrajxy.cols());
                                    optTrajxy = lastOptTrajxy;
                                    optTrajsd = lastOptTrajsd;
                                    lastOptTrajsd.clear();
                                    timer_local_callback_to_control();
                                } 
                                return ;
                            }
                            //上一次路径正在避障操作 或者从右边的车道返回到左边车道中 借道超车的动作 
                            if(Decisionflags_.ObstacleAvoidanceFlag || Decisionflags_.righttoleftlane){
                                double target_l;
                                //首先判断是否能回到右侧车道行使 
                                if (!closeroute) {
                                    start_l = -1.5; end_l = -1.5;
                                    delta_l = 0.5; target_v = 8;
                                    target_l = -1.5;
 
                                } else {
                                    start_l = -1.0; end_l = -1.0;
                                    delta_l = 0.5; target_v = 5; 
                                    target_l = -1.0;
                                }
                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l, Decisionflags_,0,false);
                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                if(obsmins == 1e16 && none == 1){//右边车道中无障碍物且要计算返回右侧车道的线路不会发生碰撞  这个是解决多个障碍物联排的场景 
                                    //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                    Decisionflags_.ObstacleAvoidanceFlag = false;
                                    Decisionflags_.DecelerateFlag = false;
                                    Decisionflags_.DriveStraightLineFlag = false;
                                    Decisionflags_.righttoleftlane = true;
                                    Decisionflags_.Overtakinginlaneflag = false;
                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd); 
                                    if(none == 0){//返回失败 //30m寻路失败 
                                        //20m
                                        target_v = 0;
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                        if(none == 0){//15m
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,15,15,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            if(none == 0){//在右侧寻路 15m 20m均失败路线  继续在左侧超车行使 
                                                if (!closeroute) {
                                                    start_l = 1.5; end_l = 1.5;
                                                    delta_l = 0.5; target_v = 8;
                                                    target_l = 1.5;
                
                                                } else {
                                                    start_l = 1.0; end_l = 1.0;
                                                    delta_l = 0.5; target_v = 5; 
                                                    target_l = 1.0;
                                                }
                                                //CalStartCarD(FrentPoint_.d,1.5,start_l,end_l);
                                                Decisionflags_.ObstacleAvoidanceFlag =true;Decisionflags_.DecelerateFlag =false;
                                                Decisionflags_ .DriveStraightLineFlag=false;Decisionflags_.righttoleftlane=false;
                                                Decisionflags_.Overtakinginlaneflag=false;
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                    globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                    start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy, lastOptTrajsd);
                                                if(none == 0){ //左侧寻路还是 全部的路径都没堵死 左侧回到右侧时停车 
                                                    Decisionflags_.DecelerateFlag  = true;
                                                    Decisionflags_.righttoleftlane = true;
                                                    size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                    double deceleration = - car(2) / T;
                                                    for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                        if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                            continue;
                                                        } else {
                                                            double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                            double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                            if(v_pow < 0){
                                                                optTrajxy(2, i) = 0;
                                                                optTrajxy(6, i) = 0;
                                                            } else {
                                                                optTrajxy(2, i) = std::sqrt(v_pow);
                                                                optTrajxy(6, i) = deceleration;
                                                            }
                                                        }
                                                    }
                                                    DecelerationPathRelease(optTrajxy);
                                                    return ;                                                                                                            
                                                }
                                            }
                                        }
                                    }
                                    if(FrentPoint_.d <= -0.5){//此时车辆已经在右侧车道中 
                                        Decisionflags_.ObstacleAvoidanceFlag =false;Decisionflags_.DecelerateFlag =false;
                                        Decisionflags_ .DriveStraightLineFlag=true;Decisionflags_.righttoleftlane=false;
                                        Decisionflags_.Overtakinginlaneflag=false;
                                    }
                                } else {//继续超车 
                                    //CalStartCarD(FrentPoint_.d,1.5,start_l,end_l);
                                    double target_l ;
                                    if (!closeroute) {
                                        start_l = 1.5; end_l = 1.5;
                                        delta_l = 0.5; target_v = 8;
                                        target_l = 1.5;
                                    } else {
                                        start_l = 1.0; end_l = 1.0;
                                        delta_l = 0.5; target_v = 5;
                                        target_l = 1.0;
                                    }
                                    Decisionflags_.ObstacleAvoidanceFlag = true;Decisionflags_.DecelerateFlag = false;
                                    Decisionflags_ .DriveStraightLineFlag = false;Decisionflags_.righttoleftlane = false;
                                    Decisionflags_.Overtakinginlaneflag = false;
                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                    if(none==0){ //超车路径发生碰撞  先向右侧寻路30m   向右侧车道寻路 20m远 10m 不能占用左侧车道 
                                        if (!closeroute) {
                                            start_l = -1.5; end_l = -1.5;
                                            delta_l = 0.5; target_v = 8;
                                            target_l = -1.5;
                                        } else {
                                            start_l = -1.0; end_l = -1.0;
                                            delta_l = 0.5; target_v = 5;
                                            target_l = -1.0;
                                        }
                                        Decisionflags_.ObstacleAvoidanceFlag =false;Decisionflags_.DecelerateFlag =false;
                                        Decisionflags_ .DriveStraightLineFlag=false;Decisionflags_.righttoleftlane=true;
                                        //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//向右侧30m寻路
                                        if(none==0){
                                            Decisionflags_.ObstacleAvoidanceFlag = true; Decisionflags_.DecelerateFlag = true;
                                            Decisionflags_.righttoleftlane = false;
                                            //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                            target_v = 0;
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            if(none == 0){//15m远
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,15,15,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                if (none == 0 && local_start_l >= -0.5){ //考虑中间行使
                                                    start_l = 0; end_l = -0.5;
                                                    delta_l = 0.5; target_v = 5;
                                                    target_l = 0.0;
                                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,15,15,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                    if(none == 0){ //寻路失败
                                                        if (!closeroute) {
                                                            start_l = -1.5; end_l = -1.5;
                                                            delta_l = 0.5; target_v = 0;
                                                            target_l = -1.5;
                                                        } else {
                                                            start_l = -1.0; end_l = -1.0;
                                                            delta_l = 0.5; target_v = 0;
                                                            target_l = -1.0;
                                                        }
                                                        if(obsmins == 1e16){ //右侧暂时无障碍物 
                                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                            if(none == 0){
                                                                Decisionflags_.ObstacleAvoidanceFlag = true;
                                                                Decisionflags_.DecelerateFlag = true;//超车时 减速停车 并且向右侧车道寻路无果
                                                                size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                                double deceleration = - car(2) / T;
                                                                for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                                    if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                                        continue;
                                                                    } else {
                                                                        double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                                        double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                                        if(v_pow < 0){
                                                                            optTrajxy(2, i) = 0;
                                                                            optTrajxy(6, i) = 0;
                                                                        } else {
                                                                            optTrajxy(2, i) = std::sqrt(v_pow);
                                                                            optTrajxy(6, i) = deceleration;
                                                                        }
                                                                    }
                                                                }
                                                                DecelerationPathRelease(optTrajxy);
                                                                return ;      
                                                            }
                                                        } else { //右侧暂时有障碍物 
                                                            double safety_distance = 3.574 + obslength / 2 + 2;
                                                            if(obsmins - globalPath(5, index) > safety_distance){
                                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                                globalPath,static_cast<int>(safety_distance),static_cast<int>(safety_distance),
                                                                            index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                                start_l,end_l,delta_l,target_v,target_l,Decisionflags_,0,false);
                                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                                if(none==0){
                                                                    Decisionflags_.ObstacleAvoidanceFlag = true;
                                                                    Decisionflags_.DecelerateFlag = true;//超车时 减速停车 并且向右侧车道寻路无果
                                                                    size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                                    double deceleration = - car(2) / T;
                                                                    for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                                        if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                                            continue;
                                                                        } else {
                                                                            double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                                            double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                                            if(v_pow < 0){
                                                                                optTrajxy(2, i) = 0;
                                                                                optTrajxy(6, i) = 0;
                                                                            } else {
                                                                                optTrajxy(2, i) = std::sqrt(v_pow);
                                                                                optTrajxy(6, i) = deceleration;
                                                                            }
                                                                        }
                                                                    }
                                                                    DecelerationPathRelease(optTrajxy);
                                                                    return ;      
                                                                }
                                                            } else {
                                                                Decisionflags_.ObstacleAvoidanceFlag = true;
                                                                Decisionflags_.DecelerateFlag = true;//超车时 减速停车 并且向右侧车道寻路无果
                                                                size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                                double deceleration = - car(2) / T;
                                                                for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                                    if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                                        continue;
                                                                    } else {
                                                                        double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                                        double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                                        if(v_pow < 0){
                                                                            optTrajxy(2, i) = 0;
                                                                            optTrajxy(6, i) = 0;
                                                                        } else {
                                                                            optTrajxy(2, i) = std::sqrt(v_pow);
                                                                            optTrajxy(6, i) = deceleration;
                                                                        }
                                                                    }
                                                                }
                                                                DecelerationPathRelease(optTrajxy);
                                                                return ;      
                                                            }
                                                        }
                                                    }
                                                }                                               
                                            }
                                        }
                                    }
                                    std::cout<<"正在超车"<<std::endl; 
                                }
                                //Numbercycles=1e16;
                            } else {
                                // 上一次路径不在避障 或者 避障已经完成 回到右侧车道中 
                                //判断前方有无障碍物 40m -0.5 ~ -2 右侧车道 
                                if(obsmins == 1e16){
                                    double targetl;
                                    if(closeroute){
                                        //CalStartCarD(FrentPoint_.d,-1.0,start_l,end_l);
                                        start_l = -1.0; end_l = -1.0;
                                        targetl = -1; 
                                        delta_l =0.5; target_v = 5;
                                    }else{
                                        //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                        start_l = -1.5; end_l = -1.5;
                                        targetl = -1.5; 
                                        delta_l =0.5; target_v = 10;
                                    }
                                    //当前车道上在范围内没有障碍物
                                    Decisionflags_.ObstacleAvoidanceFlag =false;
                                    Decisionflags_.DecelerateFlag =false;
                                    Decisionflags_.DriveStraightLineFlag=true;//按照原车道进行行驶
                                    Decisionflags_.righttoleftlane=false;
                                    Decisionflags_.Overtakinginlaneflag=false;
                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                    globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                    start_l,end_l,delta_l,target_v,targetl,Decisionflags_,0,false);//里面进行了碰撞检测 外面无需再进行了 
                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                    if(none == 0){//未寻找到路径 右侧直线车道中有碰撞 直接左侧车道超车
                                        Decisionflags_.ObstacleAvoidanceFlag =true;
                                        Decisionflags_.DecelerateFlag =false;
                                        Decisionflags_.DriveStraightLineFlag=false;//按照原车道进行行驶
                                        Decisionflags_.righttoleftlane=false;
                                        Decisionflags_.Overtakinginlaneflag=false;
                                        //CalStartCarD(FrentPoint_.d,1.5,start_l,end_l);
                                        start_l = 1.5; end_l = 1.5;
                                        delta_l =0.5;target_v = 10;
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                    globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                    start_l,end_l,delta_l,target_v,1.5,Decisionflags_,0,false);//里面进行了碰撞检测 外面无需再进行了 
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                        if(none==0){ //借道超车时 有碰撞
                                            //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                            start_l = -1.5; end_l = -1.5;
                                            delta_l =0.5; target_v = 0;
                                            Decisionflags_.ObstacleAvoidanceFlag =false;
                                            Decisionflags_.DecelerateFlag =true;
                                            Decisionflags_.DriveStraightLineFlag=true;//
                                            Decisionflags_.righttoleftlane=false;
                                            Decisionflags_.Overtakinginlaneflag=false;
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                    globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                    start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//20m
                                            if(none==0){
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                    globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                    start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//10m
                                                if(none==0){//直接停车 
                                                    size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                    double deceleration = - car(2) / T;
                                                    for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                        if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                            continue;
                                                        } else {
                                                            double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                            double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                            if(v_pow < 0){
                                                                optTrajxy(2, i) = 0;
                                                                optTrajxy(6, i) = 0;
                                                            } else {
                                                                optTrajxy(2, i) = std::sqrt(v_pow);
                                                                optTrajxy(6, i) = deceleration;
                                                            }
                                                        }
                                                    }
                                                    DecelerationPathRelease(optTrajxy);
                                                    return ;      
                                                }
                                            }
                                        }
                                    }
                                    //要不要确保当前生存的路径中不存在碰撞 这样会有一定的耗时操作 
                                    duration.zero();
                                    last_stop_time = default_time;                                   
                                    //std::cout<<"当前车道无障碍，正在直线行使"<<std::endl; 
                                } else { //车道中有障碍物 
                                    //首先判断是否满足下面情况 
                                    bool LANE_CHANGE_DECIDER=true;//借道超车的标志  
                                    //closeroute=false;
                                    if(!closeroute){//不在路口 
                                        intersectionsovertakingflag=false;//路口超车标志 
                                        duration.zero();//累加时间为0
                                        last_stop_time = default_time;//时间至为空 
                                        //1. 先尝试车道内偏移
                                        start_l = -1;  end_l = -2.0; 
                                        delta_l = 0.5; target_v = 7;
                                        Decisionflags_.ObstacleAvoidanceFlag =false;
                                        Decisionflags_.DecelerateFlag =false;
                                        Decisionflags_.DriveStraightLineFlag=false;//按照原车道进行行驶
                                        Decisionflags_.righttoleftlane=false;
                                        Decisionflags_.Overtakinginlaneflag=true;
                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                        std::cout<<"当前车道有障碍，远离路口，正在车道内超车 "<<std::endl; 
                                        if(none == 0){//车道内超车失败 
                                            //CalStartCarD(FrentPoint_.d,1.5,start_l,end_l);
                                            start_l = 1.5; end_l = 1.5;
                                            delta_l = 0.5; target_v = 10;
                                            Decisionflags_.ObstacleAvoidanceFlag =true;
                                            Decisionflags_.DecelerateFlag =false;
                                            Decisionflags_.DriveStraightLineFlag=false;
                                            Decisionflags_.righttoleftlane=false;
                                            Decisionflags_.Overtakinginlaneflag=false;
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l, end_l, delta_l,target_v,1.5,Decisionflags_,0,false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            std::cout<<"当前车道有障碍，远离路口，正在借道超车 "<<std::endl; 
                                            if(none==0){//借到超车也失败 道路全被堵死 直线行使时 借道超车 
                                                CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                                                delta_l = 0.5; target_v = 0;
                                                Decisionflags_.ObstacleAvoidanceFlag =false;
                                                Decisionflags_.DecelerateFlag =true;
                                                Decisionflags_.DriveStraightLineFlag=true;//
                                                Decisionflags_.righttoleftlane=false;
                                                Decisionflags_.Overtakinginlaneflag=false;
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//20m
                                                if(none==0){
                                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//10m    
                                                    if(none==0){//直接停车 
                                                        size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                        double deceleration = - car(2) / T;
                                                        for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                            if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                                continue;
                                                            } else {
                                                                double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                                double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                                if(v_pow < 0){
                                                                    optTrajxy(2, i) = 0;
                                                                    optTrajxy(6, i) = 0;
                                                                } else {
                                                                    optTrajxy(2, i) = std::sqrt(v_pow);
                                                                    optTrajxy(6, i) = deceleration;
                                                                }
                                                            }
                                                        }
                                                        DecelerationPathRelease(optTrajxy);
                                                        return ;      
                                                    }
                                                }
                                            }   
                                        }
                                    } else { //障碍物在路口附近在路口附近  路口也会偏移                                        
                                            start_l = -0.5;end_l = -1.5;
                                            delta_l = 0.5;target_v = 5;
                                            Decisionflags_.ObstacleAvoidanceFlag =false;
                                            Decisionflags_.DecelerateFlag =false;
                                            Decisionflags_.DriveStraightLineFlag=false;//按照原车道进行行驶
                                            Decisionflags_.righttoleftlane=false;
                                            Decisionflags_.Overtakinginlaneflag=true;
                                            LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                        globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                        start_l,end_l,delta_l,target_v,-1,Decisionflags_,obsmins,false);
                                            none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                            std::cout<<"路口车道内偏移"<<std::endl;                               
                                            if(none==0){//车道内偏移失败 有碰撞 
                                                //CalStartCarD(FrentPoint_.d,1.0,start_l,end_l);//超车
                                                start_l = 1.0; end_l = 1.0;
                                                delta_l =0.5;target_v = 5;
                                                Decisionflags_.ObstacleAvoidanceFlag =true;
                                                Decisionflags_.DecelerateFlag =false;
                                                Decisionflags_.DriveStraightLineFlag=false;//按照原车道进行行驶
                                                Decisionflags_.righttoleftlane=false;
                                                Decisionflags_.Overtakinginlaneflag=false;
                                                LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,DpAllDistance,DpSingleDistance,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,1.5,Decisionflags_,0,false);
                                                none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                                                std::cout<<"路口借道超车"<<std::endl; 
                                                if(none==0){//借道超车，会发生碰撞 速度还是0
                                                    //CalStartCarD(FrentPoint_.d,-1.0,start_l,end_l);
                                                    start_l = -1.0; end_l = -1.0;
                                                    delta_l =0.5;target_v = 0;
                                                    Decisionflags_.ObstacleAvoidanceFlag =false;
                                                    Decisionflags_.DecelerateFlag =true;
                                                    Decisionflags_.DriveStraightLineFlag=true;//
                                                    Decisionflags_.righttoleftlane=false;
                                                    Decisionflags_.Overtakinginlaneflag=false;
                                                    LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,20,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,-1.0,Decisionflags_,0,false);
                                                    none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//20m
                                                    if(none==0){
                                                        LOCAL_.setPatam(gpsA,car(2),local_start_s,local_start_l,dl,ddl,
                                                            globalPath,10,10,index,onlylocalpath,GlobalcoordinatesystemObsesLimitinlocal,
                                                            start_l,end_l,delta_l,target_v,-1.0,Decisionflags_,0,false);
                                                        none = LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);//10m
                                                        if(none==0){//直接停车 
                                                            size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                                            double deceleration = - car(2) / T;
                                                            for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                                                if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                                                    continue;
                                                                } else {
                                                                    double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                                                    double v_pow =  2 * deceleration * x + car(2) * car(2);
                                                                    if(v_pow < 0){
                                                                        optTrajxy(2, i) = 0;
                                                                        optTrajxy(6, i) = 0;
                                                                    } else {
                                                                        optTrajxy(2, i) = std::sqrt(v_pow);
                                                                        optTrajxy(6, i) = deceleration;
                                                                    }
                                                                }
                                                            }
                                                            DecelerationPathRelease(optTrajxy);
                                                            return ;      
                                                        }
                                                    }
                                                }
                                            }                                                                                                                     
                                    }                                                                                                                                                          
                                }
                            }
                        }
                        if(Decisionflags_.DecelerateFlag){
                            pubstopline(obsmins-globalPath(6,index));
                        }else{
                            pubstopline(obsmins);
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> duration = end - start;
                        std::cout << "程序运行时间: " << duration.count() << " 秒" << std::endl;
                       // Numbercycles =Numbercycles+1;
                        Numbercycles = 0;//计时归零 
                        ReplanVehiclevertices=true;//进行车辆顶点的重新计算 
                    } else { //接近终点 
                        //local_dp_qp LOCAL_;
                        //计算dp的总距离和和单个的距离
                        //double DpAllDistance,DpSingleDistance;
                        //车辆距离终点距离小于 30
                        //CalDpLength(DpAllDistance,DpSingleDistance,index);
                        //double deltaYAW=tool::normalizeAngle(tool::d2r(car(3)) - globalPath(3,index));
                        //double dl =0;
                        if(DpAllDistance < 10){ //小于10m之后 就不进行路径个更新了 
                            DecelerationPathRelease(optTrajxy);
                            return ;
                        }
                        //CalStartCarD(FrentPoint_.d,-1.5,start_l,end_l);
                        start_l = -0.5; end_l = -1.5;
                        delta_l = 0.5; target_v = 0;
                        Decisionflags_.ObstacleAvoidanceFlag =false;
                        Decisionflags_.DecelerateFlag =true;
                        Decisionflags_.DriveStraightLineFlag=false;//按照原车道进行行驶
                        Decisionflags_.righttoleftlane=false;
                        Decisionflags_.Overtakinginlaneflag=false;
                        LOCAL_.setPatam(gpsA, car(2),FrentPoint_.s,FrentPoint_.d,dl,ddl,globalPath,DpAllDistance,DpAllDistance,index,onlylocalpath,
                                GlobalcoordinatesystemObsesLimitinlocal,start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                        none=LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                        if(none == 0 ){
                            int safetydistance ;
                            if(DpAllDistance > 20){
                                safetydistance = 20;
                                LOCAL_.setPatam(gpsA, car(2),FrentPoint_.s,FrentPoint_.d,dl,ddl,globalPath,safetydistance,safetydistance,index,onlylocalpath,
                                GlobalcoordinatesystemObsesLimitinlocal,start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                none=LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                            } else if (10 < DpAllDistance && DpAllDistance <= 20){
                                safetydistance = 10;
                                LOCAL_.setPatam(gpsA, car(2),FrentPoint_.s,FrentPoint_.d,dl,ddl,globalPath,safetydistance,safetydistance,index,onlylocalpath,
                                GlobalcoordinatesystemObsesLimitinlocal,start_l,end_l,delta_l,target_v,-1.5,Decisionflags_,0,false);
                                none=LOCAL_.GetoptTrajxy(lastOptTrajxy,lastOptTrajsd);
                            } else {
                                size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                                double deceleration = - car(2) / T;
                                for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                    if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                        continue;
                                    } else {
                                        double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                        double v_pow =  2 * deceleration * x + car(2) * car(2);
                                        if(v_pow < 0){
                                            optTrajxy(2, i) = 0;
                                            optTrajxy(6, i) = 0;
                                        } else {
                                            optTrajxy(2, i) = std::sqrt(v_pow);
                                            optTrajxy(6, i) = deceleration;
                                        }
                                    }
                                }
                                DecelerationPathRelease(optTrajxy);
                                return ; 
                            }
                            if (none == 0){
                                double deceleration = - car(2) / T;
                                for(size_t i = 0; i < optTrajxy.cols(); ++i){
                                    if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                        continue;
                                    } else {
                                        double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                        double v_pow =  2 * deceleration * x + car(2) * car(2);
                                        if(v_pow < 0){
                                            optTrajxy(2, i) = 0;
                                            optTrajxy(6, i) = 0;
                                        } else {
                                            optTrajxy(2, i) = std::sqrt(v_pow);
                                            optTrajxy(6, i) = deceleration;
                                        }
                                    }
                                }
                                DecelerationPathRelease(optTrajxy);
                                return ; 
                            }
                        }
                    }
                    //找到路径再进行之后的操作 确保初始时找到局部路径
                    if (none == 1){ 
                        optTrajsd.clear();
                        optTrajxy.resize(lastOptTrajxy.rows(), lastOptTrajxy.cols());
                        optTrajsd.resize(lastOptTrajsd.size());
                        // std::cout<<"lastOptTrajxy: "<<std::endl;
                        // std::cout<<lastOptTrajxy.transpose()<<std::endl;
                        optTrajxy = lastOptTrajxy;
                        optTrajsd = lastOptTrajsd;
                        lastOptTrajsd.clear();
                        //write(GlobalcoordinatesystemObsesLimitinlocal, optTrajxy);
                    }
                }
                timer_local_callback_to_control();
               
                // for (size_t i = 0; i < optTrajxy.cols(); ++i){
                //     std::cout<<"s: "<<optTrajxy(5,i)<<" v: "<<std::round(optTrajxy(2,i)*3.6)<<" a: "<<optTrajxy(6,i)<<
                //     " "<<"t: "<<optTrajxy(7,i)<<
                //     std::endl;
                // }

                // write
                // static int loopCount =1;
                // std::string fileName = "/home/mm/V2xAvoidingObstacles/local/" + std::to_string(loopCount) + ".txt";
                // std::ofstream outFile;
                // outFile.open(fileName);
                // for (size_t i = 0; i < lastOptTrajxy.cols(); ++i){
                //     outFile<<optTrajxy(0,i)<<" "<<optTrajxy(1,i)<<" "<<optTrajxy(2,i)<<std::endl;
                // }
                // outFile.close(); 
                // loopCount=loopCount+1;          
            }
        }

        // 收到请求的处理函数
        void handle_response(const std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces::Request> request, std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces::Response> response) {
            if(request->global_request > 0){
                response->local_response  = 1;
            }
        }
       
        void global_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            if(msg->data.size() != 0) {      
                int cols = msg->data.back();
                msg->data.pop_back();
                globalPath.resize(7, cols);
                Eigen::Map<Eigen::MatrixXd> globalPathReshaped(msg->data.data(), 7, cols);
                globalPath= globalPathReshaped;
                //std::cout << "Local Node global path: " << std::endl;
                //std::cout << globalPath.transpose() << std::endl;
                for (size_t i = 0; i < globalPath.cols(); ++i){
                    outputFile<<globalPath(4,i)<<std::endl;
                }
                outputFile.close();
            }else{
                std::cout << "Local Node global path is none!!! " << std::endl;
            }
        }
        
        void cam_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg){
            // std::cout << "msg->data.size:" << msg->data.size() << std::endl;
            /************************障碍物信息获取与处理*************************/
            Eigen::VectorXd r;
            int cols = 0;
            if(msg->data.size() == 0){//无可识别障碍物
                cols = 1;
                obs_cam.setOnes(5, cols);
                obs_cam*=100;
                r.setOnes(cols);
                obs_cam.row(4) = r.array() * r0;
            }else{ //可识别障碍物
                cols = msg->data.size()/2;
                r.setOnes(cols);
                obs_cam.setZero(5, cols);
                Eigen::Map<Eigen::MatrixXd> obs_cam_pos(msg->data.data(), 2, cols);
                obs_cam.row(0) = -obs_cam_pos.row(0);//
                obs_cam.row(1) = obs_cam_pos.row(1);
                obs_cam.row(4) = r.array() * r0;
            }        
        }

        void timer_local_callback_to_control(){  
            /***********Only To Control Node*************/
            std_msgs::msg::Float64MultiArray local_trajs_msg;
            //检查矩阵optTrajxy是否所有元素都等于零。如果所有元素都等于零，整个表达式将返回true；否则返回false
            if((optTrajxy.array() != 0.0).any() == 0 ){
                local_trajs_msg.data.push_back(-1);
                local_to_control_publisher->publish(local_trajs_msg);
                local_to_hmi_publisher->publish(local_trajs_msg);
            } else {           
                if (!Trajectory_Splicing_Flag) {//不进行轨迹拼接
                    for (size_t i = 0; i < optTrajxy.cols(); ++i){
                        optTrajxy(8, i) = optTrajxy(7, i) + heading_time_ + 0.1;
                    }
                } else {
                    // double error_s = std::abs(stitching_trajectory(5, 0)); //最大的s差值 
                    // double start_time = stitching_trajectory(8, stitching_trajectory.cols() - 1); //起始的绝对时间 
                    // double relative_time = std::abs(stitching_trajectory(7, 0));  // 相对时间的最大差值 
                    // Eigen::VectorXd stitching_trajectory_last_vector =
                    //         stitching_trajectory.block(0, stitching_trajectory.cols() -1, stitching_trajectory.rows(), 1);//拼接的最后一列 
                    // stitching_trajectory.conservativeResize(Eigen::NoChange, stitching_trajectory.cols() -1);
                    // Eigen::MatrixXd Temporalmatrix(stitching_trajectory.rows(), stitching_trajectory.cols() + optTrajxy.cols());
                    // Temporalmatrix << stitching_trajectory , optTrajxy;
                    // for (size_t i = 0; i < Temporalmatrix.cols(); ++i){
                    //     Temporalmatrix(5, i) = Temporalmatrix(5, i) + error_s;
                    //     Temporalmatrix(8, i) = Temporalmatrix(7, i) + start_time;
                    //     Temporalmatrix(7, i) = Temporalmatrix(7, i) + relative_time;
                    // }
                    // optTrajxy.resize(Temporalmatrix.rows(), Temporalmatrix.cols());
                    // optTrajxy = Temporalmatrix;
                    // size_t change_col_index = stitching_trajectory.cols();//需要更改的列的编号 
                    // optTrajxy(0, change_col_index) = stitching_trajectory_last_vector(0);
                    // optTrajxy(1, change_col_index) = stitching_trajectory_last_vector(1);
                    // optTrajxy(2, change_col_index) = stitching_trajectory_last_vector(2);
                    // optTrajxy(3, change_col_index) = stitching_trajectory_last_vector(3);
                    // optTrajxy(4, change_col_index) = stitching_trajectory_last_vector(4);
                    // optTrajxy(6, change_col_index) = stitching_trajectory_last_vector(6);
                    for (size_t i = 0; i < optTrajxy.cols(); ++i){
                        optTrajxy(8, i) = optTrajxy(7, i) + heading_time_ + 0.1;
                    }
                    // std::cout<<"Temporalmatrix: "<<std::endl;
                    // std::cout<<Temporalmatrix.transpose()<<std::endl;
                }
                write_localpath(optTrajxy);
                std::vector<double> localTrajReshape(&optTrajxy(0), optTrajxy.data() + optTrajxy.size());
                local_trajs_msg.data = localTrajReshape;
                local_trajs_msg.data.push_back(globalPath.cols());
                local_trajs_msg.data.push_back(heading_time_);
                local_to_control_publisher->publish(local_trajs_msg);
                
                std_msgs::msg::Float64MultiArray local_trajs_msg2;  
                std::vector<double> localTrajReshape2(&optTrajxy(0), optTrajxy.data() + optTrajxy.size());
                local_trajs_msg2.data = localTrajReshape2;
                local_to_hmi_publisher->publish(local_trajs_msg2);                 
            }
        } 

        void timer_local_callback_to_hmi(){  
            /***********Only To HMI*************/
            std_msgs::msg::Float64MultiArray local_trajs_msg;
            if((optTrajxy.array() != 0.0).any() == 0){
                local_trajs_msg.data.push_back(-1);
                local_to_hmi_publisher->publish(local_trajs_msg);
            }else{
                if (!Trajectory_Splicing_Flag) {//不进行轨迹拼接
                    for (size_t i = 0; i < optTrajxy.cols(); ++i){
                        optTrajxy(8, i) = optTrajxy(7, i) + heading_time_ + 0.1;
                    }                    
                } else {
                    // double error_s = std::abs(stitching_trajectory(5, 0));
                    // double start_time = stitching_trajectory(8, stitching_trajectory.cols() - 1);
                    // double relative_time = std::abs(stitching_trajectory(7, 0)); 
                    // //std::cout<<"stitching_trajectory.size: "<<stitching_trajectory.cols()<<std::endl;
                    // stitching_trajectory.conservativeResize(Eigen::NoChange, stitching_trajectory.cols() -1);
                    // Eigen::MatrixXd Temporalmatrix(stitching_trajectory.rows(), stitching_trajectory.cols() + optTrajxy.cols());
                    // Temporalmatrix << stitching_trajectory , optTrajxy;
                    // for (size_t i = 0; i < Temporalmatrix.cols(); ++i){
                    //     Temporalmatrix(5, i) = Temporalmatrix(5, i) + error_s;
                    //     Temporalmatrix(8, i) = Temporalmatrix(8, i) + start_time;
                    //     Temporalmatrix(7, i) = Temporalmatrix(7, i) + relative_time;
                    // }
                    // optTrajxy = Temporalmatrix;
                    for (size_t i = 0; i < optTrajxy.cols(); ++i){
                        optTrajxy(8, i) = optTrajxy(7, i) + heading_time_ + 0.1;
                    } 

                }
                std::vector<double> localTrajReshape(&optTrajxy(0), optTrajxy.data() + optTrajxy.size());
                local_trajs_msg.data = localTrajReshape;
                local_to_hmi_publisher->publish(local_trajs_msg);
            }
        } 

        void findClosestPoint(double x, double y, Eigen::MatrixXd &globalPath, int& carIndex){
            int startIndex = std::max(carIndex - 10,0);
            int endIndex = std::min(carIndex + 120, static_cast<int>(globalPath.cols()));
            double distance,d_min = std::numeric_limits<double>::max();
            for (int i= startIndex; i < endIndex; ++i){
                distance = (std::pow(globalPath(0, i) - x, 2) + std::pow(globalPath(1, i) - y, 2));
                if (distance < d_min) {
                    carIndex = i;
                    d_min = distance;	
                }
            } 
        }
        
        void cartofrenet( Eigen::VectorXd CAR,Eigen::MatrixXd &path,int CAR_DEX, tool::frentPoint &carFrent){
            const double dx = CAR(0) - path(0,CAR_DEX);
            const double dy = CAR(1) - path(1,CAR_DEX);

            const double cos_theta_r = std::cos(path(3,CAR_DEX));
            const double sin_theta_r = std::sin(path(3,CAR_DEX));
            double ref_s = path(6, CAR_DEX);
            double path_s = dx * cos_theta_r + dy * sin_theta_r + ref_s;
            const double cross_rd_nd = cos_theta_r * dy - sin_theta_r * dx;
            carFrent.d = std::copysign(cross_rd_nd, cross_rd_nd);
            carFrent.s = std::abs(path_s);
        }
 
        void CalObsMInS(double &ObsMinS,double car_s,double &obs_length,std::vector<obses_sd>& obses,std::vector<Eigen::VectorXd> &globalobs_in_local){
            size_t obses_size = obses.size();
            ObsMinS = 1e16;
            double obs_s;
            double obs_l;
            size_t mindex = 1e4;
            if(obses_size == 0) return;
            
            for (size_t i = 0; i < obses_size; ++i){
                double min_s = std::min({obses[i].point1.s, obses[i].point2.s, obses[i].point3.s, obses[i].point4.s});
                double Kthreshold = 20; 
                if ((obs_s - min_s) <= Kthreshold){
                    //std::cout<<"obs "<<obs::decide_obs_true_false(obses_limit_SD[i],-0.3,-2.9)<<std::endl;
                    if(obs::decide_obs_true_false(obses[i],-0.5,-2.6) == 1){ //在这个范围内的都是算成障碍物 1.5-0.9-0.3  1.5+0.9+0.3 
                        if(obs_s < ObsMinS){
                            ObsMinS = obs_s;
                            mindex = i;
                        }
                    }
                }
            }
            if(mindex == 1e4){
                obs_length = 0;
            }else{
                double l12 = std::abs(globalobs_in_local[mindex](1) - globalobs_in_local[mindex](3));
                double l14 = std::abs(globalobs_in_local[mindex](0) - globalobs_in_local[mindex](2));
                obs_length = std::max(l12, l14);
            }
            // size_t obses_size = obses_limit_SD.size();
            // static bool last_flag =false;
            // bool flag=false;
            // if (obses_size==0){
            //     ObsMinS=1e16;
            //     LastObsMinS=1e16;
            //     NewObsMinS=1e16;
            //     last_flag=false;
            //     return;
            // }
            // ObsMinS=1e16;
            // double obs_s;
            // double obs_l;
            // //上一帧和当前帧均要满足有满足范围的障碍物 
            // for (size_t i = 0; i < obses_size; ++i){
            //     obs_s = obses_limit_SD[i].centre_points.s;
            //     obs_l = obses_limit_SD[i].centre_points.l;
            //     if ((obs_s - car_s) <= 30){
            //         if(obs::decide_obs_true_false(obses_limit_SD[i],-0.3,-2.9)){ //在这个范围内的都是算成障碍物 1.5-0.9-0.3  1.5+0.9+0.3 
            //             NewObsMinS = std::min(ObsMinS, obs_s);
            //             flag=true;
            //         }
            //     }
            // }
            // if(flag&&last_flag){
            //     if(NewObsMinS-LastObsMinS>0.2){//当前时刻- 上一时刻 >0.2 最近障碍物在远离 
            //         ObsMinS=1e16;
            //     }else{
            //         ObsMinS=NewObsMinS;
            //     }
            // }
            // //存在满足范围的障碍物 
            // if(flag){
            //     last_flag = true;      
            // }else{
            //     last_flag = false;      
            //     LastObsMinS=1e16;
            //     NewObsMinS=1e16;
            // }
            // LastObsMinS = NewObsMinS;
        }

        //判断是否在路口附近 
        bool  Approachingintersection(size_t start_index, size_t end_index){    
            size_t start_index_ = std::max(static_cast<size_t>(0.0), start_index); //5m
            for (size_t i = start_index_; i < end_index; ++i){
                if(std::abs(globalPath(4,i)) >= 0.03){
                    return true;
                }
            }
            return false;      
        }

        void CalObsMInSLeft(double &ObsMinS,double car_s,std::vector<obses_sd>& obses){
            size_t obses_size = obses.size();
            static bool last_flag_left =false;
            bool flag=false;
            if (obses_size==0){
                ObsMinS=1e16;
                LeftLastObsMinS=1e16;
                LeftNewObsMinS=1e16;
                last_flag_left=false;
                return;
            }
            ObsMinS= 1e16 ;
            double obs_s;
            double obs_l;
            //上一帧和当前帧均要满足有满足范围的障碍物 
            for (size_t i = 0; i < obses_size; ++i){
                obs_s = obses[i].centre_points.s;
                obs_l = obses[i].centre_points.l;
                if ((obs_s - car_s) <= 30){
                    if(obs::decide_obs_true_false(obses[i],2.9,0.3)){ //在这个范围内的都是算成障碍物 1.5-0.9-0.3  1.5+0.9+0.3 
                        LeftNewObsMinS = std::min(ObsMinS, obs_s);
                        flag=true;
                    }
                }
            }
            if(flag && last_flag_left){
                if(LeftNewObsMinS - LeftLastObsMinS>0.2){//当前时刻- 上一时刻 >0.2 最近障碍物在远离 
                    ObsMinS=1e16;
                }else{
                    ObsMinS=LeftNewObsMinS;
                }
            }
            //存在满足范围的障碍物 
            if(flag){
                last_flag_left = true;      
            }else{
                last_flag_left = false;      
                LeftLastObsMinS=1e16;
                LeftNewObsMinS=1e16;
            }
            LeftLastObsMinS = LeftNewObsMinS;
        }
        
        //发布减速命令 
        void pubDecelerateFlag(){
            std_msgs::msg::Int32 Flag;
            if (Decisionflags_.DecelerateFlag==false){
                Flag.data=0;
            }else{
                Flag.data=1;
            }
            pub_control_DecelerateFlag->publish(Flag);
        }

        //t发布停止线 
        void pubstopline(double stoplines){
            std_msgs::msg::Float64 msg;
            msg.data=static_cast<float>(stoplines);
            pub_stop_line->publish(msg);
        }

        //计算初始时的 d
        void  CalStartCarD(double origincar_d,double targetl,double &sta_l,double &end){
            if(d_list.size() == 0){
                return ;  // 数组为空，返回-1表示无法找到最近的数
            }
            // 遍历数组，寻找与目标数值最近的元素
            double dmin = std::numeric_limits<double>::max(); 
            double distance;
            size_t closet;
            double dmin_targetl = std::numeric_limits<double>::max(); 
            double distance_targetl;
            size_t closet_targetl;
            for (size_t i = 0; i < d_list.size(); ++i){
                //car
                distance = std::abs(origincar_d - d_list[i]);
                if(distance < dmin){
                    closet = i;
                    dmin = distance;
                }
                //target_l
                distance_targetl = std::abs(targetl - d_list[i]);
                if(distance_targetl < dmin_targetl){
                    closet_targetl = i;
                    dmin_targetl = distance_targetl;
                }
            }
            if(origincar_d <= targetl){
                //车辆位于目标点l的右侧
                //终点
                end = d_list[closet];
                sta_l=d_list[closet_targetl];
                // if(closet_targetl!=0){
                //     sta_l=d_list[closet_targetl-1];//向左扩大一个间隔 
                // }else{
                //     sta_l=d_list[closet_targetl];
                // }
            }else{
                //车辆位于目标点l的左侧
                sta_l = d_list[closet];
                end = d_list[closet_targetl];
                // if(closet_targetl!=d_list.size()-1){
                //     end = d_list[closet_targetl+1];
                // }else{
                //     end = d_list[closet_targetl];
                // }

            }
        }
        
        //横向误差计算 
        double CalEy(int closeindex){
            double deltaX = optTrajxy(0,closeindex)-car(0);
            double deltaY = optTrajxy(1,closeindex)-car(1);
            double thea;
            if (deltaX == 0){
                if (deltaY > 0){thea = M_PI / 2;}
                if (deltaY < 0){thea =- M_PI / 2;}
            }
            else{
                thea = atan2(deltaY,deltaX)-car(3)/180*M_PI;
            }
            double ld =std::sqrt(std::pow(deltaX,2)+std::pow(deltaY,2));
            double ey = ld*sin(thea);//横向的误差
            return ey;
        }

        void CalDpLength(double &DpAllDistance,double &DpSingleDistance, int mindex){
            //车辆距离终点距离大于30
            if(globalPath(6,globalPath.cols()-1)-globalPath(6,mindex) >= 30){
                DpAllDistance = 30;
                DpSingleDistance= 10;
            }
            //车辆距离终点距离小于 30
            if(globalPath(6,globalPath.cols()-1) - globalPath(6,mindex) <30){
                //CarCloseTerminalFlag = true;
                int distance = static_cast<int>(globalPath(6,globalPath.cols()-1)-globalPath(6,mindex));//距离终点的距离 转化为int型 方便处理 
                DpAllDistance = distance;
                DpSingleDistance = distance;
                // if(distance %3 == 0){
                //     DpAllDistance = distance;
                //     DpSingleDistance = distance/3;
                // }
                // else{
                //     DpAllDistance = distance - distance%3;
                //     DpSingleDistance = (distance - distance%3)/3;
                // }
            }

        }

        std::array<double, 6> Decidestartsl(tool::frentPoint &FrentPoint,int position_matched_index,bool flag,
                        int globalcloseindex, Eigen::MatrixXd &localpath, Eigen::VectorXd &vehicle_state,
                        bool decflag){
            double lat_threshold;
            double current_time = Time(); //获取当前的系统时间 
            double planning_cycle_time = 0.1; //路径规划的时间
            int prev_trajectory_size = localpath.cols(); //若是没有轨迹
            if (vehicle_state(2) < 0.27) { //车辆速度较小默认为静止状态  起始状态 或者 人为刹车
                double deltaYAW = tool::normalizeAngle(tool::d2r(car(3)) - globalPath(3,globalcloseindex));
                double vehicle_state_dl = (1 - globalPath(4, globalcloseindex) * FrentPoint.d) * tan(deltaYAW);
                double ptr_kappa = globalPath(4, globalcloseindex) / (1 - globalPath(4, globalcloseindex) * FrentPoint.d);
                double ptr_ddl = Caldll(FrentPoint.d, vehicle_state_dl, globalPath(5, globalcloseindex), globalPath(4, globalcloseindex), deltaYAW, ptr_kappa);
                std::array<double ,6> real_state = {FrentPoint.s, FrentPoint.d, 
                                    vehicle_state_dl, ptr_ddl, vehicle_state(2), vehicle_state(5)};
                Trajectory_Splicing_Flag = false;
                return real_state;  
            }
            if(prev_trajectory_size == 0){
                std::array<double, 6> vehicle_start_point =
                      ComputeReinitStitchingTrajectory(position_matched_index, globalcloseindex,FrentPoint, 
                        vehicle_state,localpath);
                Trajectory_Splicing_Flag = false;
                return vehicle_start_point;
            }
            auto frenet_sd = 
                    ComputePositionProjection(vehicle_state(0), vehicle_state(1),
                        localpath(0, position_matched_index), localpath(1, position_matched_index), 
                        localpath(3, position_matched_index), localpath(5, position_matched_index));
            auto lat_diff = frenet_sd.second;// 横向误差
             //此处是应对转弯时误差较大 车辆乱打方向
            if (flag) {
                FLAGS_replan_lateral_distance_threshold = 1.0;
            } else {
                FLAGS_replan_lateral_distance_threshold = 0.5;
            } 
            if (std::abs(lat_diff) > FLAGS_replan_lateral_distance_threshold) {
                std::array<double, 6> vehicle_start_point =
                      ComputeReinitStitchingTrajectory(position_matched_index, globalcloseindex,FrentPoint, 
                        vehicle_state,localpath );
                Trajectory_Splicing_Flag = false;
                 return vehicle_start_point;
            }
            auto prev_matched_index = std::min(position_matched_index, prev_trajectory_size - 1);
            int carIndex = 0;
            int startIndex = std::max(index - 80,0);
            int endIndex = std::min(index + 80, static_cast<int>(globalPath.cols()));
            double distance,d_min = std::numeric_limits<double>::max();
            double x = localpath(0, prev_matched_index);
            double y = localpath(1, prev_matched_index);
            double dx;
            double dy;
            for (int i = startIndex; i < endIndex; ++i){
                dx = globalPath(0, i) - x;
                dy = globalPath(1, i) - y;
                distance = dx * dx + dy * dy;
                if (distance < d_min) {
                    carIndex = i;
                    d_min = distance;	
                }
            }
            tool::frentPoint stitching_trajectoryFrentPoint;
            Eigen::Vector3d prev_state;
            prev_state << x , y, localpath(3, prev_matched_index);
            cartofrenet(prev_state, globalPath, carIndex, stitching_trajectoryFrentPoint);
            double path_s = stitching_trajectoryFrentPoint.s;
            // if (std::abs(stitching_trajectoryFrentPoint.s - FrentPoint.s) > 1.5) { //纵向距离差别太大了
            //     std::array<double, 6> vehicle_start_point =
            //           ComputeReinitStitchingTrajectory(position_matched_index, globalcloseindex,FrentPoint, 
            //             vehicle_state,localpath );
            //     Trajectory_Splicing_Flag = false;
            //      return vehicle_start_point;
            // }
            double start_point_s; 
            double start_point_l;
            double start_point_dl;
            double start_point_ddl;
            GetsldlBys(optTrajsd, path_s, start_point_s, start_point_l, start_point_dl, start_point_ddl);
            // start_point_l = stitching_trajectoryFrentPoint.d;
            // // std::cout<<"globalPath(3,carIndex): "<<globalPath(3,carIndex)<<std::endl;
            // // std::cout<<"prev_state(2): "<<prev_state(2)<<std::endl;
            // double deltaYAW = tool::normalizeAngle(prev_state(2) - globalPath(3, carIndex));
            // // std::cout<<"stitching_trajectoryFrentPoint.d: "<<stitching_trajectoryFrentPoint.d<<std::endl;
            // // std::cout<<"deltaYAW: "<<deltaYAW<<std::endl;
            // // std::cout<<"tan(deltaYAW: "<<tan(deltaYAW)<<std::endl;
            // double start_point_dl = (1 - globalPath(4, carIndex) * stitching_trajectoryFrentPoint.d) * tan(deltaYAW);
            // std::cout<<localpath.transpose()<<std::endl;
            std::array<double, 6> vehicle_start_point;
            vehicle_start_point = {start_point_s, start_point_l ,start_point_dl, start_point_ddl,
                localpath(2, prev_matched_index), localpath(6, prev_matched_index)};
            Trajectory_Splicing_Flag = true;
            return vehicle_start_point;
        }

        //不能使用轨迹拼接时的情况 
        std::array<double, 6> ComputeReinitStitchingTrajectory (int localcloseindex,
                int globalcloseindex, tool::frentPoint &FrentPoint, Eigen::VectorXd &vehicle_state,
                Eigen::MatrixXd &localpath) {
            //车辆启动 
            //利用运动学向外推0.1s的位置 
            Eigen::Vector3d prev_vehicle_state;
            double prev_time = 0.1;
            double ref_steer = atan2(vehicle_state(4) * localpath(4, localcloseindex), 1);   // 前轮转角 
            double sinthea = std::sin(localpath(3, localcloseindex));   
            double costhea = std::cos(localpath(3, localcloseindex));   
            double param = std::tan(ref_steer)/vehicle_state(4); 
            Eigen::Vector3d   Parametervectors;
            Parametervectors << costhea, sinthea, param;
            Eigen::Vector3d curr_vehicle_state;
            curr_vehicle_state << vehicle_state(0), vehicle_state(1), vehicle_state(3);
            prev_vehicle_state = curr_vehicle_state + (Parametervectors * vehicle_state(2)) * prev_time; //获得新的位置
            //prev_vehicle_state(2) = vehicle_state(3);
            //求取新位置的 s d dl 
            int carIndex = 0;
            int startIndex = std::max(index - 20,0);
            int endIndex = std::min(index + 80, static_cast<int>(globalPath.cols()));
            double distance,d_min = std::numeric_limits<double>::max();
            double x = prev_vehicle_state(0);
            double y = prev_vehicle_state(1);
            double dx, dy;
            for (int i= startIndex; i < endIndex; ++i){
                dx = globalPath(0, i) - x;
                dy = globalPath(1, i) - y;
                distance = dx * dx + dy * dy;
                if (distance < d_min) {
                    carIndex = i;
                    d_min = distance;	
                }
            }
            tool::frentPoint FrentPoint_;
            cartofrenet(prev_vehicle_state, globalPath, carIndex, FrentPoint_);
            double deltaYAW = tool::normalizeAngle(tool::d2r(prev_vehicle_state(2)) - globalPath(3,carIndex));
            double prev_dl = (1 - globalPath(4, carIndex) * FrentPoint_.d) * tan(deltaYAW);
            double ptr_kappa = globalPath(4, carIndex) / (1 - globalPath(4, carIndex) * FrentPoint_.d);
            double prev_ddl = Caldll(FrentPoint_.d, prev_dl, globalPath(5, carIndex), globalPath(4, carIndex), deltaYAW, ptr_kappa);
            std::array<double ,6> real_state = {FrentPoint_.s, FrentPoint_.d, prev_dl, prev_ddl,
                                        vehicle_state(2), vehicle_state(5)};
            return real_state;
            
        }

        double Time(){
            auto now = std::chrono::high_resolution_clock::now();
            auto nano_time_point = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
            auto epoch = nano_time_point.time_since_epoch();
            uint64_t now_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(epoch).count();
            return static_cast<double> (now_nano) / NANOS_PER_SECOND;
        }

        void write_localpath (Eigen::MatrixXd &path) {
            static int loopCount =1;
            std::string fileName = "/home/mm/longshan11_6/local/" + std::to_string(loopCount) + ".txt";
            std::ofstream outFile;
            outFile.open(fileName);
            for(size_t i = 0; i < path.cols(); ++i){
                outFile <<path(0,i)<<" "<<path(1,i)<<" "
                        <<path(2,i)<<" "<<path(3,i)<<" "
                        <<path(4,i)<<" "<<path(5,i)<<" "
                        <<path(6,i)<<" "<<path(7,i)<<std::endl;
            }
            loopCount=loopCount+1;      
        }
        //保存数据
        void write(std::vector<Eigen::VectorXd> &obses, Eigen::MatrixXd &path){
            static int loopCount =1;
            std::string fileName = "/home/mm/longshan9_29/local/" + std::to_string(loopCount) + ".txt";
            std::ofstream outFile;
            outFile.open(fileName);
            if(all_local_pointss.size()!=0){all_local_pointss.clear();}//重新计算时 才会清空 
                Eigen::MatrixXd car_Fpoint;
                all_local_pointss.reserve(path.cols());
                for (size_t i = 0; i < path.cols(); ++i){
                    obs::get_car_fourpoint(vehicle_length_,vehicle_width_, path.col(i),car_Fpoint);//由车辆的中心点 计算局部路径上的每个店对应的车辆的四个顶点
                    all_local_pointss.emplace_back(car_Fpoint);
            } 
            for(const auto &car_Fpoint: all_local_pointss){
                outFile <<car_Fpoint(0,0)<<" "<<car_Fpoint(1,0)<<" "
                        <<car_Fpoint(0,1)<<" "<<car_Fpoint(1,1)<<" "
                        <<car_Fpoint(0,2)<<" "<<car_Fpoint(1,2)<<" "
                        <<car_Fpoint(0,3)<<" "<<car_Fpoint(1,3)<<std::endl;
            }
            outFile.close(); 
            fileName = "/home/nvidia/longshan9_5/local/obs" + std::to_string(loopCount) + ".txt";
            outFile.open(fileName);
            for(const auto &obs: obses){
                outFile <<obs(0)<<" "<<obs(1)<<" "
                        <<obs(0)<<" "<<obs(3)<<" "
                        <<obs(2)<<" "<<obs(3)<<" "
                        <<obs(2)<<" "<<obs(1)<<std::endl;
            }
            outFile.close(); 
            loopCount=loopCount+1;      
        }
        
        //获取与当前路径发生碰撞最近的s值 
        void getclose_s(Eigen::MatrixXd &path, std::vector<Eigen::VectorXd> &obses,
                        double &min_s, bool &ischeck){
            std::vector<Eigen:: MatrixXd> all_local_points;
            Eigen::MatrixXd car_Fpoint;
            size_t path_size = path.cols();
            all_local_points.reserve(path_size);
            //获取车辆的四个顶点的位置 
            for (size_t i = 0; i < path_size; ++i){
                obs::get_car_fourpoint(vehicle_length_, vehicle_width_, path.col(i), car_Fpoint);//由车辆的中心点 计算局部路径上的每个店对应的车辆的四个顶点
                all_local_points.emplace_back(car_Fpoint);
            }
            std::vector<double> s_list;
            //与所有的障碍物进行碰撞检测 获取 s_list
            for(auto &obs_: obses){
                size_t index;
                bool flag = obs::HasOverlap(all_local_points, obs_, path, index);
                if(flag){ //发生了碰撞
                    double s = path(5, std::max(static_cast<int>(index-1), 0)); //碰撞发生时车辆所在位置的s 
                    s_list.push_back(s);
                }
            }
            if(s_list.size() != 0){
                ischeck = true;
                std::sort(s_list.begin(), s_list.end());
                min_s = s_list.front();
            } else {
                ischeck = false;
            }
        }
        
        //求取时间匹配最近点的索引
        size_t QueryLowerBoundPoint(const double veh_rel_time, Eigen::MatrixXd &localpath
            ) const{
            double time_max = std::numeric_limits<double>::max();
            size_t time_index = 0;
            for (size_t i = 0; i < localpath.cols(); ++i){
                double time_distance = std::abs(veh_rel_time - localpath(8, i));
                if(time_distance < time_max){
                    time_max = time_distance;
                    time_index = i;
                }
            }
            return time_index;
        }
        
        std::pair<double, double> ComputePositionProjection(
            const double x, const double y, const double ref_x, const double ref_y
            , const double theta, const double ref_s){
            const double dx = x - ref_x;
            const double dy = y - ref_y;
            const double costheta = std::cos(theta);
            const double sintheta = std::sin(theta);
            std::pair<double, double> frenet_sd;
            frenet_sd.first = dx * costheta + dy * sintheta + ref_s;
            frenet_sd.second = dx * sintheta - dy * costheta;
            return frenet_sd;
        }
        void speed_gears_callback(const std_msgs::msg::Int64MultiArray::SharedPtr msg){                 
            run_stop_flag = (bool)msg->data[2];
        }

        //减速过程中的路径规划 -- 前面条件不满足时 
        void Pathplanningduringdeceleration( std::vector<Eigen::VectorXd> &GlobalcoordinatesystemObsesLimitinlocal_){
            Repeatpreviouspathflag = true;
            //减速过程中依旧需要计算当前减速路径中有没有发生碰撞 以防止新的障碍物出现 而；车辆还在继续行使中  这是在计算之前的路 
            double collision_detection_s;//当前路径发生碰撞时最近的s值 
            bool collision_detection_flag;//是否发生碰撞 
            getclose_s(optTrajxy, GlobalcoordinatesystemObsesLimitinlocal_, collision_detection_s, collision_detection_flag);
            /***************后续考虑******************/
            if(collision_detection_flag){//若当前减速路径中有障碍物 并且知道当前路径在什么位置发生了碰撞 
                double distance_threshold = 10;//碰撞位置阈值为 10m
                double car_collision_detection_distance = std::abs(collision_detection_s - optTrajxy(5, closestIndex));
                if(car_collision_detection_distance > distance_threshold &&
                            collision_detection_s > optTrajxy(5, closestIndex)){ //路径碰撞位置与车辆位置的插值大于阈值 而且碰撞位置要大于车辆在局部路径中的位置 
                    for (size_t i = 0; i < optTrajxy.cols(); ++i){
                        if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){ //车辆当前位置之前的轨迹点 不考虑
                            continue;
                        } else if(optTrajxy(5, i) >= optTrajxy(5, closestIndex) && 
                                (optTrajxy(5, i) - optTrajxy(5, closestIndex)) <= 
                                (car_collision_detection_distance - distance_threshold)){ //在范围内 
                            //以恒定减速度 进行减速 在距离障碍物位置10m远的地方停下来 
                            double a = -(car(2) * car(2)) / (2 * (car_collision_detection_distance - distance_threshold));
                            double x = optTrajxy(5, i) - optTrajxy(5, closestIndex);
                            double v = std::sqrt(std::abs(2 * a * x + std::pow(car(2) , 2))); 
                            optTrajxy(2, i) = v > 0 ? v : 0;
                            optTrajxy(6, i) = a;
                            if(i == optTrajxy.cols() -1){
                                optTrajxy(2, i) = 0;
                                optTrajxy(6, i) = 0;
                            }
                        } else {
                            optTrajxy(2, i) = 0;
                            optTrajxy(6, i) = 0;
                        }
                    }
                } else { //小于设定的阈值 
                    //首先判断车速 小于0.1 默认是停车状态 
                    if(car(2) <= 0.1){
                        for (size_t i = 0; i < optTrajxy.cols(); ++i){
                            optTrajxy(2, i) = 0;
                            optTrajxy(6, i) = 0;
                        }
                    } else {
                        size_t T = 1;//距离较近 规定车辆1秒钟必须停下来
                        double deceleration = - car(2) / T;
                        for(size_t i = 0; i < optTrajxy.cols(); ++i){
                            if(optTrajxy(5, i) < optTrajxy(5, closestIndex)){
                                continue;
                            } else {
                                double x = optTrajxy(5, i) - optTrajxy(5, closestIndex); 
                                double v_pow =  2 * deceleration * x + car(2) * car(2);
                                if(v_pow < 0){
                                    optTrajxy(2, i) = 0;
                                    optTrajxy(6, i) = 0;
                                } else {
                                    optTrajxy(2, i) = std::sqrt(v_pow);
                                    optTrajxy(6, i) = deceleration;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //减速路径的发布
        void DecelerationPathRelease(Eigen::MatrixXd &dec_path){
            for (size_t i = 0; i < dec_path.cols(); ++i){
                dec_path(8, i) = dec_path(7, i) + heading_time_ + 0.1;
            }
            std_msgs::msg::Float64MultiArray local_trajs_msg;
            std::vector<double> localTrajReshape(&dec_path(0), dec_path.data() + dec_path.size());
            local_trajs_msg.data = localTrajReshape;
            local_to_control_publisher->publish(local_trajs_msg);
            write_localpath(dec_path);
            std_msgs::msg::Float64MultiArray local_trajs_msg2;
            std::vector<double> localTrajReshape2(&dec_path(0), dec_path.data() + dec_path.size());
            local_trajs_msg2.data = localTrajReshape2;
            local_to_hmi_publisher->publish(local_trajs_msg2);
        }
    
    private:
        // 声明global服务端
        rclcpp::Service<ros2_path_interfaces::srv::PathInterfaces>::SharedPtr global_path_service_;
        // 声明gps话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr gps_subscribe;
        // 声明global话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr global_path_subscribe;
        // 声明local_trajs话题发布者
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr local_to_hmi_publisher;
        // To control_node Publisher
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr local_to_control_publisher;
        // 声明cam话题订阅者
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_cam;
        //声明LIDAR话题订阅
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub_LiDAR_;
        //发布局部路径中路径点对应的的框
        rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr sub_car_local;
        //在rviz中显示局部路径 
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr pub_rviz_local;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr  pub_hmi_obses;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_control_obses;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_global_obses; //全局坐标系下的障碍物的发布 
        //向控制发布是否在减速 0为未减速 1为减速 
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_control_DecelerateFlag;

        //停止线发布
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_stop_line;

        rclcpp::Subscription<std_msgs::msg::Int64MultiArray>::SharedPtr speed_gears_subscribe;

        // Timer
        rclcpp::TimerBase::SharedPtr timer_to_control;
        rclcpp::TimerBase::SharedPtr timer_to_hmi;
        rclcpp::TimerBase::SharedPtr timer_getlocalpath;
        rclcpp::TimerBase::SharedPtr timer_DecelerateFlag;
        rclcpp::TimerBase::SharedPtr timer_stop_line;



                
        Eigen::VectorXd car;
        Eigen::VectorXd car_;

        Eigen::MatrixXd globalPath;
        Eigen::MatrixXd optTrajxy;//上周期局部路径
        Eigen::MatrixXd lastOptTrajxy;//本周期局部路径
        std::vector<Eigen::Vector4d> lastOptTrajsd;//本周期局部路径
        std::vector<Eigen::Vector4d> optTrajsd;//上周期局部路径

        Eigen::MatrixXd pubOptTrajxy;//本周期局部路径
        Eigen::MatrixXd obs_cam;
        Eigen::MatrixXd obs_lidar;
        tool::controlParams cps;
        tool::frentPoint carFrentPoint;
        int closestIndex = 10000;

        double gpsx = 0;
        double gpsy = 0;
        double gpsD = 0;
        double gpsS = 0;
        double gpsA_ = 0;

        int none = 1;//是否找到合适的局部路径 
        bool fre = false;// 是否输出localtrajFrenetsd

        int  index = -1;//最近点下标 car ditance global 
        bool in_flag = false; //文本提示输出的标志位

        double r0 = 0.3;

        bool first_run = true;
        int pre_point = 0;  //向前两个点 

        // std::string fileName = "path1.txt";
        // std::ofstream ofs;  //创建输入流对象 

        //规划拼接需要的参数
        double Replanning_threshold = 1.5;//自车和投影点距离的阈值
        double distance_threshold = 0.5;//设定起点为离投影点50cm的地方作为规划的起点、
        double T = 0.1;//向前的时间 
        std::string filename = "outputglobal.txt";
        //std::string filename = "obs.txt";
        std::ofstream outputFile;

        // std::string filename_index = "outputxy_index.txt";
        // std::ofstream outputFile_index;

        /**************Calobs***************/
        std::vector<obses_sd> obses_limit_SD; //在范围内的SD
        std::vector<Eigen::VectorXd> LidarcoordinatesystemObsesLimit;//障碍物的xy 在范围内的雷达坐标系下的障碍物                  
        std::vector<Eigen::VectorXd> GlobalcoordinatesystemObsesLimit;

        //车辆参数 
        const double vehicle_length_ = 4.532;
        const double vehicle_width_ = 1.814;
        bool CarCloseTerminalFlag=false;//车辆距离终点较近信号 


        bool ReplanVehiclevertices =true;//重新局部路径中车辆的四个顶点的位置，不需要重复计算了 
        std::vector<Eigen::MatrixXd> all_local_pointss;

        // 局部路径更改的时间 
        int Numbercycles=0;
        double total_duration_;
        double threshold_=1.5;

        /**************obs*********/
        int obs_car_globalpath_index = 0;//计算障碍物时，车辆在全局路径的编号 

        //避障的标志符
        Decisionflags Decisionflags_;
        // bool ObstacleAvoidanceFlag = false;  //街道超车的标志true为正在避障， false 直线行驶 
        // bool DecelerateFlag = false;//减速停车标志 
        // bool DriveStraightLineFlag =true;//直线行使标志  
        // bool Overtakinginlaneflag =false;//车道内超车的标志 
        // bool righttoleftlane =false;//超车完成 返回原车道的标志
        double start_l;double end_l;double delta_l;        //l方向的采样
        double target_v;        //目标速度


        //获取在路口时 车速为0时的停车时间 
        std::chrono::duration<double> duration ;
        std::chrono::high_resolution_clock::time_point stop_time;
        std::chrono::high_resolution_clock::time_point last_stop_time;
        // 创建一个默认初始化的 time_point 对象
        std::chrono::high_resolution_clock::time_point default_time;

        double Waittime=5;//等待时间 
        bool intersectionsovertakingflag =false;//路口超车标志 

        //障碍物判断 
        double NewObsMinS  = 1e16;//当前
        double LastObsMinS = 1e16;//上一次 

        double LeftNewObsMinS  = 1e16;//当前
        double LeftLastObsMinS = 1e16;//上一次 

        int obs =1;

        /***********/
        std::array<double,10>d_list{2.0,1.5,1.0,0.5,0,-0.5,-1,-1.5,-2,-2.5};
        double heading_time_ ;

        /********轨迹拼接*********/
        double FLAGS_replan_lateral_distance_threshold = 0.5;
        double FLAGS_replan_longitudinal_distance_threshold= 2.5;
        bool Trajectory_Splicing_Flag;//轨迹拼接标志 
        Eigen::MatrixXd stitching_trajectory;

        double local_start_s;
        double local_start_l;
        double dl;
        double ddl;

        bool run_stop_flag = false; //启动停止标志位

        int Slowdowntimethreshold = 100;

        bool Repeatpreviouspathflag = false ;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<local_trajs_node>("local_node");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}