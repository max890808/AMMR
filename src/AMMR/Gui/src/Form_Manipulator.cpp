#include "Form_Manipulator.h"
#include <ui_Form_AMMR.h>

int Form_Manipulator::time_tick_ = 0;

Form_Manipulator::Form_Manipulator(Ui::Form_AMMR *_ui, QObject *parent):QObject(parent), torque_threshold(50)
{
	ui = _ui;
}

void Form_Manipulator::on_Arm_btn_PosGo_clicked()
{
	const float ox = ui->Arm_lineEdit_Ox->text().toFloat();
	const float oy = ui->Arm_lineEdit_Oy->text().toFloat();
	const float oz = ui->Arm_lineEdit_Oz->text().toFloat();

	const float px = ui->Arm_lineEdit_X->text().toFloat();
	const float py = ui->Arm_lineEdit_Y->text().toFloat();
	const float pz = ui->Arm_lineEdit_Z->text().toFloat();

	mpManipulator->TrajectoryPlanning(ox, oy, oz, px, py, pz);
}


void Form_Manipulator::on_Arm_btn_RotGo_clicked()
{
	const float angle = ui->Arm_lineEdit_Angle->text().toFloat();
	
	mpManipulator->RotateSixArm(angle);
}

// void Form_Manipulator::on_Arm_btn_ImpedancePosGo_clicked()
// {
// 	const float om = ui->Arm_lineEdit_angularM->text().toFloat();
// 	const float ob = ui->Arm_lineEdit_angularB->text().toFloat();
// 	const float ok = ui->Arm_lineEdit_angularK->text().toFloat();

// 	const float pm = ui->Arm_lineEdit_linearM->text().toFloat();
// 	const float pb = ui->Arm_lineEdit_linearB->text().toFloat();
// 	const float pk = ui->Arm_lineEdit_linearK->text().toFloat();

// 	const float ox = ui->Arm_lineEdit_Ox->text().toFloat();
// 	const float oy = ui->Arm_lineEdit_Oy->text().toFloat();
// 	const float oz = ui->Arm_lineEdit_Oz->text().toFloat();

// 	const float px = ui->Arm_lineEdit_X->text().toFloat();
// 	const float py = ui->Arm_lineEdit_Y->text().toFloat();
// 	const float pz = ui->Arm_lineEdit_Z->text().toFloat();

// 	mpManipulator->ImpedanceControl(om, ob, ok, pm, pb, pk, ox, oy, oz, px, py, pz);
// }

void Form_Manipulator::on_Arm_btn_GripperOn_clicked()
{
	mpManipulator->PneumaticOn();
}

void Form_Manipulator::on_Arm_btn_GripperOff_clicked()
{
	mpManipulator->PneumaticOff();
}

void Form_Manipulator::on_Arm_btn_Start_clicked()
{
	mpManipulator->Start();
}

void Form_Manipulator::on_Arm_btn_Stop_clicked()
{
	mpManipulator->Stop();
}

void Form_Manipulator::Display()
{
	// Checl Robot Type. If robot type is AMR, not AMMR, then skip
	if(mpAMMR->GetType() != eAMMRType::Type_AMMR)
	{
		ui->Arm_btn_Start->setEnabled(false);
		ui->Arm_btn_Stop->setEnabled(false);
		ui->Arm_btn_PosGo->setEnabled(false);
		ui->Arm_btn_GripperOn->setEnabled(false);
		ui->Arm_btn_GripperOff->setEnabled(false);
		ui->Arm_btn_RotGo->setEnabled(false);
		return;
	}
	mpManipulator->CalculateJacobianMatrix();

	// time tick used to display animation
	time_tick_++;
	time_tick_ %= 20;

	// ID
	ui->Arm_label_ID_0->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 0)));
	ui->Arm_label_ID_1->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 1)));
	ui->Arm_label_ID_2->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 2)));
	ui->Arm_label_ID_3->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 3)));
	ui->Arm_label_ID_4->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 4)));
	ui->Arm_label_ID_5->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->FIRST_HAND_ID_ + 5)));
	ui->Arm_label_ID_6->setText(QString::number(mpManipulator->GetMotor_ID(mpManipulator->ROTATE_PLATFORM_ID_)));

	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 0), ui->Arm_label_ID_0);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 1), ui->Arm_label_ID_1);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 2), ui->Arm_label_ID_2);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 3), ui->Arm_label_ID_3);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 4), ui->Arm_label_ID_4);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->FIRST_HAND_ID_ + 5), ui->Arm_label_ID_5);
	isOK(mpManipulator->GetMotor_Connected(mpManipulator->ROTATE_PLATFORM_ID_), ui->Arm_label_ID_6);

	// Angle
	ui->Arm_label_angle_0->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 0)));
	ui->Arm_label_angle_1->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 1)));
	ui->Arm_label_angle_2->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 2)));
	ui->Arm_label_angle_3->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 3)));
	ui->Arm_label_angle_4->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 4)));
	ui->Arm_label_angle_5->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->FIRST_HAND_ID_ + 5)));
	ui->Arm_label_angle_6->setText(QString::number((int)mpManipulator->GetMotor_PresentAngle(mpManipulator->ROTATE_PLATFORM_ID_)));

	//Velocity
	ui->Arm_label_velocity_0->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 0)));
	ui->Arm_label_velocity_1->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 1)));
	ui->Arm_label_velocity_2->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 2)));
	ui->Arm_label_velocity_3->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 3)));
	ui->Arm_label_velocity_4->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 4)));
	ui->Arm_label_velocity_5->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->FIRST_HAND_ID_ + 5)));
	ui->Arm_label_velocity_6->setText(QString::number((int)mpManipulator->GetMotor_PresentVelocity(mpManipulator->ROTATE_PLATFORM_ID_)));

	// Torque
	ui->Arm_label_torque_0->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 0)));
	ui->Arm_label_torque_1->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 1)));
	ui->Arm_label_torque_2->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 2)));
	ui->Arm_label_torque_3->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 3)));
	ui->Arm_label_torque_4->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 4)));
	ui->Arm_label_torque_5->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 5)));
	ui->Arm_label_torque_6->setText(QString::number((int)mpManipulator->GetMotor_PresentTorque(mpManipulator->ROTATE_PLATFORM_ID_)));

	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 0)) < torque_threshold) ? true : false, ui->Arm_label_torque_0);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 1)) < torque_threshold) ? true : false, ui->Arm_label_torque_1);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 2)) < torque_threshold) ? true : false, ui->Arm_label_torque_2);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 3)) < torque_threshold) ? true : false, ui->Arm_label_torque_3);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 4)) < torque_threshold) ? true : false, ui->Arm_label_torque_4);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->FIRST_HAND_ID_ + 5)) < torque_threshold) ? true : false, ui->Arm_label_torque_5);
	isOK((abs(mpManipulator->GetMotor_PresentTorque(mpManipulator->ROTATE_PLATFORM_ID_)) < torque_threshold) ? true : false, ui->Arm_label_torque_6);

	// forward kinematics
	ui->Arm_label_currentPosX->setText(QString::number((int)mpManipulator->GetCurrentPosition(0)));
	ui->Arm_label_currentPosY->setText(QString::number((int)mpManipulator->GetCurrentPosition(1)));
	ui->Arm_label_currentPosZ->setText(QString::number((int)mpManipulator->GetCurrentPosition(2)));
	ui->Arm_label_currentRotX->setText(QString::number((int)mpManipulator->GetCurrentOrientation(0)));
	ui->Arm_label_currentRotY->setText(QString::number((int)mpManipulator->GetCurrentOrientation(1)));
	ui->Arm_label_currentRotZ->setText(QString::number((int)mpManipulator->GetCurrentOrientation(2)));

	if (mpManipulator->GetWorkingState())
	{
		/* Full description: "QWidget { background-color: rgb(255, 240, 240)}" */
		int rgb_value = 150 + time_tick_ * 5;
		std::string background_name = "QWidget { background-color: rgb(255, " + to_string(rgb_value) + ", " + to_string(rgb_value) + ")}";

		QMetaObject::invokeMethod(ui->Tab_Manipulator, "setStyleSheet", Qt::QueuedConnection, Q_ARG(QString, QString::fromStdString(background_name)));
	}
		
	else
		QMetaObject::invokeMethod(ui->Tab_Manipulator, "setStyleSheet", Qt::QueuedConnection, Q_ARG(QString, "QWidget { background-color: rgb(255, 255, 255)}"));
}

void Form_Manipulator::SetBtnState(bool bEnable)
{
	ui->Arm_btn_PosGo->setEnabled(bEnable);
	ui->Arm_btn_RotGo->setEnabled(bEnable);
	// ui->Arm_btn_ImpedancePosGo->setEnabled(bEnable);
	ui->Arm_btn_GripperOn->setEnabled(bEnable);
	ui->Arm_btn_GripperOff->setEnabled(bEnable);
	ui->Arm_btn_Stop->setEnabled(bEnable);
	ui->Arm_btn_Start->setEnabled(bEnable);
}

void Form_Manipulator::isOK(bool checked_thing, QLabel *label)
{
	if (checked_thing == true)
		Green(label);
	else
		Red(label);
}

void Form_Manipulator::Red(QLabel *label)
{
	QMetaObject::invokeMethod(label, "setStyleSheet", Qt::QueuedConnection, Q_ARG(QString, "QLabel { background-color: rgb(255, 60, 63)}"));
}

void Form_Manipulator::Green(QLabel *label)
{
	QMetaObject::invokeMethod(label, "setStyleSheet", Qt::QueuedConnection, Q_ARG(QString, "QLabel { background-color: rgb(170, 255, 127)}"));
}