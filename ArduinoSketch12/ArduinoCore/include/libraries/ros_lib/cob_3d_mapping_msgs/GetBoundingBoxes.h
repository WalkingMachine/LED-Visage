#ifndef _ROS_SERVICE_GetBoundingBoxes_h
#define _ROS_SERVICE_GetBoundingBoxes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace cob_3d_mapping_msgs
{

static const char GETBOUNDINGBOXES[] = "cob_3d_mapping_msgs/GetBoundingBoxes";

  class GetBoundingBoxesRequest : public ros::Msg
  {
    public:

    GetBoundingBoxesRequest()
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

    const char * getType(){ return GETBOUNDINGBOXES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetBoundingBoxesResponse : public ros::Msg
  {
    public:
      uint8_t bounding_boxes_length;
      sensor_msgs::PointCloud2 st_bounding_boxes;
      sensor_msgs::PointCloud2 * bounding_boxes;

    GetBoundingBoxesResponse():
      bounding_boxes_length(0), bounding_boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = bounding_boxes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bounding_boxes_length; i++){
      offset += this->bounding_boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t bounding_boxes_lengthT = *(inbuffer + offset++);
      if(bounding_boxes_lengthT > bounding_boxes_length)
        this->bounding_boxes = (sensor_msgs::PointCloud2*)realloc(this->bounding_boxes, bounding_boxes_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      bounding_boxes_length = bounding_boxes_lengthT;
      for( uint8_t i = 0; i < bounding_boxes_length; i++){
      offset += this->st_bounding_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->bounding_boxes[i]), &(this->st_bounding_boxes), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return GETBOUNDINGBOXES; };
    const char * getMD5(){ return "2c8e5a484f41a0aac9855792591d7d4c"; };

  };

  class GetBoundingBoxes {
    public:
    typedef GetBoundingBoxesRequest Request;
    typedef GetBoundingBoxesResponse Response;
  };

}
#endif
