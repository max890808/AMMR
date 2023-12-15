#include "Form_AMR.h"
#include <ui_Form_AMMR.h>
#include <Eigen/Geometry> 

Form_AMR::Form_AMR(Ui::Form_AMMR *_ui, QObject *parent):QObject(parent), torque_threshold(50)
{ 
    ui = _ui; 

	// Set Value
	int nSliderValue = ui->Control_Slider_FSpeed->value();
	string strRPM = to_string(nSliderValue)+" PRM";
	ui->Control_Label_FSpeed ->setText(QString::fromStdString(strRPM));

	ui->Control_Btn_LF->setShortcut(QKeySequence("Q"));
	ui->Control_Btn_SF->setShortcut(QKeySequence("W"));
	ui->Control_Btn_RF->setShortcut(QKeySequence("E"));
	ui->Control_Btn_LS->setShortcut(QKeySequence("A"));
	ui->Control_Btn_SS->setShortcut(QKeySequence("S"));
	ui->Control_Btn_RS->setShortcut(QKeySequence("D"));
	ui->Control_Btn_LB->setShortcut(QKeySequence("Z"));
	ui->Control_Btn_SB->setShortcut(QKeySequence("X"));
	ui->Control_Btn_RB->setShortcut(QKeySequence("C"));
}

void Form_AMR::on_AMRInfo_Btn_TorqueSwitch_clicked()
{
	bool bAMRState = mpAMR->GetExecuteState();
	if(bAMRState)
	{
		mpAMR->Stop();
	}
	else
	{
		mpAMR->Start();
	}
	
}

// Control Button
void Form_AMR::on_Control_Btn_LF_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Left_Forward, sliderPosition);
}

void Form_AMR::on_Control_Btn_SF_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Forward, sliderPosition);
}

void Form_AMR::on_Control_Btn_RF_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Right_Forward, sliderPosition);
}

void Form_AMR::on_Control_Btn_LS_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Left_Selfturn, sliderPosition);
}

void Form_AMR::on_Control_Btn_SS_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Pause, sliderPosition);
}

void Form_AMR::on_Control_Btn_RS_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Right_Selfturn, sliderPosition);
}

void Form_AMR::on_Control_Btn_LB_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Left_Backward, sliderPosition);	
}

void Form_AMR::on_Control_Btn_SB_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Backward, sliderPosition);
}

void Form_AMR::on_Control_Btn_RB_clicked()
{
	int sliderPosition = ui->Control_Slider_FSpeed->sliderPosition();
	mpAMR->SimpleControl(eSimpleControlMode::Right_Backward, sliderPosition);
}

void Form_AMR::on_Control_Slider_FSpeed_valueChanged(int nSliderValue)
{
	string strRPM = to_string(nSliderValue)+" PRM";
	ui->Control_Label_FSpeed ->setText(QString::fromStdString(strRPM));
}

// Diff Control Button
void Form_AMR::on_Diff_Btn_Go_clicked()
{
	bool bAngularOK;
	float fAngular = ui->Diff_LineEdit_Angular->text().toFloat(&bAngularOK);
	if(!bAngularOK)
	{
		ui->Diff_LineEdit_Angular->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		ui->Diff_LineEdit_Angular->setStyleSheet("background-color:rgb(255, 248, 252);");
	}

	bool bLinearOK;
	float fLinear = ui->Diff_LineEdit_Linear->text().toFloat(&bLinearOK);
	if(!bLinearOK)
	{
		ui->Diff_LineEdit_Linear->setStyleSheet("background-color:rgb(255, 125, 125);");
	}
	else
	{
		ui->Diff_LineEdit_Linear->setStyleSheet("background-color:rgb(255, 248, 252);");
	}

	if(bAngularOK && bLinearOK)
	{
		mpAMR->SetVelocity(fLinear, fAngular);
	}
}

void Form_AMR::on_Diff_Btn_Stop_clicked()
{
	ui->Diff_LineEdit_Angular->setText(QString("0")); 
	ui->Diff_LineEdit_Linear->setText(QString("0")); 
	mpAMR->SetVelocity(0, 0);
}

void Form_AMR::on_P2P_Btn_Go_clicked()
{
	bool bPosXOK;
	double dPosX = ui->P2P_LineEdit_X->text().toDouble(&bPosXOK);
	if(!bPosXOK)
	{
		ui->P2P_LineEdit_X->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		ui->P2P_LineEdit_X->setStyleSheet("background-color:rgb(255, 248, 252);");
	}

	bool bPosYOK;
	double dPosY = ui->P2P_LineEdit_Y->text().toDouble(&bPosYOK);
	if(!bPosYOK)
	{
		ui->P2P_LineEdit_Y->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		ui->P2P_LineEdit_Y->setStyleSheet("background-color:rgb(255, 248, 252);");
	}

	bool bOriZOK;
	double dOriZ = ui->P2P_LineEdit_Rotate->text().toDouble(&bOriZOK);
	if(!bOriZOK || (dOriZ <= -360 || dOriZ >= 360) )
	{
		bOriZOK = false;
		ui->P2P_LineEdit_Rotate->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		dOriZ = dOriZ * M_PI / 180;
		ui->P2P_LineEdit_Rotate->setStyleSheet("background-color:rgb(255, 248, 252);");
	}

	if(bPosXOK && bPosYOK && bOriZOK)
	{
		mpAMMR->mpControlInterface->SendGoalZYX(dPosX, dPosY, 0.0, dOriZ, 0.0, 0.0);
	}
}

void Form_AMR::on_Conveyor_btn_Put_clicked()
{
	bool velocityOK;
	double velocity = ui->Conveyor_lineEdit_Velocity->text().toDouble(&velocityOK);
	if(!velocityOK)
	{
		ui->Conveyor_lineEdit_Velocity->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		ui->Conveyor_lineEdit_Velocity->setStyleSheet("background-color:rgb(255, 248, 252);");
		mpAMR->Put(velocity);
	}
}

void Form_AMR::on_Conveyor_btn_Rot_clicked()
{
	bool angleOK;
	double angle = ui->Conveyor_lineEdit_Angle->text().toDouble(&angleOK);
	if(!angleOK)
	{
		ui->Conveyor_lineEdit_Angle->setStyleSheet("background-color: rgb(255, 125, 125);");
	}
	else
	{
		ui->Conveyor_lineEdit_Angle->setStyleSheet("background-color:rgb(255, 248, 252);");
		mpAMR->RotateConveyor(angle);
	}
}

void Form_AMR::Display()
{
	// Left, invert order
	int nLIdx = mpAMR->GetLeftIdx();
	ui->AMRInfo_Label_LeftID ->setText(QString::number(mpAMR->GetMotor_ID(nLIdx)));
	isOK(mpAMR->GetMotor_Connected(nLIdx), ui->AMRInfo_Label_LeftID );

	float nLeftAngle = mpAMR->GetMotor_PresentAngleSingleTurn(nLIdx);
	ui->AMRInfo_Label_LeftAngle->setText(QString::number(nLeftAngle, 'f', 2));

	float nLeftRPM = mpAMR->GetMotor_PresentVelocityRPM(nLIdx);
	ui->AMRInfo_Label_LeftVelocity->setText(QString::number(nLeftRPM, 'f', 2));

	// Right
	int nRIdx = mpAMR->GetRightIdx();
	ui->AMRInfo_Label_RightID->setText(QString::number(mpAMR->GetMotor_ID(nRIdx)));
	isOK(mpAMR->GetMotor_Connected(nRIdx), ui->AMRInfo_Label_RightID);

	float nRightAngle = mpAMR->GetMotor_PresentAngleSingleTurn(nRIdx);
	ui->AMRInfo_Label_RightAngle->setText(QString::number(nRightAngle, 'f', 2));

	float nRightRPM = mpAMR->GetMotor_PresentVelocityRPM(nRIdx);
	ui->AMRInfo_Label_RightVelocity->setText(QString::number(nRightRPM, 'f', 2));

	// Robot Velocity
	float fVelLinear, fVelAngular;
	mpAMR->GetVelocity(fVelLinear, fVelAngular);
	ui->VelInfo_Label_Angular->setText(QString::number(fVelAngular, 'f', 2));
	ui->VelInfo_Label_Linear->setText(QString::number(fVelLinear, 'f', 2));

	// Set button
	bool bAMRStop = !mpAMR->GetExecuteState();
	isOK(bAMRStop, ui->AMRInfo_Btn_TorqueSwitch);
	string strBtnText = bAMRStop?"ON":"OFF";
	ui->AMRInfo_Btn_TorqueSwitch->setText(QString::fromStdString(strBtnText));

	// Robot Position
	double dx, dy, dz, dOz, dOy, dOx;
	bool bGetPos = mpAMMR->mpControlInterface->GetPosZYXFromTF(dx, dy, dz, dOz, dOy, dOx);
	if(bGetPos)
	{
		dOz = dOz * 180 / M_PI;
		ui->Pos_Label_PosX->setText(QString::number(dx, 'f', 2));
		ui->Pos_Label_PosY->setText(QString::number(dy, 'f', 2));
		// ui->Pos_Label_PosZ->setText(QString::number(dz, 'f', 2));
		ui->Pos_Label_RotateZ->setText(QString::number(dOz, 'f', 2));
	}

	string strMovingState = mpAMMR->mpControlInterface->GetMovingState();
	if(strMovingState.length() > 0)
	{
		ui->Pos_Label_State->setText(QString::fromStdString(strMovingState));
	}
	
	if (mpAMMR->GetType() == eAMMRType::Type_AGV)
	{
		ui->Conveyor_btn_Rot->setEnabled(true);
		ui->Conveyor_btn_Put->setEnabled(true);
		ui->Conveyor_label_ID_1->setText(QString::number(mpAMR->GetMotor_ID(mpAMR->conveyor)));
		ui->Conveyor_label_ID_2->setText(QString::number(mpAMR->GetMotor_ID(mpAMR->conveyor_R)));
		isOK(mpAMR->GetMotor_Connected(mpAMR->conveyor), ui->Conveyor_label_ID_1);
		isOK(mpAMR->GetMotor_Connected(mpAMR->conveyor_R), ui->Conveyor_label_ID_2);
		ui->Conveyor_label_angle_1->setText(QString::number((int)mpAMR->GetMotor_PresentAngle(mpAMR->conveyor)));
		ui->Conveyor_label_angle_2->setText(QString::number((int)mpAMR->GetMotor_PresentAngle(mpAMR->conveyor_R)));
		ui->Conveyor_label_velocity_1->setText(QString::number((int)mpAMR->GetMotor_PresentVelocity(mpAMR->conveyor)));
		ui->Conveyor_label_velocity_2->setText(QString::number((int)mpAMR->GetMotor_PresentVelocity(mpAMR->conveyor_R)));
		ui->Conveyor_label_torque_1->setText(QString::number((int)mpAMR->GetMotor_PresentTorque(mpAMR->conveyor)));
		ui->Conveyor_label_torque_2->setText(QString::number((int)mpAMR->GetMotor_PresentTorque(mpAMR->conveyor_R)));
		isOK((abs(mpAMR->GetMotor_PresentTorque(mpAMR->conveyor)) < torque_threshold) ? true : false, ui->Conveyor_label_torque_1);
		isOK((abs(mpAMR->GetMotor_PresentTorque(mpAMR->conveyor_R)) < torque_threshold) ? true : false, ui->Conveyor_label_torque_2);
	}
	else 
	{
		ui->Conveyor_btn_Rot->setEnabled(false);
		ui->Conveyor_btn_Put->setEnabled(false);
	}
}

void Form_AMR::isOK(bool checked, QWidget *widget)
{
	if (checked == true)
		Checked(widget);
	else
		UnChecked(widget);
}

void Form_AMR::Checked(QWidget *widget)
{
	widget->setStyleSheet("background-color: rgb(125, 255, 125);");
}

void Form_AMR::UnChecked(QWidget *widget)
{
	widget->setStyleSheet("background-color: rgb(255, 125, 125);");
}
