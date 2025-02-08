#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
#include <tuple>
#include <algorithm> 
using namespace std;


double robot_length = 2.5;
double robot_wigth = 1.0;
double collision_detection_length = 2.5; //全局路径中碰撞检测的长度 

/*
    @param global_path 全局路径信息 x y theta 
    @param robot_message 机器人自身信息 x y theta 
    @param obstacle 障碍物信息  min_x min_y max_x max_y 
*/
bool CollisionDetection(vector<vector<double>> &global_path, vector<double> &robot_message, vector<vector<double>>&obstacle);

size_t FindClosePoint(vector<vector<double>> &global_path, vector<double> &robot_message);
void DetermineStarteAndEndIndex(size_t &startindex, size_t &endindex, size_t index, vector<vector<double>> &global_path);

std::vector<std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>,
    std::pair<double, double>, double>>GetFourPoints(size_t &startindex, size_t &endindex, vector<vector<double>> &global_path);

bool HasOverlap(std::tuple<std::pair<double, double>, std::pair<double, double>, std::pair<double, double>, std::pair<double, double>,
       std::pair<double, double>, double> &robot_point, std::vector<double> &obs);