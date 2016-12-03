#ifndef _ROS_SERVICE_computePlan_h
#define _ROS_SERVICE_computePlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/CollisionObject.h"

namespace wm_arm_msgs
{

static const char COMPUTEPLAN[] = "wm_arm_msgs/computePlan";

  class computePlanRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped targetPose;
      uint8_t jointPos_length;
      float st_jointPos;
      float * jointPos;
      int8_t planningSpace;
      moveit_msgs::CollisionObject collisionObject;
      enum { CARTESIAN_SPACE = 1 };
      enum { JOINT_SPACE = 2 };

    computePlanRequest():
      targetPose(),
      jointPos_length(0), jointPos(NULL),
      planningSpace(0),
      collisionObject()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->targetPose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = jointPos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jointPos_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jointPos[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_planningSpace;
      u_planningSpace.real = this->planningSpace;
      *(outbuffer + offset + 0) = (u_planningSpace.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->planningSpace);
      offset += this->collisionObject.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->targetPose.deserialize(inbuffer + offset);
      uint8_t jointPos_lengthT = *(inbuffer + offset++);
      if(jointPos_lengthT > jointPos_length)
        this->jointPos = (float*)realloc(this->jointPos, jointPos_lengthT * sizeof(float));
      offset += 3;
      jointPos_length = jointPos_lengthT;
      for( uint8_t i = 0; i < jointPos_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_jointPos));
        memcpy( &(this->jointPos[i]), &(this->st_jointPos), sizeof(float));
      }
      union {
        int8_t real;
        uint8_t base;
      } u_planningSpace;
      u_planningSpace.base = 0;
      u_planningSpace.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->planningSpace = u_planningSpace.real;
      offset += sizeof(this->planningSpace);
      offset += this->collisionObject.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return COMPUTEPLAN; };
    const char * getMD5(){ return "f1c2a31c9bb473536a6145fe83ed9db9"; };

  };

  class computePlanResponse : public ros::Msg
  {
    public:
      int8_t planningResult;
      moveit_msgs::RobotTrajectory trajectory;
      enum { PLANNING_SUCCESS = 1 };
      enum { PLANNING_FAILURE = 0 };

    computePlanResponse():
      planningResult(0),
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_planningResult;
      u_planningResult.real = this->planningResult;
      *(outbuffer + offset + 0) = (u_planningResult.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->planningResult);
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_planningResult;
      u_planningResult.base = 0;
      u_planningResult.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->planningResult = u_planningResult.real;
      offset += sizeof(this->planningResult);
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return COMPUTEPLAN; };
    const char * getMD5(){ return "694fc1fd2e6ebc099d6ed661aab2889e"; };

  };

  class computePlan {
    public:
    typedef computePlanRequest Request;
    typedef computePlanResponse Response;
  };

}
#endif
