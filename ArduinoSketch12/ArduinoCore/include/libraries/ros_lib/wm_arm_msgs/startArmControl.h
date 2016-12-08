#ifndef _ROS_SERVICE_startArmControl_h
#define _ROS_SERVICE_startArmControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_arm_msgs
{

static const char STARTARMCONTROL[] = "wm_arm_msgs/startArmControl";

  class startArmControlRequest : public ros::Msg
  {
    public:

    startArmControlRequest()
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

    const char * getType(){ return STARTARMCONTROL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class startArmControlResponse : public ros::Msg
  {
    public:
      int8_t startResult;
      enum { START_SUCCESS = 1 };
      enum { START_FAILURE = 0 };

    startArmControlResponse():
      startResult(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_startResult;
      u_startResult.real = this->startResult;
      *(outbuffer + offset + 0) = (u_startResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->startResult);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_startResult;
      u_startResult.base = 0;
      u_startResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->startResult = u_startResult.real;
      offset += sizeof(this->startResult);
     return offset;
    }

    const char * getType(){ return STARTARMCONTROL; };
    const char * getMD5(){ return "35756c5a4eaf446d99b95de471f87bd7"; };

  };

  class startArmControl {
    public:
    typedef startArmControlRequest Request;
    typedef startArmControlResponse Response;
  };

}
#endif
