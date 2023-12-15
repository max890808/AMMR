; Auto-generated. Do not edit!


(cl:in-package airobots_ammr-srv)


;//! \htmlinclude Job-request.msg.html

(cl:defclass <Job-request> (roslisp-msg-protocol:ros-message)
  ((ammr_location
    :reader ammr_location
    :initarg :ammr_location
    :type cl:integer
    :initform 0))
)

(cl:defclass Job-request (<Job-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Job-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Job-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name airobots_ammr-srv:<Job-request> is deprecated: use airobots_ammr-srv:Job-request instead.")))

(cl:ensure-generic-function 'ammr_location-val :lambda-list '(m))
(cl:defmethod ammr_location-val ((m <Job-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:ammr_location-val is deprecated.  Use airobots_ammr-srv:ammr_location instead.")
  (ammr_location m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Job-request>) ostream)
  "Serializes a message object of type '<Job-request>"
  (cl:let* ((signed (cl:slot-value msg 'ammr_location)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Job-request>) istream)
  "Deserializes a message object of type '<Job-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ammr_location) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Job-request>)))
  "Returns string type for a service object of type '<Job-request>"
  "airobots_ammr/JobRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Job-request)))
  "Returns string type for a service object of type 'Job-request"
  "airobots_ammr/JobRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Job-request>)))
  "Returns md5sum for a message object of type '<Job-request>"
  "121b506e876d46cc88efd65664c7abde")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Job-request)))
  "Returns md5sum for a message object of type 'Job-request"
  "121b506e876d46cc88efd65664c7abde")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Job-request>)))
  "Returns full string definition for message of type '<Job-request>"
  (cl:format cl:nil "int32 ammr_location~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Job-request)))
  "Returns full string definition for message of type 'Job-request"
  (cl:format cl:nil "int32 ammr_location~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Job-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Job-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Job-request
    (cl:cons ':ammr_location (ammr_location msg))
))
;//! \htmlinclude Job-response.msg.html

(cl:defclass <Job-response> (roslisp-msg-protocol:ros-message)
  ((ok
    :reader ok
    :initarg :ok
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Job-response (<Job-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Job-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Job-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name airobots_ammr-srv:<Job-response> is deprecated: use airobots_ammr-srv:Job-response instead.")))

(cl:ensure-generic-function 'ok-val :lambda-list '(m))
(cl:defmethod ok-val ((m <Job-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:ok-val is deprecated.  Use airobots_ammr-srv:ok instead.")
  (ok m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Job-response>) ostream)
  "Serializes a message object of type '<Job-response>"
  (cl:let* ((signed (cl:slot-value msg 'ok)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Job-response>) istream)
  "Deserializes a message object of type '<Job-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ok) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Job-response>)))
  "Returns string type for a service object of type '<Job-response>"
  "airobots_ammr/JobResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Job-response)))
  "Returns string type for a service object of type 'Job-response"
  "airobots_ammr/JobResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Job-response>)))
  "Returns md5sum for a message object of type '<Job-response>"
  "121b506e876d46cc88efd65664c7abde")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Job-response)))
  "Returns md5sum for a message object of type 'Job-response"
  "121b506e876d46cc88efd65664c7abde")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Job-response>)))
  "Returns full string definition for message of type '<Job-response>"
  (cl:format cl:nil "int8 ok~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Job-response)))
  "Returns full string definition for message of type 'Job-response"
  (cl:format cl:nil "int8 ok~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Job-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Job-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Job-response
    (cl:cons ':ok (ok msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Job)))
  'Job-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Job)))
  'Job-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Job)))
  "Returns string type for a service object of type '<Job>"
  "airobots_ammr/Job")