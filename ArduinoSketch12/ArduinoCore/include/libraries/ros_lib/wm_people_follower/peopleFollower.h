#ifndef _ROS_SERVICE_peopleFollower_h
#define _ROS_SERVICE_peopleFollower_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wm_people_follower
{

static const char PEOPLEFOLLOWER[] = "wm_people_follower/peopleFollower";

  class peopleFollowerRequest : public ros::Msg
  {
    public:
      int8_t request;
      enum { ACQUIRE_TARGET = 1 };
      enum { START_FOLLOWING = 2 };
      enum { STOP_FOLLOWING = 3 };
      enum { RELEASE_TARGET = 4 };

    peopleFollowerRequest():
      request(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_request;
      u_request.real = this->request;
      *(outbuffer + offset + 0) = (u_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->request);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_request;
      u_request.base = 0;
      u_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->request = u_request.real;
      offset += sizeof(this->request);
     return offset;
    }

    const char * getType(){ return PEOPLEFOLLOWER; };
    const char * getMD5(){ return "6e5b3bee98af79cefa959d91d5fa05ae"; };

  };

  class peopleFollowerResponse : public ros::Msg
  {
    public:
      int8_t response;
      enum { SUCCESS = 1 };
      enum { FAILURE = -1 };

    peopleFollowerResponse():
      response(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_response;
      u_response.real = this->response;
      *(outbuffer + offset + 0) = (u_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->response);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_response;
      u_response.base = 0;
      u_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->response = u_response.real;
      offset += sizeof(this->response);
     return offset;
    }

    const char * getType(){ return PEOPLEFOLLOWER; };
    const char * getMD5(){ return "19011f7e324a39d625c31c7f67825383"; };

  };

  class peopleFollower {
    public:
    typedef peopleFollowerRequest Request;
    typedef peopleFollowerResponse Response;
  };

}
#endif
