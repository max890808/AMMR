; Auto-generated. Do not edit!


(cl:in-package airobots_ammr-msg)


;//! \htmlinclude status.msg.html

(cl:defclass <status> (roslisp-msg-protocol:ros-message)
  ((position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0)
   (status
    :reader status
    :initarg :status
    :type cl:string
    :initform ""))
)

(cl:defclass status (<status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name airobots_ammr-msg:<status> is deprecated: use airobots_ammr-msg:status instead.")))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-msg:position-val is deprecated.  Use airobots_ammr-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-msg:status-val is deprecated.  Use airobots_ammr-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <status>) ostream)
  "Serializes a message object of type '<status>"
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'status))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <status>) istream)
  "Deserializes a message object of type '<status>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'status) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<status>)))
  "Returns string type for a message object of type '<status>"
  "airobots_ammr/status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'status)))
  "Returns string type for a message object of type 'status"
  "airobots_ammr/status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<status>)))
  "Returns md5sum for a message object of type '<status>"
  "561aa337f47712989dd36d699a75f1af")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'status)))
  "Returns md5sum for a message object of type 'status"
  "561aa337f47712989dd36d699a75f1af")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<status>)))
  "Returns full string definition for message of type '<status>"
  (cl:format cl:nil "int32 position~%string status~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'status)))
  "Returns full string definition for message of type 'status"
  (cl:format cl:nil "int32 position~%string status~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <status>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'status))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <status>))
  "Converts a ROS message object to a list"
  (cl:list 'status
    (cl:cons ':position (position msg))
    (cl:cons ':status (status msg))
))
