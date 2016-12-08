#ifndef _ROS_cob_3d_mapping_msgs_Plane_h
#define _ROS_cob_3d_mapping_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_3d_mapping_msgs/Polygon.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_3d_mapping_msgs
{

  class Plane : public ros::Msg
  {
    public:
      uint8_t polygons_length;
      cob_3d_mapping_msgs::Polygon st_polygons;
      cob_3d_mapping_msgs::Polygon * polygons;
      geometry_msgs::Pose pose;
      float weight;
      std_msgs::ColorRGBA color;

    Plane():
      polygons_length(0), polygons(NULL),
      pose(),
      weight(0),
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = polygons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      offset += this->pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_weight;
      u_weight.real = this->weight;
      *(outbuffer + offset + 0) = (u_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weight);
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t polygons_lengthT = *(inbuffer + offset++);
      if(polygons_lengthT > polygons_length)
        this->polygons = (cob_3d_mapping_msgs::Polygon*)realloc(this->polygons, polygons_lengthT * sizeof(cob_3d_mapping_msgs::Polygon));
      offset += 3;
      polygons_length = polygons_lengthT;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(cob_3d_mapping_msgs::Polygon));
      }
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_weight;
      u_weight.base = 0;
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weight = u_weight.real;
      offset += sizeof(this->weight);
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/Plane"; };
    const char * getMD5(){ return "dfaae30aed6b6175cbcc972b30123ff6"; };

  };

}
#endif