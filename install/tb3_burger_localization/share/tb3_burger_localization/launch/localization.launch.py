import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node

def generate_launch_description():

    # Get Package Description and Directory
    package_description = 'tb3_burger_localization'
    package_directory = get_package_share_directory(package_description)
    
    # Build the path to the map YAML file
    map_yaml = PathJoinSubstitution([package_directory, 'maps', 'tb3_burger_realrobotlab.yaml'])

    # Define paths to AMCL configuration file
    amcl_yaml = os.path.join(package_directory, 'config', 'amcl_config.yaml')

    # Define the path to the RViz configuration file
    rviz_config_file = os.path.join(package_directory, 'rviz', 'localization.rviz')

    # Define RViz node
    rviz_node = Node(package='rviz2', executable='rviz2',
                     name='rviz_node', output='screen',
                     parameters=[{'use_sim_time': False}],
                     arguments=['-d', rviz_config_file])

    # Define Map Server node
    map_server_node = Node(package='nav2_map_server', executable='map_server',
                           name='map_server', output='screen',
                           parameters=[{'use_sim_time': False},
                                       {'yaml_filename': map_yaml}])

    # Define AMCL node for real robot
    amcl_node = Node(package='nav2_amcl', executable='amcl',
                     name='amcl', output='screen',
                     parameters=[amcl_yaml])

    # Define Lifecycle Manager node
    lifecycle_manager_node = Node(package='nav2_lifecycle_manager', executable='lifecycle_manager',
                                  name='lifecycle_manager_mapper', output='screen',
                                  parameters=[{'use_sim_time': False},
                                              {'autostart': True},
                                              {'node_names': ['map_server', 'amcl']}])

    # Return the LaunchDescription with all nodes and arguments
    return LaunchDescription([
        rviz_node,
        map_server_node,
        amcl_node,
        lifecycle_manager_node,
    ])
