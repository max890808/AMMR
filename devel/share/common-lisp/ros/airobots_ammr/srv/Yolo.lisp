; Auto-generated. Do not edit!


(cl:in-package airobots_ammr-srv)


;//! \htmlinclude Yolo-request.msg.html

(cl:defclass <Yolo-request> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (demand
    :reader demand
    :initarg :demand
    :type cl:integer
    :initform 0))
)

(cl:defclass Yolo-request (<Yolo-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Yolo-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Yolo-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name airobots_ammr-srv:<Yolo-request> is deprecated: use airobots_ammr-srv:Yolo-request instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Yolo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:id-val is deprecated.  Use airobots_ammr-srv:id instead.")
  (id m))

(cl:ensure-generic-function 'demand-val :lambda-list '(m))
(cl:defmethod demand-val ((m <Yolo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:demand-val is deprecated.  Use airobots_ammr-srv:demand instead.")
  (demand m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Yolo-request>) ostream)
  "Serializes a message object of type '<Yolo-request>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'demand)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Yolo-request>) istream)
  "Deserializes a message object of type '<Yolo-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'demand) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Yolo-request>)))
  "Returns string type for a service object of type '<Yolo-request>"
  "airobots_ammr/YoloRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Yolo-request)))
  "Returns string type for a service object of type 'Yolo-request"
  "airobots_ammr/YoloRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Yolo-request>)))
  "Returns md5sum for a message object of type '<Yolo-request>"
  "7b27c6abe40c22cf4eac73520da2bb11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Yolo-request)))
  "Returns md5sum for a message object of type 'Yolo-request"
  "7b27c6abe40c22cf4eac73520da2bb11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Yolo-request>)))
  "Returns full string definition for message of type '<Yolo-request>"
  (cl:format cl:nil "int32 id~%int32 demand ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Yolo-request)))
  "Returns full string definition for message of type 'Yolo-request"
  (cl:format cl:nil "int32 id~%int32 demand ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Yolo-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Yolo-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Yolo-request
    (cl:cons ':id (id msg))
    (cl:cons ':demand (demand msg))
))
;//! \htmlinclude Yolo-response.msg.html

(cl:defclass <Yolo-response> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0))
   (orientation
    :reader orientation
    :initarg :orientation
    :type cl:float
    :initform 0.0))
)

(cl:defclass Yolo-response (<Yolo-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Yolo-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Yolo-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name airobots_ammr-srv:<Yolo-response> is deprecated: use airobots_ammr-srv:Yolo-response instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Yolo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:id-val is deprecated.  Use airobots_ammr-srv:id instead.")
  (id m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <Yolo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:position-val is deprecated.  Use airobots_ammr-srv:position instead.")
  (position m))

(cl:ensure-generic-function 'orientation-val :lambda-list '(m))
(cl:defmethod orientation-val ((m <Yolo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader airobots_ammr-srv:orientation-val is deprecated.  Use airobots_ammr-srv:orientation instead.")
  (orientation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Yolo-response>) ostream)
  "Serializes a message object of type '<Yolo-response>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'position))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'orientation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Yolo-response>) istream)
  "Deserializes a message object of type '<Yolo-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'position) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'position)))
    (cl:dotimes (i 4)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'orientation) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Yolo-response>)))
  "Returns string type for a service object of type '<Yolo-response>"
  "airobots_ammr/YoloResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Yolo-response)))
  "Returns string type for a service object of type 'Yolo-response"
  "airobots_ammr/YoloResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Yolo-response>)))
  "Returns md5sum for a message object of type '<Yolo-response>"
  "7b27c6abe40c22cf4eac73520da2bb11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Yolo-response)))
  "Returns md5sum for a message object of type 'Yolo-response"
  "7b27c6abe40c22cf4eac73520da2bb11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Yolo-response>)))
  "Returns full string definition for message of type '<Yolo-response>"
  (cl:format cl:nil "int32 id~%float32[4] position~%float32 orientation ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Yolo-response)))
  "Returns full string definition for message of type 'Yolo-response"
  (cl:format cl:nil "int32 id~%float32[4] position~%float32 orientation ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Yolo-response>))
  (cl:+ 0
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Yolo-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Yolo-response
    (cl:cons ':id (id msg))
    (cl:cons ':position (position msg))
    (cl:cons ':orientation (orientation msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Yolo)))
  'Yolo-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Yolo)))
  'Yolo-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Yolo)))
  "Returns string type for a service object of type '<Yolo>"
  "airobots_ammr/Yolo")