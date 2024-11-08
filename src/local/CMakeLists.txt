cmake_minimum_required(VERSION 3.5)
project(local)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(visualization_msgs REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(./include)
find_package(ros2_path_interfaces REQUIRED)
find_package(OpenMP REQUIRED)
find_package(osqp REQUIRED)
find_package(yaml-cpp REQUIRED)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
include_directories(${osqp_INCLUDE_DIRS})
include_directories(${YAML_CPP_INCLUDE_DIR})

# add_library(Calobs ./src/Calobs.cpp)
# target_compile_options(Calobs PRIVATE ${OpenMP_CXX_FLAGS})
# target_link_libraries(Calobs PRIVATE OpenMP::OpenMP_CXX)

aux_source_directory(./src SRC_LIST)
list(APPEND SRC_LIST ./src/local_dp_qp.cpp)
list(APPEND SRC_LIST ./src/QP.cpp)
list(APPEND SRC_LIST ./src/piecewise_jerk_problem.cpp)
list(APPEND SRC_LIST ./src/Speeddecisions.cpp)
list(APPEND SRC_LIST ./src/piecewise_jerk_speed_optimizer.cpp)




# add_executable(path_planning_pub ${SRC_LIST})
add_executable(local_node3 ${SRC_LIST})

target_include_directories(local_node3 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(local_node3 ${OpenCV_LIBS})
target_link_libraries(local_node3  osqp::osqp)
target_link_libraries(local_node3 yaml-cpp)

if(OpenMP_CXX_FOUND)

  target_compile_options(local_node3  PRIVATE ${OpenMP_CXX_FLAGS})
  target_link_libraries(local_node3  ${OpenMP_CXX_LIBRARIES})

endif()

ament_target_dependencies(local_node3 rclcpp std_msgs ros2_path_interfaces visualization_msgs)

install(TARGETS
local_node3
DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
