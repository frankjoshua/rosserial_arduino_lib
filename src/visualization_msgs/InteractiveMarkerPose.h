#ifndef _ROS_visualization_msgs_InteractiveMarkerPose_h
#define _ROS_visualization_msgs_InteractiveMarkerPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace visualization_msgs
{

    static const char visualization_msgs_InteractiveMarkerPose_type[] PROGMEM= "visualization_msgs/InteractiveMarkerPose";
    static const char visualization_msgs_InteractiveMarkerPose_md5[] PROGMEM= "a6e6833209a196a38d798dadb02c81f8";
  class InteractiveMarkerPose : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef const char* _name_type;
      _name_type name;

    InteractiveMarkerPose():
      header(),
      pose(),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)visualization_msgs_InteractiveMarkerPose_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)visualization_msgs_InteractiveMarkerPose_md5);return md5_msg; };

  };

}
#endif
