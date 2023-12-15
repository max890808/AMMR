#include <Form_AMMR.h>
#include <ui_Form_AMMR.h>
#include <chrono>

using namespace std;

Form_AMMR::Form_AMMR(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::Form_AMMR),
	mnRobotType(eAMMRType::Type_AMMR)
{
	ui->setupUi(this);
	mpQThread_AMMR = new QThread();

	// AMR
	mpForm_AMR = new Form_AMR(ui);
	connect(ui->AMRInfo_Btn_TorqueSwitch, SIGNAL(clicked()), mpForm_AMR, SLOT(on_AMRInfo_Btn_TorqueSwitch_clicked()));
	connect(ui->Control_Btn_LF, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_LF_clicked()));
	connect(ui->Control_Btn_SF, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_SF_clicked()));
	connect(ui->Control_Btn_RF, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_RF_clicked()));
	connect(ui->Control_Btn_LS, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_LS_clicked()));
	connect(ui->Control_Btn_SS, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_SS_clicked()));
	connect(ui->Control_Btn_RS, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_RS_clicked()));
	connect(ui->Control_Btn_LB, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_LB_clicked()));
	connect(ui->Control_Btn_SB, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_SB_clicked()));
	connect(ui->Control_Btn_RB, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Control_Btn_RB_clicked()));
	connect(ui->Diff_Btn_Go, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Diff_Btn_Go_clicked()));
	connect(ui->Diff_Btn_Stop, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Diff_Btn_Stop_clicked()));
	connect(ui->P2P_Btn_Go, SIGNAL(clicked()), mpForm_AMR, SLOT(on_P2P_Btn_Go_clicked()));
	connect(ui->Conveyor_btn_Put, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Conveyor_btn_Put_clicked()));
	connect(ui->Conveyor_btn_Rot, SIGNAL(clicked()), mpForm_AMR, SLOT(on_Conveyor_btn_Rot_clicked()));
	connect(ui->Control_Slider_FSpeed, SIGNAL(valueChanged(int)), mpForm_AMR, SLOT(on_Control_Slider_FSpeed_valueChanged(int)));
	mpForm_AMR->moveToThread(mpQThread_AMMR);

	// Manipulator
	mpForm_Manipulator = new Form_Manipulator(ui);
	connect(ui->Arm_btn_PosGo, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_PosGo_clicked()));
	// connect(ui->Arm_btn_ImpedancePosGo, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_ImpedancePosGo_clicked()));
	connect(ui->Arm_btn_RotGo, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_RotGo_clicked()));
	connect(ui->Arm_btn_GripperOn, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_GripperOn_clicked()));
	connect(ui->Arm_btn_GripperOff, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_GripperOff_clicked()));
	connect(ui->Arm_btn_Start, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_Start_clicked()));
	connect(ui->Arm_btn_Stop, SIGNAL(clicked()), mpForm_Manipulator, SLOT(on_Arm_btn_Stop_clicked()));
	mpForm_Manipulator->moveToThread(mpQThread_AMMR);

	// Sensor
	mpForm_VLSensor = new Form_VLSensor(ui);
	connect(ui->LiDAR1_Btn_InvertZ, SIGNAL(toggled(bool)), mpForm_VLSensor, SLOT(on_LiDAR1_Btn_InvertZ_toggled(bool)));
	connect(ui->LiDAR1_Btn_ShowLines, SIGNAL(toggled(bool)), mpForm_VLSensor, SLOT(on_LiDAR1_Btn_ShowLines_toggled(bool)));
	connect(ui->LiDAR1_Slider_Range, SIGNAL(valueChanged(int)), mpForm_VLSensor, SLOT(on_LiDAR1_Slider_Range_valueChanged(int)));
	connect(ui->LiDAR2_Btn_InvertZ, SIGNAL(toggled(bool)), mpForm_VLSensor, SLOT(on_LiDAR2_Btn_InvertZ_toggled(bool)));
	connect(ui->LiDAR2_Btn_ShowLines, SIGNAL(toggled(bool)), mpForm_VLSensor, SLOT(on_LiDAR2_Btn_ShowLines_toggled(bool)));
	connect(ui->LiDAR2_Slider_Range, SIGNAL(valueChanged(int)), mpForm_VLSensor, SLOT(on_LiDAR2_Slider_Range_valueChanged(int)));
	mpForm_VLSensor->moveToThread(mpQThread_AMMR);

	mpQThread_AMMR->start();
}

Form_AMMR::~Form_AMMR()
{
	delete ui;
	delete mpAMMR;
}

void Form_AMMR::showEvent(QShowEvent *event)
{
	// Initialize Instance
	mpAMMR = AMMR::GetAMMR(mnRobotType);
	SetForm();

	mpTimerDisplay = new QTimer(this);
	connect(mpTimerDisplay, SIGNAL(timeout()), this, SLOT(Display()));
	mpTimerDisplay->start(30);
}

void Form_AMMR::closeEvent(QCloseEvent *event)
{
	delete mpTimerDisplay;
}

// Button Callback function
void Form_AMMR::on_AMMR_Btn_Reconnect_clicked()
{
	mpAMMR->Reconnect();
	mpForm_AMR->SetAMMR(mpAMMR);
}

void Form_AMMR::Display()
{
	if(mpAMMR != AMMR::GetAMMR())
	{
		SetForm();
	}		
	else if (ui->Tab_System->currentIndex() == 0)
	{
		mpForm_VLSensor->Display();
	}
	else if (ui->Tab_System->currentIndex() == 1)
	{
		mpForm_AMR->Display();
	}
	else if (ui->Tab_System->currentIndex() == 2)
	{
		mpForm_Manipulator->Display();
	}
	else
	{

	}
}

void Form_AMMR::SetRobotType(eAMMRType nRobotType)
{
	mnRobotType = nRobotType;
}

void Form_AMMR::SetForm()
{
	mpAMMR = AMMR::GetAMMR();
	mnRobotType = mpAMMR->GetType();
	if(mnRobotType==eAMMRType::Type_AMMR)
	{
		mpForm_Manipulator->SetBtnState(true);
	}
	else if(mnRobotType==eAMMRType::Type_AMR)
	{
		mpForm_Manipulator->SetBtnState(false);
	}

	mpForm_AMR->SetAMMR(mpAMMR);
	mpForm_Manipulator->SetAMMR(mpAMMR);
	mpForm_VLSensor->SetAMMR(mpAMMR);
}