/*
 * rosserial Publisher Example
 * Prints "hello world!"
 * This intend to connect to a Wifi Access Point
 * and a rosserial socket server.
 * You can launch the rosserial socket server with
 * roslaunch rosserial_server socket.launch
 * The default port is 11411
 *
 */
#include <WiFiNINA.h>
#include <ros.h>
#include <std_msgs/String.h>

const char* ssid     = "your-ssid";
const char* password = "your-password";
// Set the rosserial socket server IP address (likely ROS_IP)
IPAddress server(192,168,1,1);
// Set the rosserial socket server port
const uint16_t serverPort = 11411;

ros::NodeHandle nh;
// Make a chatter publisher
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

// Be polite and say hello
char hello[13] = "hello world!";

void setup()
{
  // Use Arduino serial to monitor the process
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect the WiFiNINA compatible board to the wifi AP
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Another way to get IP
  Serial.print("IP = ");
  Serial.println(nh.getHardware()->getLocalIP());

  // Start to be polite
  nh.advertise(chatter);
}

void loop()
{
  if (nh.connected()) {
    Serial.println("Connected");
    // Say hello
    str_msg.data = hello;
    chatter.publish( &str_msg );
  } else {
    Serial.println("Not Connected");
  }
  nh.spinOnce();
  // Loop at ~1Hz
  delay(1000);
}
