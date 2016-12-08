/*
 * ros_interface.h
 *
 * Created: 2016-12-03 14:44:18
 *  Author: Salco
 */ 


#ifndef ROS_INTERFACE_H_
#define ROS_INTERFACE_H_

#include <stdint.h>

#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>
//#include "sara_face_led_driver_define.h"
#if defined( TEST_ROS )
	extern void control_emo(const std_msgs::UInt8& emo);
#endif
void init_ros_interface(void);
void ros_spinOnce(void);

#endif /* ROS_INTERFACE_H_ */