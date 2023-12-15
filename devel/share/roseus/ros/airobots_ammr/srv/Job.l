;; Auto-generated. Do not edit!


(when (boundp 'airobots_ammr::Job)
  (if (not (find-package "AIROBOTS_AMMR"))
    (make-package "AIROBOTS_AMMR"))
  (shadow 'Job (find-package "AIROBOTS_AMMR")))
(unless (find-package "AIROBOTS_AMMR::JOB")
  (make-package "AIROBOTS_AMMR::JOB"))
(unless (find-package "AIROBOTS_AMMR::JOBREQUEST")
  (make-package "AIROBOTS_AMMR::JOBREQUEST"))
(unless (find-package "AIROBOTS_AMMR::JOBRESPONSE")
  (make-package "AIROBOTS_AMMR::JOBRESPONSE"))

(in-package "ROS")





(defclass airobots_ammr::JobRequest
  :super ros::object
  :slots (_ammr_location ))

(defmethod airobots_ammr::JobRequest
  (:init
   (&key
    ((:ammr_location __ammr_location) 0)
    )
   (send-super :init)
   (setq _ammr_location (round __ammr_location))
   self)
  (:ammr_location
   (&optional __ammr_location)
   (if __ammr_location (setq _ammr_location __ammr_location)) _ammr_location)
  (:serialization-length
   ()
   (+
    ;; int32 _ammr_location
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _ammr_location
       (write-long _ammr_location s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _ammr_location
     (setq _ammr_location (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass airobots_ammr::JobResponse
  :super ros::object
  :slots (_ok ))

(defmethod airobots_ammr::JobResponse
  (:init
   (&key
    ((:ok __ok) 0)
    )
   (send-super :init)
   (setq _ok (round __ok))
   self)
  (:ok
   (&optional __ok)
   (if __ok (setq _ok __ok)) _ok)
  (:serialization-length
   ()
   (+
    ;; int8 _ok
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _ok
       (write-byte _ok s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _ok
     (setq _ok (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ok 127) (setq _ok (- _ok 256)))
   ;;
   self)
  )

(defclass airobots_ammr::Job
  :super ros::object
  :slots ())

(setf (get airobots_ammr::Job :md5sum-) "121b506e876d46cc88efd65664c7abde")
(setf (get airobots_ammr::Job :datatype-) "airobots_ammr/Job")
(setf (get airobots_ammr::Job :request) airobots_ammr::JobRequest)
(setf (get airobots_ammr::Job :response) airobots_ammr::JobResponse)

(defmethod airobots_ammr::JobRequest
  (:response () (instance airobots_ammr::JobResponse :init)))

(setf (get airobots_ammr::JobRequest :md5sum-) "121b506e876d46cc88efd65664c7abde")
(setf (get airobots_ammr::JobRequest :datatype-) "airobots_ammr/JobRequest")
(setf (get airobots_ammr::JobRequest :definition-)
      "int32 ammr_location
---
int8 ok
")

(setf (get airobots_ammr::JobResponse :md5sum-) "121b506e876d46cc88efd65664c7abde")
(setf (get airobots_ammr::JobResponse :datatype-) "airobots_ammr/JobResponse")
(setf (get airobots_ammr::JobResponse :definition-)
      "int32 ammr_location
---
int8 ok
")



(provide :airobots_ammr/Job "121b506e876d46cc88efd65664c7abde")


