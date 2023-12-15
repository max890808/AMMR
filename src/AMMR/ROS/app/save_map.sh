#!/bin/bash

echo "Save Topic:${1} map to ${2}......"
[ "$#" != 2 ] && echo "Please provide 2 arguments, save_map.sh MapTopic MapPath" && exit
rosrun map_server map_saver -f ${2} map:=${1}
