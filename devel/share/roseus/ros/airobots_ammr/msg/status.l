;; Auto-generated. Do not edit!


(when (boundp 'airobots_ammr::status)
  (if (not (find-package "AIROBOTS_AMMR"))
    (make-package "AIROBOTS_AMMR"))
  (shadow 'status (find-package "AIROBOTS_AMMR")))
(unless (find-package "AIROBOTS_AMMR::STATUS")
  (make-package "AIROBOTS_AMMR::STATUS"))

(in-package "ROS")
;;//! \htmlinclude status.msg.html


(defclass airobots_ammr::status
  :super ros::object
  :slots (_position _status ))

(defmethod airobots_ammr::status
  (:init
   (&key
    ((:position __position) 0)
    ((:status __status) "")
    )
   (send-super :init)
   (setq _position (round __position))
   (setq _status (string __status))
   self)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; int32 _position
    4
    ;; string _status
    4 (length _status)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _position
       (write-long _position s)
     ;; string _status
       (write-long (length _status) s) (princ _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _position
     (setq _position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _status
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get airobots_ammr::status :md5sum-) "561aa337f47712989dd36d699a75f1af")
(setf (get airobots_ammr::status :datatype-) "airobots_ammr/status")
(setf (get airobots_ammr::status :definition-)
      "int32 position
string status
")



(provide :airobots_ammr/status "561aa337f47712989dd36d699a75f1af")


