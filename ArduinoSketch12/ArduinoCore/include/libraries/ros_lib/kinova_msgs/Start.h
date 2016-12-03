#ifndef _ROS_SERVICE_Start_h
#define _ROS_SERVICE_Start_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kinova_msgs
{

static const char START[] = "kinova_msgs/Start";

  class StartRequest : public ros::Msg
  {
    public:

    StartRequest()
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

    const char * getType(){ return START; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartResponse : public ros::Msg
  {
    public:
      const char* start_result;

    StartResponse():
      start_result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_start_result = strlen(this->start_result);
      memcpy(outbuffer + offset, &length_start_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->start_result, length_start_result);
      offset += length_start_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_start_result;
      memcpy(&length_start_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_start_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_start_result-1]=0;
      this->start_result = (char *)(inbuffer + offset-1);
      offset += length_start_result;
     return offset;
    }

    const char * getType(){ return START; };
    const char * getMD5(){ return "e762e31d813526eaaa6a12e8354174fc"; };

  };

  class Start {
    public:
    typedef StartRequest Request;
    typedef StartResponse Response;
  };

}
#endif
