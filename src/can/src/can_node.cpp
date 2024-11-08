#include"can/socketcan.h"
#include <chrono>
#include <memory>
#include<ctime>
#include "rclcpp/rclcpp.hpp"
#include"std_msgs/msg/int64_multi_array.hpp"
#include <csignal>
#include"std_msgs/msg/float32_multi_array.hpp"
#include<thread>
using namespace std;
using std::placeholders::_1;


class can_node:public rclcpp::Node
{
private:
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr sub;
    socketcan* socketcan_ = nullptr;
    bool flag = false;
    bool exit_socketcan = true;
public:
    can_node(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "%s start!", name.c_str());
        sub=this->create_subscription<std_msgs::msg::Float32MultiArray>("/control_pub",1,std::bind(&can_node::callback, this, _1));
        socketcan_ =new  socketcan();

    };
    void callback(std_msgs::msg::Float32MultiArray::SharedPtr msg)
    {
        if(static_cast<int>(msg->data[4])==0)
        {
            if (flag==true)
            {
                if (exit_socketcan)
                {
                    std::cout<<"can_node exit"<<std::endl;
                    socketcan_->exit_socketcan();
                    std::cout<<"can_node 0"<<std::endl; 
                    delete socketcan_;
                    exit_socketcan = false;
                    //socketcan_=nullptr;
                }
            }
        }
        else
        {
            if (socketcan_!=nullptr)
            {
                flag=true;
                int speed = static_cast<int>(msg->data[0]);
                int sw_angle = static_cast<int>((msg->data[2]));
                int brake = static_cast<int>(msg->data[3]);
                unsigned char gear ;
                if (static_cast<int>(msg->data[1])==0)
                {
                    gear = 0xB;
                }
                if (static_cast<int>(msg->data[1])==1)
                {
                    gear = 0xA;
                }
                if (static_cast<int>(msg->data[1])==2)
                {
                    gear = 0x1;
                }
                if (static_cast<int>(msg->data[1])==3)
                {
                    gear = 0x9;
                }
                socketcan_->meeeage_all(brake,sw_angle,gear,speed);
             }
            //socketcan_->message_0x20(brake,sw_angle);
            //sleep(0.0001);
            //socketcan_->message_0x1c5(gear,speed);
        }
        // int speed = int(msg->data[0]);
        // int sw_angle = int((msg->data[2]));
        // int brake = int(msg->data[3]);
        // unsigned char gear ;
        // if ((msg->data[1])==0)
        // {
        //     gear = 0xB;
        // }
        // if ((msg->data[1])==1)
        // {
        //     gear = 0xA;
        // }
        // if ((msg->data[1])==2)
        // {
        //     gear = 0x1;
        // }
        // if ((msg->data[1])==3)
        // {
        //     gear = 0x9;
        // }
        // socketcan_->meeeage_all(brake,sw_angle,gear,speed);
        
        
    };
    ~can_node( ){
        socketcan_->exit_socketcan(); 
        delete socketcan_;
    };
};
int main(int argc, char  **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<can_node>("socketcan");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
