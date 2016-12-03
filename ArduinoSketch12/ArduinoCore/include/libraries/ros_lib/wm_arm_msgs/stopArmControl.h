#ifndef _ROS_SERVICE_stopArmControl_h
#define _ROS_SERVICE_stopArmControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_arm_msgs
{

static const char STOPARMCONTROL[] = "wm_arm_msgs/stopArmControl";

  class stopArmControlRequest : public ros::Msg
  {
    public:

    stopArmControlRequest()
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

    const char * getType(){ return STOPARMCONTROL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stopArmControlResponse : public ros::Msg
  {
    public:
      int8_t stopResult;
      enum { STOP_SUCCESS = 1 };
      enum { STOP_FAILURE = 0 };

    stopArmControlResponse():
      stopResult(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_stopResult;
      u_stopResult.real = this->stopResult;
      *(outbuffer + offset + 0) = (u_stopResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stopResult);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_stopResult;
      u_stopResult.base = 0;
      u_stopResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stopResult = u_stopResult.real;
      offset += sizeof(this->stopResult);
     return offset;
    }

    const char * getType(){ return STOPARMCONTROL; };
    const char * getMD5(){ return "e1c31d606b0447983fcd5153113e62ed"; };

  };

  class stopArmControl {
    public:
    typedef stopArmControlRequest Request;
    typedef stopArmControlResponse Response;
  };

}
#endif
