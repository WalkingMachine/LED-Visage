#ifndef _ROS_SERVICE_robotStatus_h
#define _ROS_SERVICE_robotStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_supervisor
{

static const char ROBOTSTATUS[] = "wm_supervisor/robotStatus";

  class robotStatusRequest : public ros::Msg
  {
    public:

    robotStatusRequest()
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

    const char * getType(){ return ROBOTSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class robotStatusResponse : public ros::Msg
  {
    public:
      int8_t status;
      enum { STATUS_OK = 1 };
      enum { STOP_COMMANDED = -1 };

    robotStatusResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return ROBOTSTATUS; };
    const char * getMD5(){ return "fe64813bdfab51d3fbd89412013ad279"; };

  };

  class robotStatus {
    public:
    typedef robotStatusRequest Request;
    typedef robotStatusResponse Response;
  };

}
#endif
