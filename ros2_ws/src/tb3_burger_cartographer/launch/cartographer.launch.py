import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():

    # Get Package Description and Directory
    package_description = 'tb3_burger_cartographer'
    package_directory = get_package_share_directory(package_description)
    
    # Set configuration and RViz file paths
    cartographer_config_dir = os.path.join(package_directory, 'config')
    rviz_config_file = os.path.join(package_directory, 'rviz', 'cartographer.rviz')

    # Define RViz node
    rviz_node = Node(package='rviz2', executable='rviz2',
                     name='rviz_node', output='screen',
                     parameters=[{'use_sim_time': False}],
                     arguments=['-d', rviz_config_file])

    # Define Cartographer node for real-time
    cartographer_node = Node(package='cartographer_ros', executable='cartographer_node',
                             name='cartographer_node', output='screen',
                             parameters=[{'use_sim_time': False}], 
                             arguments=['-configuration_directory', cartographer_config_dir,
                                        '-configuration_basename', 'cartographer.lua'])
    
    # Define occupancy grid node
    occupancy_grid_node = Node(package='cartographer_ros', executable='cartographer_occupancy_grid_node',
                               name='occupancy_grid_node', output='screen',
                               parameters=[{'use_sim_time': False}], 
                               arguments=['-resolution', '0.01', '-publish_period_sec', '1.0'])

    # Return LaunchDescription with all nodes and configurations
    return LaunchDescription([
        rviz_node,
        cartographer_node,
        occupancy_grid_node,
    ]) 

# Command to save the map:
# ros2 run nav2_map_server map_saver_cli -f tb3_burger_realrobotlab
