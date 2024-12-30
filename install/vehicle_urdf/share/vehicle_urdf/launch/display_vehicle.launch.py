from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 发布 URDF 模型
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': open('/home/mm/longshan12_2/src/vehicle_urdf/urdf/vehicle.urdf', 'r').read()}]
        ),
        # 启动 Rviz
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen'
        ),
    ])
