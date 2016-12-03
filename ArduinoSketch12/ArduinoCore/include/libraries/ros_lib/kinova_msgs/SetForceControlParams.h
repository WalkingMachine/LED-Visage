#ifndef _ROS_SERVICE_SetForceControlParams_h
#define _ROS_SERVICE_SetForceControlParams_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace kinova_msgs
{

static const char SETFORCECONTROLPARAMS[] = "kinova_msgs/SetForceControlParams";

  class SetForceControlParamsRequest : public ros::Msg
  {
    public:
      geometry_msgs::Vector3 inertia_linear;
      geometry_msgs::Vector3 inertia_angular;
      geometry_msgs::Vector3 damping_linear;
      geometry_msgs::Vector3 damping_angular;
      geometry_msgs::Vector3 force_min_linear;
      geometry_msgs::Vector3 force_min_angular;
      geometry_msgs::Vector3 force_max_linear;
      geometry_msgs::Vector3 force_max_angular;

    SetForceControlParamsRequest():
      inertia_linear(),
      inertia_angular(),
      damping_linear(),
      damping_angular(),
      force_min_linear(),
      force_min_angular(),
      force_max_linear(),
      force_max_angular()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->inertia_linear.serialize(outbuffer + offset);
      offset += this->inertia_angular.serialize(outbuffer + offset);
      offset += this->damping_linear.serialize(outbuffer + offset);
      offset += this->damping_angular.serialize(outbuffer + offset);
      offset += this->force_min_linear.serialize(outbuffer + offset);
      offset += this->force_min_angular.serialize(outbuffer + offset);
      offset += this->force_max_linear.serialize(outbuffer + offset);
      offset += this->force_max_angular.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->inertia_linear.deserialize(inbuffer + offset);
      offset += this->inertia_angular.deserialize(inbuffer + offset);
      offset += this->damping_linear.deserialize(inbuffer + offset);
      offset += this->damping_angular.deserialize(inbuffer + offset);
      offset += this->force_min_linear.deserialize(inbuffer + offset);
      offset += this->force_min_angular.deserialize(inbuffer + offset);
      offset += this->force_max_linear.deserialize(inbuffer + offset);
      offset += this->force_max_angular.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETFORCECONTROLPARAMS; };
    const char * getMD5(){ return "5c0999be3d1c60dba47ea0b2fd08231e"; };

  };

  class SetForceControlParamsResponse : public ros::Msg
  {
    public:

    SetForceControlParamsResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETFORCECONTROLPARAMS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetForceControlParams {
    public:
    typedef SetForceControlParamsRequest Request;
    typedef SetForceControlParamsResponse Response;
  };

}
#endif