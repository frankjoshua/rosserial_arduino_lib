#ifndef _ROS_octomap_msgs_OctomapWithPose_h
#define _ROS_octomap_msgs_OctomapWithPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "octomap_msgs/Octomap.h"

namespace octomap_msgs
{

  class OctomapWithPose : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose origin;
      octomap_msgs::Octomap octomap;

    OctomapWithPose():
      header(),
      origin(),
      octomap()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->octomap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->octomap.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "octomap_msgs/OctomapWithPose"; };
    const char * getMD5(){ return "20b380aca6a508a657e95526cddaf618"; };

  };

}
#endif