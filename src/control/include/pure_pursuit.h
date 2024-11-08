#include <fstream>
#include<iostream>
#include <Eigen/Eigen>
#include<Eigen/Dense>
#include"toolKits.h"
using namespace std;



class pure_pursuit
{
private:
    double ld=2;//前视距离
    int Preview_point;
    double L =2.67;//轴距
    Eigen::VectorXd car;//车辆信息 

public:
    pure_pursuit();
    ~pure_pursuit();
    void getPreviewpoint(Eigen::VectorXd car_,Eigen::MatrixXd &optTrajxy,int closestIndex);
    void setld(double distance);
    double getThea(Eigen::MatrixXd &optTrajxy);
};



    




