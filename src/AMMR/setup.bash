#!/bin/bash

SCRIPT=`realpath $BASH_SOURCE`
SCRIPTPATH=`dirname $SCRIPT`
echo "Add ${SCRIPTPATH} to ROS_PACKAGE_PATH"
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:${SCRIPTPATH}