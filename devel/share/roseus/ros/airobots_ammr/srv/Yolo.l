;; Auto-generated. Do not edit!


(when (boundp 'airobots_ammr::Yolo)
  (if (not (find-package "AIROBOTS_AMMR"))
    (make-package "AIROBOTS_AMMR"))
  (shadow 'Yolo (find-package "AIROBOTS_AMMR")))
(unless (find-package "AIROBOTS_AMMR::YOLO")
  (make-package "AIROBOTS_AMMR::YOLO"))
(unless (find-package "AIROBOTS_AMMR::YOLOREQUEST")
  (make-package "AIROBOTS_AMMR::YOLOREQUEST"))
(unless (find-package "AIROBOTS_AMMR::YOLORESPONSE")
  (make-package "AIROBOTS_AMMR::YOLORESPONSE"))

(in-package "ROS")





(defclass airobots_ammr::YoloRequest
  :super ros::object
  :slots (_id _demand ))

(defmethod airobots_ammr::YoloRequest
  (:init
   (&key
    ((:id __id) 0)
    ((:demand __demand) 0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _demand (round __demand))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:demand
   (&optional __demand)
   (if __demand (setq _demand __demand)) _demand)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; int32 _demand
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; int32 _demand
       (write-long _demand s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _demand
     (setq _demand (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass airobots_ammr::YoloResponse
  :super ros::object
  :slots (_id _position _orientation ))

(defmethod airobots_ammr::YoloResponse
  (:init
   (&key
    ((:id __id) 0)
    ((:position __position) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:orientation __orientation) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _position __position)
   (setq _orientation (float __orientation))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:orientation
   (&optional __orientation)
   (if __orientation (setq _orientation __orientation)) _orientation)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; float32[4] _position
    (* 4    4)
    ;; float32 _orientation
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; float32[4] _position
     (dotimes (i 4)
       (sys::poke (elt _position i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32 _orientation
       (sys::poke _orientation (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32[4] _position
   (dotimes (i (length _position))
     (setf (elt _position i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32 _orientation
     (setq _orientation (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass airobots_ammr::Yolo
  :super ros::object
  :slots ())

(setf (get airobots_ammr::Yolo :md5sum-) "7b27c6abe40c22cf4eac73520da2bb11")
(setf (get airobots_ammr::Yolo :datatype-) "airobots_ammr/Yolo")
(setf (get airobots_ammr::Yolo :request) airobots_ammr::YoloRequest)
(setf (get airobots_ammr::Yolo :response) airobots_ammr::YoloResponse)

(defmethod airobots_ammr::YoloRequest
  (:response () (instance airobots_ammr::YoloResponse :init)))

(setf (get airobots_ammr::YoloRequest :md5sum-) "7b27c6abe40c22cf4eac73520da2bb11")
(setf (get airobots_ammr::YoloRequest :datatype-) "airobots_ammr/YoloRequest")
(setf (get airobots_ammr::YoloRequest :definition-)
      "int32 id
int32 demand 
---
int32 id
float32[4] position
float32 orientation 
")

(setf (get airobots_ammr::YoloResponse :md5sum-) "7b27c6abe40c22cf4eac73520da2bb11")
(setf (get airobots_ammr::YoloResponse :datatype-) "airobots_ammr/YoloResponse")
(setf (get airobots_ammr::YoloResponse :definition-)
      "int32 id
int32 demand 
---
int32 id
float32[4] position
float32 orientation 
")



(provide :airobots_ammr/Yolo "7b27c6abe40c22cf4eac73520da2bb11")


