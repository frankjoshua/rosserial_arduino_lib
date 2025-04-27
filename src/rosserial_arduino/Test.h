#ifndef _ROS_SERVICE_Test_h
#define _ROS_SERVICE_Test_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace rosserial_arduino
{

#ifdef ESP8266
    static const char TEST[] = "rosserial_arduino/Test";
#else
    static const char TEST[] PROGMEM= "rosserial_arduino/Test";
#endif

    static const char rosserial_arduino_TestRequest_type[] PROGMEM= "rosserial_arduino/TestRequest";
    static const char rosserial_arduino_TestRequest_md5[] PROGMEM= "39e92f1778057359c64c7b8a7d7b19de";
  class TestRequest : public ros::Msg
  {
    public:
      typedef const char* _input_type;
      _input_type input;

    TestRequest():
      input("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_input = strlen(this->input);
      varToArr(outbuffer + offset, length_input);
      offset += 4;
      memcpy(outbuffer + offset, this->input, length_input);
      offset += length_input;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_input;
      arrToVar(length_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_input-1]=0;
      this->input = (char *)(inbuffer + offset-1);
      offset += length_input;
     return offset;
    }

    #ifdef ESP8266
        const char * getType(){ return TEST; };
        const char * getMD5() { return  ("39e92f1778057359c64c7b8a7d7b19de");};
    #else
        virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)TEST);return type_msg; };
        virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)rosserial_arduino_TestRequest_md5);return md5_msg; };
    #endif

  };

    static const char rosserial_arduino_TestResponse_type[] PROGMEM= "rosserial_arduino/TestResponse";
    static const char rosserial_arduino_TestResponse_md5[] PROGMEM= "0825d95fdfa2c8f4bbb4e9c74bccd3fd";
  class TestResponse : public ros::Msg
  {
    public:
      typedef const char* _output_type;
      _output_type output;

    TestResponse():
      output("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_output = strlen(this->output);
      varToArr(outbuffer + offset, length_output);
      offset += 4;
      memcpy(outbuffer + offset, this->output, length_output);
      offset += length_output;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_output;
      arrToVar(length_output, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_output; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_output-1]=0;
      this->output = (char *)(inbuffer + offset-1);
      offset += length_output;
     return offset;
    }

    #ifdef ESP8266
        const char * getType(){ return TEST; };
        const char * getMD5() { return  ("0825d95fdfa2c8f4bbb4e9c74bccd3fd");};
    #else
        virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)TEST);return type_msg; };
        virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)rosserial_arduino_TestResponse_md5);return md5_msg; };
    #endif

  };

  class Test {
    public:
    typedef TestRequest Request;
    typedef TestResponse Response;
  };

}
#endif
