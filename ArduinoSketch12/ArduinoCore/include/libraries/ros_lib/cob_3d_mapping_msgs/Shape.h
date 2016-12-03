#ifndef _ROS_cob_3d_mapping_msgs_Shape_h
#define _ROS_cob_3d_mapping_msgs_Shape_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/PointCloud2.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_3d_mapping_msgs
{

  class Shape : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t type;
      int32_t id;
      float weight;
      geometry_msgs::Pose pose;
      uint8_t params_length;
      float st_params;
      float * params;
      uint8_t points_length;
      sensor_msgs::PointCloud2 st_points;
      sensor_msgs::PointCloud2 * points;
      uint8_t vertices_length;
      int32_t st_vertices;
      int32_t * vertices;
      std_msgs::ColorRGBA color;
      uint8_t holes_length;
      bool st_holes;
      bool * holes;
      enum { POLYGON = 0 };
      enum { LINE = 1 };
      enum { CURVED = 2 };
      enum { MESH = 3 };
      enum { OTHER = 4 };
      enum { CYLINDER = 5 };

    Shape():
      header(),
      type(0),
      id(0),
      weight(0),
      pose(),
      params_length(0), params(NULL),
      points_length(0), points(NULL),
      vertices_length(0), vertices(NULL),
      color(),
      holes_length(0), holes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
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
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = params_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < params_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->params[i]);
      }
      *(outbuffer + offset++) = points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = vertices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vertices_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_verticesi;
      u_verticesi.real = this->vertices[i];
      *(outbuffer + offset + 0) = (u_verticesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_verticesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_verticesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_verticesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices[i]);
      }
      offset += this->color.serialize(outbuffer + offset);
      *(outbuffer + offset++) = holes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < holes_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_holesi;
      u_holesi.real = this->holes[i];
      *(outbuffer + offset + 0) = (u_holesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->holes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
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
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t params_lengthT = *(inbuffer + offset++);
      if(params_lengthT > params_length)
        this->params = (float*)realloc(this->params, params_lengthT * sizeof(float));
      offset += 3;
      params_length = params_lengthT;
      for( uint8_t i = 0; i < params_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_params));
        memcpy( &(this->params[i]), &(this->st_params), sizeof(float));
      }
      uint8_t points_lengthT = *(inbuffer + offset++);
      if(points_lengthT > points_length)
        this->points = (sensor_msgs::PointCloud2*)realloc(this->points, points_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      points_length = points_lengthT;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(sensor_msgs::PointCloud2));
      }
      uint8_t vertices_lengthT = *(inbuffer + offset++);
      if(vertices_lengthT > vertices_length)
        this->vertices = (int32_t*)realloc(this->vertices, vertices_lengthT * sizeof(int32_t));
      offset += 3;
      vertices_length = vertices_lengthT;
      for( uint8_t i = 0; i < vertices_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_vertices;
      u_st_vertices.base = 0;
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_vertices = u_st_vertices.real;
      offset += sizeof(this->st_vertices);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(int32_t));
      }
      offset += this->color.deserialize(inbuffer + offset);
      uint8_t holes_lengthT = *(inbuffer + offset++);
      if(holes_lengthT > holes_length)
        this->holes = (bool*)realloc(this->holes, holes_lengthT * sizeof(bool));
      offset += 3;
      holes_length = holes_lengthT;
      for( uint8_t i = 0; i < holes_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_holes;
      u_st_holes.base = 0;
      u_st_holes.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_holes = u_st_holes.real;
      offset += sizeof(this->st_holes);
        memcpy( &(this->holes[i]), &(this->st_holes), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/Shape"; };
    const char * getMD5(){ return "d5fc6a3556290a571009cfc613a557d0"; };

  };

}
#endif