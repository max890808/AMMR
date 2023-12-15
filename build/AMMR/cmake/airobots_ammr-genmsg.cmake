# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "airobots_ammr: 1 messages, 2 services")

set(MSG_I_FLAGS "-Iairobots_ammr:/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(airobots_ammr_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_custom_target(_airobots_ammr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "airobots_ammr" "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" ""
)

get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_custom_target(_airobots_ammr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "airobots_ammr" "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" ""
)

get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_custom_target(_airobots_ammr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "airobots_ammr" "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr
)

### Generating Services
_generate_srv_cpp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr
)
_generate_srv_cpp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr
)

### Generating Module File
_generate_module_cpp(airobots_ammr
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(airobots_ammr_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(airobots_ammr_generate_messages airobots_ammr_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_cpp _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_cpp _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_cpp _airobots_ammr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(airobots_ammr_gencpp)
add_dependencies(airobots_ammr_gencpp airobots_ammr_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS airobots_ammr_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr
)

### Generating Services
_generate_srv_eus(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr
)
_generate_srv_eus(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr
)

### Generating Module File
_generate_module_eus(airobots_ammr
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(airobots_ammr_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(airobots_ammr_generate_messages airobots_ammr_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_eus _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_eus _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_eus _airobots_ammr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(airobots_ammr_geneus)
add_dependencies(airobots_ammr_geneus airobots_ammr_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS airobots_ammr_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr
)

### Generating Services
_generate_srv_lisp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr
)
_generate_srv_lisp(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr
)

### Generating Module File
_generate_module_lisp(airobots_ammr
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(airobots_ammr_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(airobots_ammr_generate_messages airobots_ammr_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_lisp _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_lisp _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_lisp _airobots_ammr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(airobots_ammr_genlisp)
add_dependencies(airobots_ammr_genlisp airobots_ammr_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS airobots_ammr_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr
)

### Generating Services
_generate_srv_nodejs(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr
)
_generate_srv_nodejs(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr
)

### Generating Module File
_generate_module_nodejs(airobots_ammr
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(airobots_ammr_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(airobots_ammr_generate_messages airobots_ammr_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_nodejs _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_nodejs _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_nodejs _airobots_ammr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(airobots_ammr_gennodejs)
add_dependencies(airobots_ammr_gennodejs airobots_ammr_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS airobots_ammr_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr
)

### Generating Services
_generate_srv_py(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr
)
_generate_srv_py(airobots_ammr
  "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr
)

### Generating Module File
_generate_module_py(airobots_ammr
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(airobots_ammr_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(airobots_ammr_generate_messages airobots_ammr_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_py _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_py _airobots_ammr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg" NAME_WE)
add_dependencies(airobots_ammr_generate_messages_py _airobots_ammr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(airobots_ammr_genpy)
add_dependencies(airobots_ammr_genpy airobots_ammr_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS airobots_ammr_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/airobots_ammr
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(airobots_ammr_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/airobots_ammr
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(airobots_ammr_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/airobots_ammr
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(airobots_ammr_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/airobots_ammr
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(airobots_ammr_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/airobots_ammr
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(airobots_ammr_generate_messages_py std_msgs_generate_messages_py)
endif()
