#ifndef _ROS_cob_3d_mapping_msgs_ShapeArray_h
#define _ROS_cob_3d_mapping_msgs_ShapeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_3d_mapping_msgs/Shape.h"

namespace cob_3d_mapping_msgs
{

  class ShapeArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t shapes_length;
      cob_3d_mapping_msgs::Shape st_shapes;
      cob_3d_mapping_msgs::Shape * shapes;

    ShapeArray():
      header(),
      shapes_length(0), shapes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = shapes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < shapes_length; i++){
      offset += this->shapes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t shapes_lengthT = *(inbuffer + offset++);
      if(shapes_lengthT > shapes_length)
        this->shapes = (cob_3d_mapping_msgs::Shape*)realloc(this->shapes, shapes_lengthT * sizeof(cob_3d_mapping_msgs::Shape));
      offset += 3;
      shapes_length = shapes_lengthT;
      for( uint8_t i = 0; i < shapes_length; i++){
      offset += this->st_shapes.deserialize(inbuffer + offset);
        memcpy( &(this->shapes[i]), &(this->st_shapes), sizeof(cob_3d_mapping_msgs::Shape));
      }
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/ShapeArray"; };
    const char * getMD5(){ return "bc723f28be387c6f3061c2c124641aac"; };

  };

}
#endif