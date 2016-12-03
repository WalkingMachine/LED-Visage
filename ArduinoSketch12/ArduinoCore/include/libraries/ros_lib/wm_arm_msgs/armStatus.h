#ifndef _ROS_SERVICE_armStatus_h
#define _ROS_SERVICE_armStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_arm_msgs
{

static const char ARMSTATUS[] = "wm_arm_msgs/armStatus";

  class armStatusRequest : public ros::Msg
  {
    public:

    armStatusRequest()
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

    const char * getType(){ return ARMSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class armStatusResponse : public ros::Msg
  {
    public:
      int8_t armStatus;
      enum { ARM_READY = 1 };
      enum { ARM_RUNNING = 2 };
      enum { ARM_TORQUE_FAULT = 3 };

    armStatusResponse():
      armStatus(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_armStatus;
      u_armStatus.real = this->armStatus;
      *(outbuffer + offset + 0) = (u_armStatus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armStatus);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_armStatus;
      u_armStatus.base = 0;
      u_armStatus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->armStatus = u_armStatus.real;
      offset += sizeof(this->armStatus);
     return offset;
    }

    const char * getType(){ return ARMSTATUS; };
    const char * getMD5(){ return "3b94ed79e9ad88321e413f1dadec5195"; };

  };

  class armStatus {
    public:
    typedef armStatusRequest Request;
    typedef armStatusResponse Response;
  };

}
#endif
