#ifndef _ROS_cob_3d_mapping_msgs_CurvedPolygonArray_h
#define _ROS_cob_3d_mapping_msgs_CurvedPolygonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_3d_mapping_msgs/CurvedPolygon.h"

namespace cob_3d_mapping_msgs
{

  class CurvedPolygonArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t polygons_length;
      cob_3d_mapping_msgs::CurvedPolygon st_polygons;
      cob_3d_mapping_msgs::CurvedPolygon * polygons;

    CurvedPolygonArray():
      header(),
      polygons_length(0), polygons(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = polygons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t polygons_lengthT = *(inbuffer + offset++);
      if(polygons_lengthT > polygons_length)
        this->polygons = (cob_3d_mapping_msgs::CurvedPolygon*)realloc(this->polygons, polygons_lengthT * sizeof(cob_3d_mapping_msgs::CurvedPolygon));
      offset += 3;
      polygons_length = polygons_lengthT;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(cob_3d_mapping_msgs::CurvedPolygon));
      }
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/CurvedPolygonArray"; };
    const char * getMD5(){ return "dca7a231f0d66f77a98e4e50cf3157dc"; };

  };

}
#endif