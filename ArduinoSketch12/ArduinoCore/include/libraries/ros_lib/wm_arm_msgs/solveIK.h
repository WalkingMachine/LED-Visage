#ifndef _ROS_SERVICE_solveIK_h
#define _ROS_SERVICE_solveIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace wm_arm_msgs
{

static const char SOLVEIK[] = "wm_arm_msgs/solveIK";

  class solveIKRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose targetPose;

    solveIKRequest():
      targetPose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->targetPose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->targetPose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SOLVEIK; };
    const char * getMD5(){ return "914376da8aec9b5e4e0e49d519dcae93"; };

  };

  class solveIKResponse : public ros::Msg
  {
    public:
      int8_t solveResult;
      float jointPos[6];
      enum { SOLVE_SUCCESS = 1 };
      enum { SOLVE_FAILURE = 0 };

    solveIKResponse():
      solveResult(0),
      jointPos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_solveResult;
      u_solveResult.real = this->solveResult;
      *(outbuffer + offset + 0) = (u_solveResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->solveResult);
      for( uint8_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jointPos[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_solveResult;
      u_solveResult.base = 0;
      u_solveResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->solveResult = u_solveResult.real;
      offset += sizeof(this->solveResult);
      for( uint8_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->jointPos[i]));
      }
     return offset;
    }

    const char * getType(){ return SOLVEIK; };
    const char * getMD5(){ return "2bd8e43c93a4421c51177e0c38956f62"; };

  };

  class solveIK {
    public:
    typedef solveIKRequest Request;
    typedef solveIKResponse Response;
  };

}
#endif
