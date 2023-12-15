import rospy
from std_msgs.msg import Int32
from airobots_ammr.srv import *
import time

def Give_job(location):
    print("Give_job")
    rospy.wait_for_service('Job')
    try:
        get_job = rospy.ServiceProxy('Job', Job)
        res = get_job(location)
        return res.ok
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def Callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    Give_job(data.data)
    time.sleep(5)

if __name__ == "__main__":
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", Int32, Callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()
