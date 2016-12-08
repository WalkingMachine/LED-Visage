#ifndef _ROS_cob_3d_mapping_msgs_PlaneScene_h
#define _ROS_cob_3d_mapping_msgs_PlaneScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_3d_mapping_msgs/Plane.h"

namespace cob_3d_mapping_msgs
{

  class PlaneScene : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t planes_length;
      cob_3d_mapping_msgs::Plane st_planes;
      cob_3d_mapping_msgs::Plane * planes;

    PlaneScene():
      header(),
      planes_length(0), planes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = planes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < planes_length; i++){
      offset += this->planes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t planes_lengthT = *(inbuffer + offset++);
      if(planes_lengthT > planes_length)
        this->planes = (cob_3d_mapping_msgs::Plane*)realloc(this->planes, planes_lengthT * sizeof(cob_3d_mapping_msgs::Plane));
      offset += 3;
      planes_length = planes_lengthT;
      for( uint8_t i = 0; i < planes_length; i++){
      offset += this->st_planes.deserialize(inbuffer + offset);
        memcpy( &(this->planes[i]), &(this->st_planes), sizeof(cob_3d_mapping_msgs::Plane));
      }
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/PlaneScene"; };
    const char * getMD5(){ return "5aa30c5b0316a946cb91f45ed3f1d963"; };

  };

}
#endif