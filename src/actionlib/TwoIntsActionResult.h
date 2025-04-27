#ifndef _ROS_actionlib_TwoIntsActionResult_h
#define _ROS_actionlib_TwoIntsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "actionlib/TwoIntsResult.h"

namespace actionlib
{

    static const char actionlib_TwoIntsActionResult_type[] PROGMEM= "actionlib/TwoIntsActionResult";
    static const char actionlib_TwoIntsActionResult_md5[] PROGMEM= "3ba7dea8b8cddcae4528ade4ef74b6e7";
  class TwoIntsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef actionlib::TwoIntsResult _result_type;
      _result_type result;

    TwoIntsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)actionlib_TwoIntsActionResult_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)actionlib_TwoIntsActionResult_md5);return md5_msg; };

  };

}
#endif
