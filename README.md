# Jeff Hexapod Robot

ROS 2 workspace for the Jeff Hexapod robot, containing robot description models, gait generation, hardware control interfaces, and teleoperation nodes.

## Packages

- **hexapod_description**: URDF robot models, meshes, and RViz visualization launch files.
- **hexapod_gait**: Gait generation strategies (Wave Gait, Ripple Gait) and gait factory.
- **hexapod_hardware**: ros2_control Hardware Interface plugin for PCA9685 servo control and hardware simulation.
- **hexapod_teleop**: Teleoperation control node.

## Prerequisites

- ROS 2 (Humble recommended)
- colcon build tool
- System packages and dependencies:

```bash
sudo apt update
sudo apt install ros-humble-joint-state-publisher \
                 ros-humble-joint-state-publisher-gui \
                 ros-humble-robot-state-publisher \
                 ros-humble-rviz2 \
                 ros-humble-hardware-interface \
                 ros-humble-rclcpp \
                 ros-humble-rclcpp-lifecycle \
                 ros-humble-pluginlib
```

## Building the Workspace

From the workspace root:

```bash
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

To build a single package:

```bash
colcon build --packages-select <package_name>
```

## How to Run

### 1. Visualize Robot Model in RViz

To launch RViz with joint slider GUI controls:

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 launch hexapod_description display.launch.py
```

To launch without the joint slider GUI:

```bash
ros2 launch hexapod_description display.launch.py use_gui:=false
```

If you encounter OpenGL or DRI driver errors (e.g. in VM/Docker/Nouveau), force software rendering:

```bash
export LIBGL_ALWAYS_SOFTWARE=1
ros2 launch hexapod_description display.launch.py
```

### 2. Run Gait Node

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 run hexapod_gait hexapod_gait
```

### 3. Run Teleoperation Node

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 run hexapod_teleop hexapod_teleop
```
