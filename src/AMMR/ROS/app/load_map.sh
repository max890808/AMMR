#!/bin/bash

echo "Load Map:${1}"
[ "$#" != 1 ] && echo "Please provide 1 arguments, load_map.sh MapName" && exit
rosrun map_server map_server ${1}.yaml
