#ifndef _ROS_SERVICE_GetPlane_h
#define _ROS_SERVICE_GetPlane_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32.h"
#include "sensor_msgs/PointCloud2.h"

namespace cob_3d_mapping_msgs
{

static const char GETPLANE[] = "cob_3d_mapping_msgs/GetPlane";

  class GetPlaneRequest : public ros::Msg
  {
    public:

    GetPlaneRequest()
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

    const char * getType(){ return GETPLANE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPlaneResponse : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 pc;
      sensor_msgs::PointCloud2 hull;
      uint8_t plane_coeffs_length;
      std_msgs::Float32 st_plane_coeffs;
      std_msgs::Float32 * plane_coeffs;

    GetPlaneResponse():
      pc(),
      hull(),
      plane_coeffs_length(0), plane_coeffs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pc.serialize(outbuffer + offset);
      offset += this->hull.serialize(outbuffer + offset);
      *(outbuffer + offset++) = plane_coeffs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < plane_coeffs_length; i++){
      offset += this->plane_coeffs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pc.deserialize(inbuffer + offset);
      offset += this->hull.deserialize(inbuffer + offset);
      uint8_t plane_coeffs_lengthT = *(inbuffer + offset++);
      if(plane_coeffs_lengthT > plane_coeffs_length)
        this->plane_coeffs = (std_msgs::Float32*)realloc(this->plane_coeffs, plane_coeffs_lengthT * sizeof(std_msgs::Float32));
      offset += 3;
      plane_coeffs_length = plane_coeffs_lengthT;
      for( uint8_t i = 0; i < plane_coeffs_length; i++){
      offset += this->st_plane_coeffs.deserialize(inbuffer + offset);
        memcpy( &(this->plane_coeffs[i]), &(this->st_plane_coeffs), sizeof(std_msgs::Float32));
      }
     return offset;
    }

    const char * getType(){ return GETPLANE; };
    const char * getMD5(){ return "e11c006bc7fabf06881bc7d0de7ba820"; };

  };

  class GetPlane {
    public:
    typedef GetPlaneRequest Request;
    typedef GetPlaneResponse Response;
  };

}
#endif
