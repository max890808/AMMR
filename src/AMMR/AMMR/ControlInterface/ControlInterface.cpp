#include "ControlInterface.h"
#include <geometry_msgs/TransformStamped.h>
#include <Eigen/Geometry> 
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>

/**
 * @brief Construct a new Control Interface instance
 * 
 */
ControlInterface::ControlInterface():mbUseMoveBase(false), mbSubTF(false), mpTFListener(nullptr), linear_x(0.0), angular_z(0.0)
{
	
}

/**
 * @brief Destroy the Control Interface instance
 * 
 */
ControlInterface::~ControlInterface()
{
	if(mbUseMoveBase)
	{
		delete mpMBClient;
	}

	if(mbSubTF)
    {
        delete mpTFListener;
    }

}

/**
 * @brief Set the control target of this interface
 * 
 * @param pAMR The pointer to the robot, see also @ref AMR
 */
void ControlInterface::SetAMR(AMR *pAMR)
{
    mpAMR = pAMR;
}

/**
 * @brief The function that setup the @ref MoveBaseClient.
 * 
 * @param bSpinThread If true, then the @ref MoveBaseClient starts its own spin thread.
 * @param nUpdateRate The state update rate of the @ref MoveBaseClient
 * @param strMapFrame The name of the global frame when path planning
 * @param bWaitForServer If true, then the function blocks until the movebase server is connected
 * @param strFromTopic  If strFromTopic is given, then the @ref MoveBaseClient will subscribe to that topic.
 */
void ControlInterface::SetMoveBaseClient(bool bSpinThread, int nUpdateRate, std::string strMapFrame, bool bWaitForServer, std::string strFromTopic)
{
	mpMBClient = new MoveBaseClient(bSpinThread, nUpdateRate, strMapFrame, bWaitForServer);

	if(strFromTopic.length() > 0)
	{
		mpMBClient->StartSubSimpleGoal(strFromTopic);
	}

	cout << "[ControlInterface] Set Move Base - Spin: " << bSpinThread << endl;
	cout << "[ControlInterface] Set Move Base - Rate: " << nUpdateRate << endl;
	cout << "[ControlInterface] Set Move Base - MapFrame: " << strMapFrame << endl;
	cout << "[ControlInterface] Set Move Base - Wait Server: " << bWaitForServer << endl;
	cout << "[ControlInterface] Set Move Base - SubControl: " << strFromTopic << endl;

	mbUseMoveBase = true;
}

/**
 * @brief The function that set the goal of the controller
 * @note The rotation is in Z-Y-X order
 * 
 * @param dx The x value (meter)
 * @param dy The y value (meter)
 * @param dz The z value (meter)
 * @param dOz The orientation z value (radius)
 * @param dOy The orientation y value (radius)
 * @param dOx The orientation x value (radius)
 */
void ControlInterface::SendGoalZYX(double dx, double dy, double dz, double dOz, double dOy, double dOx)
{
	if(mbUseMoveBase)
	{
		Eigen::Quaterniond q;
		q = Eigen::AngleAxisd(dOz, Eigen::Vector3d::UnitZ()) * 
		    Eigen::AngleAxisd(dOy, Eigen::Vector3d::UnitY()) * 
			Eigen::AngleAxisd(dOx, Eigen::Vector3d::UnitX());

		Eigen::Vector4d vCoeff = q.coeffs();
		std::cout << q.coeffs() << std::endl;
		mpMBClient->SendGoal(dx, dy, dz, vCoeff[0], vCoeff[1], vCoeff[2], vCoeff[3]);
	}
}

/**
 * @brief The function that set the goal of the controller
 * 
 * @param dx The x value (meter)
 * @param dy The y value (meter)
 * @param dz The z value (meter)
 * @param dQx The x value of quaternion
 * @param dQy The y value of quaternion
 * @param dQz The z value of quaternion
 * @param dQw The w value of quaternion
 */
void ControlInterface::SendGoalQuat(double dx, double dy, double dz, double dQx, double dQy, double dQz, double dQw)
{
	if(mbUseMoveBase)
	{
		mpMBClient->SendGoal(dx, dy, dz, dQx, dQy, dQz, dQw);
	}
}

/**
 * @brief The function that set the topic of the twist command
 * 
 * @param strCmdVelTopic The ROS topic name of twist command.
 */
void ControlInterface::SubControlFromTwist(string strCmdVelTopic)
{
	if(!strCmdVelTopic.empty())
	{
		this->vel_sub_ = this->nh_.subscribe(strCmdVelTopic, 1, &ControlInterface::CmdVelCb, this);
	}

	cout << "[ControlInterface] Twist Command Topic: " << strCmdVelTopic << endl;
}

/**
 * @brief The function that set the name of global and robot frame for pose tracking.
 * 
 * @param parent The name of global frame
 * @param child The name of robot frame
 */
void ControlInterface::SubPosFromTF(string parent, string child)
{
	if(!mbSubTF)
	{
		mbSubTF = true;
		mstrParent = parent;
		mstrChild = child;
		mpTFListener = new tf2_ros::TransformListener(mTFBuffer);
	}

	cout << "[ControlInterface] Set TF tree - Parent: " << mstrParent << endl;
	cout << "[ControlInterface] Set TF tree - Child: " << mstrChild << endl;
}

/**
 * @brief Get the position of robot from TF tree, you should call @ref SubPosFromTF() first
 * 
 * @param dx Output x value
 * @param dy Output y value
 * @param dz Output z value
 * @param dQx Output quaternion x value
 * @param dQy Output quaternion y value
 * @param dQz Output quaternion z value
 * @param dQw Output quaternion w value
 * @return true if the pose is available in TF tree
 * @return false if the pose is available in TF tree
 */
bool ControlInterface::GetPosQuatFromTF(double &dx, double &dy, double &dz, double &dQx, double &dQy, double &dQz, double &dQw)
{
	if(mbSubTF)
	{
		geometry_msgs::TransformStamped tfStamp;
		try
		{
			tfStamp = mTFBuffer.lookupTransform(mstrParent, mstrChild, ros::Time(0));
			dx = tfStamp.transform.translation.x;
			dy = tfStamp.transform.translation.y;
			dz = tfStamp.transform.translation.z;
			dQx = tfStamp.transform.rotation.x;
			dQy = tfStamp.transform.rotation.y;
			dQz = tfStamp.transform.rotation.z;
			dQw = tfStamp.transform.rotation.w;
			return true;
		}
		catch (tf2::TransformException ex)
		{
			return false;
		}
	}
	return false;
}

/**
 * @brief Get the position of robot from TF tree, you should call SubPosFromTF() first
 * 
 * @param dx Output x value
 * @param dy Output y value
 * @param dz Output z value
 * @param dOz Output orientation z value
 * @param dOy Output orientation y value
 * @param dOx Output orientation x value
 * @return true if the pose is available in TF tree
 * @return false if the pose is available in TF tree
 */
bool ControlInterface::GetPosZYXFromTF(double &dx, double &dy, double &dz, double &dOz, double &dOy, double &dOx)
{
	if(mbSubTF)
	{
		geometry_msgs::TransformStamped tfStamp;
		try
		{
			tfStamp = mTFBuffer.lookupTransform(mstrParent, mstrChild, ros::Time(0));

			tf2::Quaternion q(tfStamp.transform.rotation.x,
							tfStamp.transform.rotation.y,
							tfStamp.transform.rotation.z,
							tfStamp.transform.rotation.w);
			tf2::Matrix3x3 m(q);
			m.getEulerYPR(dOz, dOy, dOx);

			dx = tfStamp.transform.translation.x;
			dy = tfStamp.transform.translation.y;
			dz = tfStamp.transform.translation.z;
			return true;
		}
		catch (tf2::TransformException ex)
		{
			return false;
		}
	}
	return false;
}

/**
 * @brief The function that get the state of controller
 * 
 * @return string The moving state
 */
string ControlInterface::GetMovingState()
{
	if(mbUseMoveBase)
	{
		return mpMBClient->GetState();
	}
	return string("");
}

/**
 * @brief The callback function that send the twist command to robot
 * 
 * @param msg The ROS geometry_msgs::Twist message
 */
void ControlInterface::CmdVelCb(const geometry_msgs::TwistConstPtr &msg)
{
	mpAMR->SetVelocity(msg->linear.x, msg->angular.z);
	linear_x = msg->linear.x;
	angular_z = msg->angular.z;
}