#ifndef _ROS_cob_3d_mapping_msgs_CurvedPolygon_h
#define _ROS_cob_3d_mapping_msgs_CurvedPolygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "cob_3d_mapping_msgs/SimilarityScore.h"
#include "cob_3d_mapping_msgs/PolylinePoint.h"
#include "cob_3d_mapping_msgs/Feature.h"

namespace cob_3d_mapping_msgs
{

  class CurvedPolygon : public ros::Msg
  {
    public:
      ros::Time stamp;
      uint32_t ID;
      float parameter[6];
      uint8_t score_length;
      cob_3d_mapping_msgs::SimilarityScore st_score;
      cob_3d_mapping_msgs::SimilarityScore * score;
      uint8_t polyline_length;
      cob_3d_mapping_msgs::PolylinePoint st_polyline;
      cob_3d_mapping_msgs::PolylinePoint * polyline;
      uint8_t features_length;
      cob_3d_mapping_msgs::Feature st_features;
      cob_3d_mapping_msgs::Feature * features;
      const char* energy;
      float weight;

    CurvedPolygon():
      stamp(),
      ID(0),
      parameter(),
      score_length(0), score(NULL),
      polyline_length(0), polyline(NULL),
      features_length(0), features(NULL),
      energy(""),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      *(outbuffer + offset + 0) = (this->ID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ID >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ID >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ID >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ID);
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_parameteri;
      u_parameteri.real = this->parameter[i];
      *(outbuffer + offset + 0) = (u_parameteri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_parameteri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_parameteri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_parameteri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameter[i]);
      }
      *(outbuffer + offset++) = score_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < score_length; i++){
      offset += this->score[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = polyline_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < polyline_length; i++){
      offset += this->polyline[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = features_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < features_length; i++){
      offset += this->features[i].serialize(outbuffer + offset);
      }
      uint32_t length_energy = strlen(this->energy);
      memcpy(outbuffer + offset, &length_energy, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->energy, length_energy);
      offset += length_energy;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      this->ID =  ((uint32_t) (*(inbuffer + offset)));
      this->ID |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ID |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ID |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ID);
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_parameteri;
      u_parameteri.base = 0;
      u_parameteri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_parameteri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_parameteri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_parameteri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->parameter[i] = u_parameteri.real;
      offset += sizeof(this->parameter[i]);
      }
      uint8_t score_lengthT = *(inbuffer + offset++);
      if(score_lengthT > score_length)
        this->score = (cob_3d_mapping_msgs::SimilarityScore*)realloc(this->score, score_lengthT * sizeof(cob_3d_mapping_msgs::SimilarityScore));
      offset += 3;
      score_length = score_lengthT;
      for( uint8_t i = 0; i < score_length; i++){
      offset += this->st_score.deserialize(inbuffer + offset);
        memcpy( &(this->score[i]), &(this->st_score), sizeof(cob_3d_mapping_msgs::SimilarityScore));
      }
      uint8_t polyline_lengthT = *(inbuffer + offset++);
      if(polyline_lengthT > polyline_length)
        this->polyline = (cob_3d_mapping_msgs::PolylinePoint*)realloc(this->polyline, polyline_lengthT * sizeof(cob_3d_mapping_msgs::PolylinePoint));
      offset += 3;
      polyline_length = polyline_lengthT;
      for( uint8_t i = 0; i < polyline_length; i++){
      offset += this->st_polyline.deserialize(inbuffer + offset);
        memcpy( &(this->polyline[i]), &(this->st_polyline), sizeof(cob_3d_mapping_msgs::PolylinePoint));
      }
      uint8_t features_lengthT = *(inbuffer + offset++);
      if(features_lengthT > features_length)
        this->features = (cob_3d_mapping_msgs::Feature*)realloc(this->features, features_lengthT * sizeof(cob_3d_mapping_msgs::Feature));
      offset += 3;
      features_length = features_lengthT;
      for( uint8_t i = 0; i < features_length; i++){
      offset += this->st_features.deserialize(inbuffer + offset);
        memcpy( &(this->features[i]), &(this->st_features), sizeof(cob_3d_mapping_msgs::Feature));
      }
      uint32_t length_energy;
      memcpy(&length_energy, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_energy; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_energy-1]=0;
      this->energy = (char *)(inbuffer + offset-1);
      offset += length_energy;
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
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/CurvedPolygon"; };
    const char * getMD5(){ return "44b9c6adf55085288b1561faf0dcdb6d"; };

  };

}
#endif