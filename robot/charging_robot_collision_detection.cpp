#include"charging_robot_collision_detection.h"

bool CollisionDetection(vector<vector<double>> &global_path, vector<double> &robot_message,  vector<vector<double>>&obstacle){
    if (obstacle.empty()) {
        return false;
    }
    if (global_path.empty() || robot_message.empty()) {
        std::cout<<"碰撞检测模块输入错误"<<std::endl;
        return false;
    }
    size_t index = FindClosePoint(global_path, robot_message);
    size_t startindex, endindex;
    DetermineStarteAndEndIndex(startindex, endindex, index, global_path);
    //计算需要碰撞的路径点 具体机器人的包围框的大小
    std::vector<std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>,
         std::pair<double, double>, double>> all_robot_four_points;
    all_robot_four_points = GetFourPoints(startindex, endindex, global_path);
    for (size_t i = 0; i < all_robot_four_points.size(); ++i) {
        for (size_t j = 0; j <  obstacle.size(); j++) {
            if (HasOverlap(all_robot_four_points[i], obstacle[j])) {
                return true;
            }
            
        }
    }
    return false;
}

size_t FindClosePoint(vector<vector<double>> &global_path, vector<double> &robot_message){
    size_t end = global_path.size();
    double mindistance = std::numeric_limits<double>::max();
    double x_diff, y_diff, distance;
    double x = robot_message[0];
    double y = robot_message[1];
    size_t mindex = 0;
    for (size_t i = 0; i < end; ++i) {
        x_diff = x - global_path[i][0];
        y_diff = y - global_path[i][1];
        distance = x_diff * x_diff + y_diff * y_diff;
        if (distance < mindistance) {
            mindistance = distance;
            mindex = i;
        }
    }
    return mindex;
}


void DetermineStarteAndEndIndex(size_t &startindex, size_t &endindex, size_t index, vector<vector<double>> &global_path) {
    if (index == global_path.size() - 1) {
        startindex = index;
        endindex = index;
        return;
    }
    startindex = index;
    size_t globalsize = global_path.size();
    double current_length;
    double x_diff, y_diff;
    for (size_t i = index; i < globalsize - 1; ++i) {
        x_diff = global_path[i+1][0] - global_path[i][0];
        y_diff = global_path[i+1][1] - global_path[i][1];
        double length = std::sqrt(x_diff * x_diff + y_diff * y_diff);
        current_length += length;
        endindex = i + 1;
        if (current_length >= collision_detection_length) {
            break;
        }
    }
}

std::vector<std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>,
    std::pair<double, double>, double>>GetFourPoints(size_t &startindex, size_t &endindex, vector<vector<double>> &global_path) {
        /*
            2-------3
            |       |
            1-------4
			车子的四个顶点 
        */
       std::pair<double, double> onepoint;
       std::pair<double, double> twopoint;
       std::pair<double, double> threepoint;
       std::pair<double, double> fourpoint;
       std::pair<double, double> centerpoint;
       double length = 0.5; //车轮后轴到车体中心的距离
       double half_robot_length = robot_length / 2;
       double half_robot_wigth = robot_wigth / 2;
        std::vector<std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>,
            std::pair<double, double>, double>> FourPoints;
        for (size_t i = startindex; i < endindex; i++){
            double theta = global_path[i][2];
            double cos_thea = cos(theta);
            double sin_thea = sin(theta); 
            double x = global_path[i][0];
            double y = global_path[i][1];
            double term0 = x + length * cos_thea;
            double term1 = y + length * sin_thea;//恢复到车体的中心 
            //1
            onepoint.first  = (-half_robot_length)*cos_thea - (-half_robot_wigth)*sin_thea+term0;
            onepoint.second = (-half_robot_length)*sin_thea + (-half_robot_wigth)*cos_thea+term1;

            //2
            twopoint.first  = (-half_robot_length)*cos_thea - (half_robot_wigth)*sin_thea+term0;
            twopoint.second = (-half_robot_length)*sin_thea + (half_robot_wigth)*cos_thea+term1;

            //3
            threepoint.first  = (half_robot_length)*cos_thea - (half_robot_wigth)*sin_thea+term0;
            threepoint.second = (half_robot_length)*sin_thea + (half_robot_wigth)*cos_thea+term1;

            //4
            fourpoint.first  = (half_robot_length)*cos_thea - (-half_robot_wigth)*sin_thea+term0;
            fourpoint.second = (half_robot_length)*sin_thea + (-half_robot_wigth)*cos_thea+term1;

            centerpoint.first = term0;
            centerpoint.second = term1;
            FourPoints.emplace_back(std::make_tuple(onepoint, twopoint, threepoint, fourpoint, centerpoint, theta));
        }	
}

//每一个点与所有障碍物进行比较 这样如果有碰撞 速度会加快 
bool HasOverlap(std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, 
    std::pair<double, double>, double> &robot_point, std::vector<double> &obs) {
    
    double car_x_min,car_y_min,car_x_max,car_y_max,car_centre_x,car_centre_y,car_half_length,car_half_width;
    car_half_length = robot_length / 2 ; car_half_width = robot_wigth / 2;
    double obs_x_min,obs_y_min,obs_x_max,obs_y_max,obs_centre_x,obs_centre_y,obs_half_length,obs_half_width;    
    //计算车辆的相关信息 最大x y 最小 x y 中心点坐标 
    auto &p0 = std::get<0>(robot_point);
    auto &p1 = std::get<1>(robot_point);
    auto &p2 = std::get<2>(robot_point);
    auto &p3 = std::get<3>(robot_point);
    double theta = std::get<5>(robot_point);
    car_x_min = std::min({p0.first, p1.first, p2.first, p3.first});
    car_y_min = std::min({p0.second, p1.second, p2.second, p3.second});
    car_x_max = std::max({p0.first, p1.first, p2.first, p3.first});
    car_y_max = std::max({p0.second, p1.second, p2.second, p3.second});
    car_centre_x = std::get<4>(robot_point).first;
    car_centre_y = std::get<4>(robot_point).second;
    double cos_heading_ = std::cos(theta);    
    double sin_heading_ = std::sin(theta);
    
    double obs_1_x = obs[0];
    double obs_1_y = obs[1];

    double obs_2_x = obs[0];
    double obs_2_y = obs[3];

    double obs_3_x = obs[2];
    double obs_3_y = obs[3];

    double obs_4_x = obs[2];
    double obs_4_y = obs[1];

    obs_x_min = std::min({obs_1_x,obs_2_x,obs_3_x,obs_4_x});
    obs_y_min = std::min({obs_1_y,obs_2_y,obs_3_y,obs_4_y});
    obs_x_max = std::max({obs_1_x,obs_2_x,obs_3_x,obs_4_x});
    obs_y_max = std::max({obs_1_y,obs_2_y,obs_3_y,obs_4_y});
    obs_centre_x = (obs_1_x+obs_2_x+obs_3_x+obs_4_x)/4;
    obs_centre_y = (obs_1_y+obs_2_y+obs_3_y+obs_4_y)/4;
    obs_half_length = std::abs(obs_4_x-obs_1_x)/2;
    obs_half_width  = std::abs(obs_2_y-obs_1_y)/2;
    double obs_cos_heading = std::cos(0);
    double obs_sin_heading = std::sin(0);
    if (obs_x_max < car_x_min || obs_x_min > car_x_max ||
        obs_y_max < car_y_min || obs_y_min > car_y_max){
        return false;
    }else{
        const double shift_x = obs_centre_x - car_centre_x;
        const double shift_y = obs_centre_y - car_centre_y;
        const double dx1 = cos_heading_ * car_half_length;
        const double dy1 = sin_heading_ * car_half_length;
        const double dx2 = sin_heading_ * car_half_width;
        const double dy2 = -cos_heading_ * car_half_width;

        const double dx3 = obs_cos_heading * obs_half_length;
        const double dy3 = obs_sin_heading * obs_half_length;
        const double dx4 = obs_sin_heading * obs_half_width;
        const double dy4 = -obs_cos_heading* obs_half_width;

        //f3
        if(std::abs(shift_x * cos_heading_ + shift_y * sin_heading_) <=
                    std::abs(dx3 * cos_heading_ + dy3 * sin_heading_) +
                        std::abs(dx4 * cos_heading_ + dy4 * sin_heading_) +
                        car_half_length &&
        //f4
                std::abs(shift_x * sin_heading_ - shift_y * cos_heading_) <=
                    std::abs(dx3 * sin_heading_ - dy3 * cos_heading_) +
                        std::abs(dx4 * sin_heading_ - dy4 * cos_heading_) +
                        car_half_width &&
        //f5
                std::abs(shift_x * obs_cos_heading + shift_y * obs_sin_heading) <=
                    std::abs(dx1 *obs_cos_heading + dy1 * obs_sin_heading) +
                        std::abs(dx2 * obs_cos_heading + dy2 * obs_sin_heading) +
                        obs_half_length &&
        //f6
                std::abs(shift_x * obs_sin_heading - shift_y * obs_cos_heading) <=
                    std::abs(dx1 * obs_sin_heading - dy1 * obs_cos_heading) +
                        std::abs(dx2 * obs_sin_heading - dy2 * obs_cos_heading) +
                        obs_half_width){
            return true;
        }else{
            return false;
        }
    }
    return false;
}