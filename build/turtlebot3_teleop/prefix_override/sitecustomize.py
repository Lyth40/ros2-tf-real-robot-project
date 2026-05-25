import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/latih/ros2-tf-real-robot-project/install/turtlebot3_teleop'
