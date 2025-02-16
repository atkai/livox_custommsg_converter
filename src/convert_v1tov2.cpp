#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>

#include <livox_ros_driver/CustomMsg.h>
#include <livox_ros_driver2/CustomMsg.h>
#include <livox_ros_driver/CustomPoint.h>
#include <livox_ros_driver2/CustomPoint.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "rosbag_converter");
    ros::NodeHandle nh("~");

    std::string input_bag_path = "/path/to/input.bag";
    std::string output_bag_path = "/path/to/output.bag";
    std::string lidar_topic = "/livox/lidar";

    nh.getParam("input_bag_path", input_bag_path);
    nh.getParam("output_bag_path", output_bag_path);
    nh.getParam("lidar_topic", lidar_topic);

    rosbag::Bag input_bag;
    rosbag::Bag output_bag;

    input_bag.open(input_bag_path, rosbag::bagmode::Read);
    output_bag.open(output_bag_path, rosbag::bagmode::Write);

    rosbag::View view(input_bag, rosbag::TopicQuery(lidar_topic));

    for (const rosbag::MessageInstance& m : view) {
        livox_ros_driver::CustomMsg::ConstPtr custom_msg = m.instantiate<livox_ros_driver::CustomMsg>();
        if (custom_msg != nullptr) {
            livox_ros_driver2::CustomMsg new_msg;
            // Convert the message fields here
            new_msg.header = custom_msg->header;
            new_msg.timebase = custom_msg->timebase;
            new_msg.point_num = custom_msg->point_num;
            new_msg.lidar_id = custom_msg->lidar_id;
            new_msg.rsvd = custom_msg->rsvd;

            std::vector<livox_ros_driver2::CustomPoint> points;
            for (const livox_ros_driver::CustomPoint& point : custom_msg->points) {
                livox_ros_driver2::CustomPoint new_point;
                // Convert the point fields here
                new_point.x = point.x;
                new_point.y = point.y;
                new_point.z = point.z;

                new_point.reflectivity = point.reflectivity;
                new_point.tag = point.tag;
                new_point.line = point.line;
                new_point.offset_time = point.offset_time;

                points.push_back(new_point);
            }
            new_msg.points = points;

            output_bag.write(lidar_topic, m.getTime(), new_msg);
        }
    }

    for (const rosbag::MessageInstance&m : view){
        output_bag.write(m.getTopic(), m.getTime(), m);
    }

    input_bag.close();
    output_bag.close();

    return 0;
}