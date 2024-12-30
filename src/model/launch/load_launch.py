import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # 获取 URDF 文件路径，使用 ROS 2 的包路径机制
    package_name = 'model'  # 这是您包的名称
    urdf_file_path = os.path.join(get_package_share_directory(package_name), 'car_model', 'default.urdf')

    # 读取 URDF 文件内容
    with open(urdf_file_path, 'r') as urdf_file:
        urdf_content = urdf_file.read()

    # 创建 launch 描述
    return LaunchDescription([
        # Declare the argument for the URDF file
        DeclareLaunchArgument('urdf_file', default_value=urdf_content, description='URDF file content for the robot'),

        # Launch the robot_state_publisher node
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': urdf_content}],
        ),
    ])
