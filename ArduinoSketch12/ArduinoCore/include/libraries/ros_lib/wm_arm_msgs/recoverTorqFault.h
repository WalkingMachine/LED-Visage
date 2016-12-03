#ifndef _ROS_SERVICE_recoverTorqFault_h
#define _ROS_SERVICE_recoverTorqFault_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_arm_msgs
{

static const char RECOVERTORQFAULT[] = "wm_arm_msgs/recoverTorqFault";

  class recoverTorqFaultRequest : public ros::Msg
  {
    public:

    recoverTorqFaultRequest()
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

    const char * getType(){ return RECOVERTORQFAULT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class recoverTorqFaultResponse : public ros::Msg
  {
    public:
      int8_t recoverResult;
      enum { RECOVER_SUCCESS = 1 };
      enum { RECOVER_FAILURE = 0 };

    recoverTorqFaultResponse():
      recoverResult(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_recoverResult;
      u_recoverResult.real = this->recoverResult;
      *(outbuffer + offset + 0) = (u_recoverResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recoverResult);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_recoverResult;
      u_recoverResult.base = 0;
      u_recoverResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recoverResult = u_recoverResult.real;
      offset += sizeof(this->recoverResult);
     return offset;
    }

    const char * getType(){ return RECOVERTORQFAULT; };
    const char * getMD5(){ return "5e47faa5fb83bae7798c942d19896af6"; };

  };

  class recoverTorqFault {
    public:
    typedef recoverTorqFaultRequest Request;
    typedef recoverTorqFaultResponse Response;
  };

}
#endif
