#ifndef _ROS_SERVICE_setState_h
#define _ROS_SERVICE_setState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_follow
{

static const char SETSTATE[] = "wm_follow/setState";

  class setStateRequest : public ros::Msg
  {
    public:
      int8_t state;
      enum { START_FOLLOWING =  1 };
      enum { STOP_FOLLOWING =  0 };
      enum { LOCK =  2 };
      enum { UNLOCK =  3 };

    setStateRequest():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return SETSTATE; };
    const char * getMD5(){ return "7817b882771bbf56b83751af7be40b15"; };

  };

  class setStateResponse : public ros::Msg
  {
    public:

    setStateResponse()
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

    const char * getType(){ return SETSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class setState {
    public:
    typedef setStateRequest Request;
    typedef setStateResponse Response;
  };

}
#endif
