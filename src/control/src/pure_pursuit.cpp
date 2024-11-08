                                                                                                                                                                                                               #include"pure_pursuit.h"


pure_pursuit::pure_pursuit()
{
    car.resize(5,1);
}

pure_pursuit::~pure_pursuit()
{
}

void pure_pursuit::setld(double distance){
    ld=distance;
}
void pure_pursuit::getPreviewpoint(Eigen::VectorXd car_,Eigen::MatrixXd &optTrajxy,int closestIndex){
    car = std::move(car_);
    double sum_distance;
    for (int i = closestIndex+1; i < optTrajxy.cols(); ++i)
    {
        if(i>=optTrajxy.cols()-1){
            Preview_point=optTrajxy.cols()-1;
            break;
        }
        //计算距离
        //double ditance = std::sqrt(std::pow(optTrajxy(0,i)-car(0),2)+std::pow(optTrajxy(1,i)-car(1),2));
        double sum_distance = std::sqrt(std::pow(optTrajxy(0,i)-optTrajxy(0,i-1),2)+std::pow(optTrajxy(1,i)-optTrajxy(1,i-1),2));
        if (sum_distance>=ld)
        {
            Preview_point = i;
            break;
        }
    }
}
double pure_pursuit::getThea(Eigen::MatrixXd &optTrajxy){
    double deltaX = optTrajxy(0,Preview_point)-car(0);
    double deltaY = optTrajxy(1,Preview_point)-car(1);
    double thea;
    if (deltaX==0)
    {
        if (deltaY>0){thea=M_PI/2;}
        if (deltaY<0){thea=-M_PI/2;}
    }
    else{
        thea = atan2(deltaY,deltaX)-car(3)/180*M_PI;
    }
   // std::sqrt(std::pow(deltaX,2)+std::pow(deltaY,2));
    double Thea = 2*L*sin(thea)/ld;
    return -std::atan(Thea);
}