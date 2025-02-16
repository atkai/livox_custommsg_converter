# Livox CustomMsg Converter

This tool is designed to convert messages from type "livox_ros_driver2/CustomMsg" to type "livox_ros_driver/CustomMsg".
Some SLAM systems only support `livox_ros_driver/CustomMsg`, so this tool helps ensure compatibility when using data collected with `livox_ros_driver2`.
It also supports conversion from type "livox_ros_driver/CustomMsg" to type "livox_ros_driver2/CustomMsg".

## Features
- Convert `livox_ros_driver2/CustomMsg` to `livox_ros_driver/CustomMsg`
- Convert `livox_ros_driver/CustomMsg` to `livox_ros_driver2/CustomMsg`


## Installtion 
Before using this tool, we need install the following dependencies:
- [Livox-SDK](https://github.com/Livox-SDK/Livox-SDK)
- [Livox-SDK2](https://github.com/Livox-SDK/Livox-SDK2)

Make sure you have 'Livox-SDK' and 'Livox-SDK2' installed and set up on your system before proceeding.

To install and compile this tool, follow the following steps:
(1) First, create a catkin workspace that includes a "src" folder;
(2) Get into this folder and clone the necessary dependencies 'livox_ros_driver' and 'livox_ros_driver2';
```
git clone https://github.com/Livox-SDK/livox_ros_driver
git clone https://github.com/Livox-SDK/livox_ros_driver2
```

(3) Clone this repo;
```
git clone https://github.com/atkai/livox_custommsg_converter

```
(4) Back to the workspace, compile and source the workspace;
```
catkin_make
source devel/setup.sh
```


## Usage

```
roslaunch livox_custommsg_converter run_v2tov1.launch

``` 
Before launching the launch file, remember to modify the file path.


## Notes
1. Since 'Livox-SDK2' support both 'ROS1' and 'ROS2', we need to make some changes to the 'CMakeLists.txt'
```
set(ROS_EDITION "ROS1" CACHE STRING "ROS1 or ROS2") 
```
