cmake_minimum_required(VERSION 3.10)

project(livox_custommsg_converter)

# Find required packages
find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    livox_ros_driver
    livox_ros_driver2
)

# Include directories
include_directories(
    ${catkin_INCLUDE_DIRS}
)

catkin_package(
    CATKIN_DEPENDS roscpp std_msgs livox_ros_driver livox_ros_driver2
)

# Add the executable for v2 to v1 conversion
add_executable(livox_custommsg_v2tov1 src/convert_v2tov1.cpp)
target_link_libraries(livox_custommsg_v2tov1
    ${catkin_LIBRARIES}
)

# Add the executable for v1 to v2 conversion
add_executable(livox_custommsg_v1tov2 src/convert_v1tov2.cpp)
target_link_libraries(livox_custommsg_v1tov2
    ${catkin_LIBRARIES}
)