#!/bin/bash

docker build -t ros_serial_update .

docker run -d --name ros_serial_update ros_serial_update roscore

docker cp ros_serial_update:/tmp/ros_lib ./

docker stop ros_serial_update

docker rm ros_serial_update
