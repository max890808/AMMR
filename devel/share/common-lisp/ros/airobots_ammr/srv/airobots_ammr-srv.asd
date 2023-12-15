
(cl:in-package :asdf)

(defsystem "airobots_ammr-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Job" :depends-on ("_package_Job"))
    (:file "_package_Job" :depends-on ("_package"))
    (:file "Yolo" :depends-on ("_package_Yolo"))
    (:file "_package_Yolo" :depends-on ("_package"))
  ))