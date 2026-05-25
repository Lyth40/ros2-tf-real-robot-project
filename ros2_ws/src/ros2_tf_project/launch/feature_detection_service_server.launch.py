from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_path
import os

def generate_launch_description():
    rviz_config_path = os.path.join(
        get_package_share_path('ros2_tf_project'),
        'rviz',
        'tb3_burger.rviz.rviz'
    )

    FD = Node(
        package='ros2_tf_project',
        executable='feature_detector',
        name='feature_detector',
        output='screen',
        emulate_tty=True  
    )
        
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', rviz_config_path],
        output='screen'
    )


    return LaunchDescription([
        FD,
        rviz
    ])
