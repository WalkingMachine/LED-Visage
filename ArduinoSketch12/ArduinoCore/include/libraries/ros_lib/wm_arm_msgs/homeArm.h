#ifndef _ROS_SERVICE_homeArm_h
#define _ROS_SERVICE_homeArm_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_arm_msgs
{

static const char HOMEARM[] = "wm_arm_msgs/homeArm";

  class homeArmRequest : public ros::Msg
  {
    public:

    homeArmRequest()
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

    const char * getType(){ return HOMEARM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class homeArmResponse : public ros::Msg
  {
    public:
      int8_t homingResult;
      enum { HOMING_SUCCESS = 1 };
      enum { HOMING_FAILURE = 0 };

    homeArmResponse():
      homingResult(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_homingResult;
      u_homingResult.real = this->homingResult;
      *(outbuffer + offset + 0) = (u_homingResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->homingResult);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_homingResult;
      u_homingResult.base = 0;
      u_homingResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->homingResult = u_homingResult.real;
      offset += sizeof(this->homingResult);
     return offset;
    }

    const char * getType(){ return HOMEARM; };
    const char * getMD5(){ return "50f5b3cd4867df7e585a0228bce16aa0"; };

  };

  class homeArm {
    public:
    typedef homeArmRequest Request;
    typedef homeArmResponse Response;
  };

}
#endif
