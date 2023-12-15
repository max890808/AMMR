/********************************************************************************
** Form generated from reading UI file 'Form_AMMR.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_AMMR_H
#define UI_FORM_AMMR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_AMMR
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *Tab_System;
    QWidget *Tab_VLSensor;
    QGroupBox *Color_GroupBox;
    QGridLayout *gridLayout_6;
    QGraphicsView *Color_Graphics;
    QGroupBox *LiDAR1_GroupBox;
    QGridLayout *gridLayout_8;
    QSlider *LiDAR1_Slider_Range;
    QGraphicsView *LiDAR1_Graphics;
    QLabel *LiDAR1_Label_Range;
    QGroupBox *LiDAR2_GroupBox;
    QGridLayout *gridLayout_9;
    QSlider *LiDAR2_Slider_Range;
    QGraphicsView *LiDAR2_Graphics;
    QLabel *LiDAR2_Label_Range;
    QGroupBox *Depth_GroupBox;
    QGridLayout *gridLayout_11;
    QGraphicsView *Depth_Graphics;
    QRadioButton *LiDAR1_Btn_InvertZ;
    QRadioButton *LiDAR2_Btn_InvertZ;
    QTextBrowser *LiDAR1_Text_Info;
    QTextBrowser *LiDAR2_Text_Info;
    QTextBrowser *Color_Text_Info;
    QTextBrowser *Depth_Text_Info;
    QRadioButton *LiDAR1_Btn_ShowLines;
    QRadioButton *LiDAR2_Btn_ShowLines;
    QWidget *Tab_AMR;
    QGroupBox *Control_GroupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *Control_GridLayout;
    QTabWidget *Control_Label_AMR;
    QWidget *Tab_DiffControl;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLineEdit *Diff_LineEdit_Linear;
    QLabel *Diff_Label_Title_Top;
    QPushButton *Diff_Btn_Go;
    QPushButton *Diff_Btn_Stop;
    QLabel *Diff_Label_Title_Linear;
    QLabel *Diff_Label_Title_Angular;
    QLineEdit *Diff_LineEdit_Angular;
    QFrame *line_2;
    QWidget *Tab_KeyBoard;
    QWidget *gridLayoutWidget_3;
    QGridLayout *KeyBoard_GridLayout;
    QPushButton *Control_Btn_RB;
    QPushButton *Control_Btn_LB;
    QSlider *Control_Slider_FSpeed;
    QPushButton *Control_Btn_RF;
    QPushButton *Control_Btn_LF;
    QLabel *Control_Label_FSpeed;
    QPushButton *Control_Btn_RS;
    QPushButton *Control_Btn_LS;
    QPushButton *Control_Btn_SB;
    QPushButton *Control_Btn_SF;
    QPushButton *Control_Btn_SS;
    QFrame *line;
    QGroupBox *Pos_GroupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *Pos_GridLayout;
    QLabel *Pos_Label_RotateX;
    QLabel *Pos_Label_Title_Y;
    QLabel *Pos_Label_Title_Pos;
    QLabel *Pos_Label_PosY;
    QLabel *Pos_Label_RotateZ;
    QLabel *Pos_Label_PosZ;
    QLabel *Pos_Label_Title_X;
    QLabel *Pos_Label_Title_Rotate;
    QLabel *Pos_Label_RotateY;
    QLabel *Pos_Label_PosX;
    QLabel *Pos_Label_Title_Z;
    QPushButton *P2P_Btn_Go;
    QLineEdit *P2P_LineEdit_X;
    QLineEdit *P2P_LineEdit_Y;
    QLineEdit *P2P_LineEdit_Rotate;
    QLabel *Pos_Label_State;
    QGroupBox *AMRInfo_GroupBox;
    QGridLayout *gridLayout_7;
    QGridLayout *AMRInfo_GridLayout;
    QLabel *AMRInfo_Label_LeftVelocity;
    QLabel *VelInfo_Label_Linear;
    QLabel *AMRInfo_Label_LeftMotor;
    QLabel *VelInfo_Label_Title_Linear;
    QLabel *AMRInfo_Label_Angle;
    QLabel *AMRInfo_Label_RightAngle;
    QLabel *VelInfo_Label_Title_Angular;
    QLabel *AMRInfo_Label_Velocity;
    QLabel *VelInfo_Label_Title_Top;
    QLabel *AMRInfo_Label_RightMotor;
    QLabel *AMRInfo_Label_RightVelocity;
    QLabel *AMRInfo_Label_LeftAngle;
    QPushButton *AMRInfo_Btn_TorqueSwitch;
    QLabel *AMRInfo_Label_LeftID;
    QLabel *VelInfo_Label_Angular;
    QLabel *AMRInfo_Label_RightID;
    QFrame *AMRInfo_Line_Spacer;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGraphicsView *MAP_graphics_small;
    QWidget *tab_4;
    QWidget *layoutWidget_5;
    QGridLayout *Conveyor_GridLayout;
    QLineEdit *Conveyor_lineEdit_Angle;
    QLabel *Conveyor_label_title_velocity;
    QLabel *Conveyor_label_title_torque;
    QLabel *Conveyor_label_velocity_1;
    QLabel *Conveyor_label_angle_1;
    QLabel *Conveyor_label_ID_1;
    QLabel *Conveyor_label_torque_1;
    QLabel *Conveyor_label_title_angle;
    QLabel *Conveyor_label_ID_2;
    QLabel *Conveyor_label_angle_2;
    QLabel *Conveyor_label_velocity_2;
    QLineEdit *Conveyor_lineEdit_Velocity;
    QLabel *Conveyor_label_torque_2;
    QPushButton *Conveyor_btn_Rot;
    QPushButton *Conveyor_btn_Put;
    QWidget *Tab_Manipulator;
    QGroupBox *ArmMotorInfo_GroupBox;
    QWidget *gridLayoutWidget_6;
    QGridLayout *Arm_GridLayout;
    QLabel *Arm_label_velocity_3;
    QLabel *Arm_label_torque_3;
    QLabel *Arm_label_angle_3;
    QLabel *Arm_label_angle_5;
    QLabel *Arm_label_title_torque;
    QLabel *Arm_label_ID_3;
    QLabel *Arm_label_torque_2;
    QLabel *Arm_label_ID_4;
    QLabel *Arm_label_angle_1;
    QLabel *Arm_label_torque_5;
    QLabel *Arm_label_torque_1;
    QLabel *Arm_label_velocity_1;
    QLabel *Arm_label_angle_0;
    QLabel *Arm_label_angle_2;
    QLabel *Arm_label_ID_1;
    QLabel *Arm_label_torque_4;
    QLabel *Arm_label_ID_2;
    QLabel *Arm_label_torque_0;
    QLabel *Arm_label_velocity_0;
    QLabel *Arm_label_ID_5;
    QLabel *Arm_label_velocity_2;
    QLabel *Arm_label_ID_0;
    QLabel *Arm_label_angle_4;
    QLabel *Arm_label_velocity_4;
    QLabel *Arm_label_velocity_5;
    QLabel *Arm_label_title_velocity;
    QLabel *Arm_label_title_angle;
    QGroupBox *ArmPosition_GroupBox;
    QWidget *gridLayoutWidget_7;
    QGridLayout *Arm_GridLayout_Pos;
    QLabel *Arm_label_title_currentRot;
    QLabel *Arm_label_currentPosY;
    QLabel *Arm_label_title_currentPos;
    QLabel *Arm_label_title_currentZ;
    QLabel *Arm_label_currentRotY;
    QLabel *Arm_label_currentRotZ;
    QLabel *Arm_label_title_currentY;
    QLabel *Arm_label_currentPosX;
    QLabel *Arm_label_title_currentX;
    QLabel *Arm_label_currentPosZ;
    QLabel *Arm_label_currentRotX;
    QWidget *layoutWidget_3;
    QGridLayout *Arm_GridLayout_Control;
    QLineEdit *Arm_lineEdit_Oz;
    QLabel *Arm_label_title_controlY;
    QLabel *Arm_label_title_controlPos;
    QLabel *Arm_label_title_controlX;
    QLineEdit *Arm_lineEdit_Y;
    QLineEdit *Arm_lineEdit_Z;
    QLineEdit *Arm_lineEdit_Oy;
    QLineEdit *Arm_lineEdit_Ox;
    QLabel *Arm_label_title_controlZ;
    QLineEdit *Arm_lineEdit_X;
    QLabel *Arm_label_title_controlRot;
    QWidget *layoutWidget;
    QVBoxLayout *Arm_VerticalLayout_Control;
    QPushButton *Arm_btn_Start;
    QPushButton *Arm_btn_Stop;
    QPushButton *Arm_btn_PosGo;
    QGroupBox *ArmRotation_GroupBox;
    QWidget *layoutWidget_4;
    QGridLayout *Arm_GridLayout_Rot;
    QLabel *Arm_label_title_velocity_2;
    QLabel *Arm_label_title_armRot;
    QLineEdit *Arm_lineEdit_Angle;
    QLabel *Arm_label_ID_6;
    QLabel *Arm_label_velocity_6;
    QLabel *Arm_label_torque_6;
    QLabel *Arm_label_angle_6;
    QLabel *Arm_label_title_angle_2;
    QLabel *Arm_label_title_torque_2;
    QPushButton *Arm_btn_RotGo;
    QGroupBox *Gripper_GroupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *Gripper_VerticalLayout;
    QPushButton *Arm_btn_GripperOn;
    QPushButton *Arm_btn_GripperOff;
    QPushButton *AMMR_Btn_Reconnect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Form_AMMR)
    {
        if (Form_AMMR->objectName().isEmpty())
            Form_AMMR->setObjectName(QStringLiteral("Form_AMMR"));
        Form_AMMR->resize(917, 690);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form_AMMR->sizePolicy().hasHeightForWidth());
        Form_AMMR->setSizePolicy(sizePolicy);
        Form_AMMR->setMinimumSize(QSize(0, 690));
        Form_AMMR->setMaximumSize(QSize(2000, 690));
        Form_AMMR->setBaseSize(QSize(0, 1));
        QFont font;
        font.setPointSize(11);
        Form_AMMR->setFont(font);
        centralwidget = new QWidget(Form_AMMR);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Tab_System = new QTabWidget(centralwidget);
        Tab_System->setObjectName(QStringLiteral("Tab_System"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Tab_System->sizePolicy().hasHeightForWidth());
        Tab_System->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        Tab_System->setFont(font1);
        Tab_System->setLayoutDirection(Qt::LeftToRight);
        Tab_System->setAutoFillBackground(false);
        Tab_System->setStyleSheet(QStringLiteral(""));
        Tab_System->setIconSize(QSize(16, 16));
        Tab_VLSensor = new QWidget();
        Tab_VLSensor->setObjectName(QStringLiteral("Tab_VLSensor"));
        Color_GroupBox = new QGroupBox(Tab_VLSensor);
        Color_GroupBox->setObjectName(QStringLiteral("Color_GroupBox"));
        Color_GroupBox->setGeometry(QRect(430, 0, 341, 291));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        Color_GroupBox->setFont(font2);
        Color_GroupBox->setAutoFillBackground(false);
        gridLayout_6 = new QGridLayout(Color_GroupBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Color_Graphics = new QGraphicsView(Color_GroupBox);
        Color_Graphics->setObjectName(QStringLiteral("Color_Graphics"));
        sizePolicy.setHeightForWidth(Color_Graphics->sizePolicy().hasHeightForWidth());
        Color_Graphics->setSizePolicy(sizePolicy);
        Color_Graphics->setMinimumSize(QSize(320, 240));
        Color_Graphics->setMaximumSize(QSize(320, 240));
        Color_Graphics->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Color_Graphics->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_6->addWidget(Color_Graphics, 0, 0, 1, 1);

        LiDAR1_GroupBox = new QGroupBox(Tab_VLSensor);
        LiDAR1_GroupBox->setObjectName(QStringLiteral("LiDAR1_GroupBox"));
        LiDAR1_GroupBox->setGeometry(QRect(10, 0, 281, 291));
        LiDAR1_GroupBox->setFont(font2);
        LiDAR1_GroupBox->setAutoFillBackground(false);
        gridLayout_8 = new QGridLayout(LiDAR1_GroupBox);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        LiDAR1_Slider_Range = new QSlider(LiDAR1_GroupBox);
        LiDAR1_Slider_Range->setObjectName(QStringLiteral("LiDAR1_Slider_Range"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(LiDAR1_Slider_Range->sizePolicy().hasHeightForWidth());
        LiDAR1_Slider_Range->setSizePolicy(sizePolicy3);
        LiDAR1_Slider_Range->setMinimumSize(QSize(190, 0));
        LiDAR1_Slider_Range->setMaximumSize(QSize(190, 16777215));
        LiDAR1_Slider_Range->setMinimum(1);
        LiDAR1_Slider_Range->setMaximum(60);
        LiDAR1_Slider_Range->setPageStep(1);
        LiDAR1_Slider_Range->setOrientation(Qt::Horizontal);
        LiDAR1_Slider_Range->setInvertedControls(true);

        gridLayout_8->addWidget(LiDAR1_Slider_Range, 0, 0, 1, 1);

        LiDAR1_Graphics = new QGraphicsView(LiDAR1_GroupBox);
        LiDAR1_Graphics->setObjectName(QStringLiteral("LiDAR1_Graphics"));
        sizePolicy.setHeightForWidth(LiDAR1_Graphics->sizePolicy().hasHeightForWidth());
        LiDAR1_Graphics->setSizePolicy(sizePolicy);
        LiDAR1_Graphics->setMinimumSize(QSize(210, 210));
        LiDAR1_Graphics->setMaximumSize(QSize(210, 210));
        LiDAR1_Graphics->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LiDAR1_Graphics->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_8->addWidget(LiDAR1_Graphics, 1, 0, 1, 1);

        LiDAR1_Label_Range = new QLabel(LiDAR1_GroupBox);
        LiDAR1_Label_Range->setObjectName(QStringLiteral("LiDAR1_Label_Range"));
        QFont font3;
        font3.setPointSize(12);
        LiDAR1_Label_Range->setFont(font3);

        gridLayout_8->addWidget(LiDAR1_Label_Range, 0, 1, 1, 1);

        LiDAR2_GroupBox = new QGroupBox(Tab_VLSensor);
        LiDAR2_GroupBox->setObjectName(QStringLiteral("LiDAR2_GroupBox"));
        LiDAR2_GroupBox->setGeometry(QRect(10, 290, 281, 291));
        LiDAR2_GroupBox->setFont(font2);
        LiDAR2_GroupBox->setAutoFillBackground(false);
        gridLayout_9 = new QGridLayout(LiDAR2_GroupBox);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        LiDAR2_Slider_Range = new QSlider(LiDAR2_GroupBox);
        LiDAR2_Slider_Range->setObjectName(QStringLiteral("LiDAR2_Slider_Range"));
        sizePolicy3.setHeightForWidth(LiDAR2_Slider_Range->sizePolicy().hasHeightForWidth());
        LiDAR2_Slider_Range->setSizePolicy(sizePolicy3);
        LiDAR2_Slider_Range->setMinimumSize(QSize(190, 0));
        LiDAR2_Slider_Range->setMaximumSize(QSize(190, 16777215));
        LiDAR2_Slider_Range->setMinimum(1);
        LiDAR2_Slider_Range->setMaximum(60);
        LiDAR2_Slider_Range->setPageStep(1);
        LiDAR2_Slider_Range->setOrientation(Qt::Horizontal);
        LiDAR2_Slider_Range->setInvertedControls(true);

        gridLayout_9->addWidget(LiDAR2_Slider_Range, 0, 0, 1, 1);

        LiDAR2_Graphics = new QGraphicsView(LiDAR2_GroupBox);
        LiDAR2_Graphics->setObjectName(QStringLiteral("LiDAR2_Graphics"));
        sizePolicy.setHeightForWidth(LiDAR2_Graphics->sizePolicy().hasHeightForWidth());
        LiDAR2_Graphics->setSizePolicy(sizePolicy);
        LiDAR2_Graphics->setMinimumSize(QSize(210, 210));
        LiDAR2_Graphics->setMaximumSize(QSize(210, 210));
        LiDAR2_Graphics->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LiDAR2_Graphics->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_9->addWidget(LiDAR2_Graphics, 1, 0, 1, 1);

        LiDAR2_Label_Range = new QLabel(LiDAR2_GroupBox);
        LiDAR2_Label_Range->setObjectName(QStringLiteral("LiDAR2_Label_Range"));
        LiDAR2_Label_Range->setFont(font3);

        gridLayout_9->addWidget(LiDAR2_Label_Range, 0, 1, 1, 1);

        Depth_GroupBox = new QGroupBox(Tab_VLSensor);
        Depth_GroupBox->setObjectName(QStringLiteral("Depth_GroupBox"));
        Depth_GroupBox->setGeometry(QRect(430, 290, 341, 291));
        Depth_GroupBox->setFont(font2);
        Depth_GroupBox->setAutoFillBackground(false);
        gridLayout_11 = new QGridLayout(Depth_GroupBox);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        Depth_Graphics = new QGraphicsView(Depth_GroupBox);
        Depth_Graphics->setObjectName(QStringLiteral("Depth_Graphics"));
        sizePolicy.setHeightForWidth(Depth_Graphics->sizePolicy().hasHeightForWidth());
        Depth_Graphics->setSizePolicy(sizePolicy);
        Depth_Graphics->setMinimumSize(QSize(320, 240));
        Depth_Graphics->setMaximumSize(QSize(320, 240));
        Depth_Graphics->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Depth_Graphics->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_11->addWidget(Depth_Graphics, 0, 0, 1, 1);

        LiDAR1_Btn_InvertZ = new QRadioButton(Tab_VLSensor);
        LiDAR1_Btn_InvertZ->setObjectName(QStringLiteral("LiDAR1_Btn_InvertZ"));
        LiDAR1_Btn_InvertZ->setGeometry(QRect(300, 30, 112, 23));
        LiDAR1_Btn_InvertZ->setChecked(true);
        LiDAR1_Btn_InvertZ->setAutoExclusive(false);
        LiDAR2_Btn_InvertZ = new QRadioButton(Tab_VLSensor);
        LiDAR2_Btn_InvertZ->setObjectName(QStringLiteral("LiDAR2_Btn_InvertZ"));
        LiDAR2_Btn_InvertZ->setEnabled(true);
        LiDAR2_Btn_InvertZ->setGeometry(QRect(300, 320, 112, 23));
        LiDAR2_Btn_InvertZ->setCheckable(true);
        LiDAR2_Btn_InvertZ->setChecked(true);
        LiDAR2_Btn_InvertZ->setAutoRepeat(false);
        LiDAR2_Btn_InvertZ->setAutoExclusive(false);
        LiDAR1_Text_Info = new QTextBrowser(Tab_VLSensor);
        LiDAR1_Text_Info->setObjectName(QStringLiteral("LiDAR1_Text_Info"));
        LiDAR1_Text_Info->setGeometry(QRect(300, 80, 121, 211));
        LiDAR2_Text_Info = new QTextBrowser(Tab_VLSensor);
        LiDAR2_Text_Info->setObjectName(QStringLiteral("LiDAR2_Text_Info"));
        LiDAR2_Text_Info->setGeometry(QRect(300, 370, 121, 211));
        Color_Text_Info = new QTextBrowser(Tab_VLSensor);
        Color_Text_Info->setObjectName(QStringLiteral("Color_Text_Info"));
        Color_Text_Info->setGeometry(QRect(780, 30, 121, 261));
        Depth_Text_Info = new QTextBrowser(Tab_VLSensor);
        Depth_Text_Info->setObjectName(QStringLiteral("Depth_Text_Info"));
        Depth_Text_Info->setGeometry(QRect(780, 320, 121, 261));
        LiDAR1_Btn_ShowLines = new QRadioButton(Tab_VLSensor);
        LiDAR1_Btn_ShowLines->setObjectName(QStringLiteral("LiDAR1_Btn_ShowLines"));
        LiDAR1_Btn_ShowLines->setGeometry(QRect(300, 50, 112, 23));
        LiDAR1_Btn_ShowLines->setChecked(true);
        LiDAR1_Btn_ShowLines->setAutoExclusive(false);
        LiDAR2_Btn_ShowLines = new QRadioButton(Tab_VLSensor);
        LiDAR2_Btn_ShowLines->setObjectName(QStringLiteral("LiDAR2_Btn_ShowLines"));
        LiDAR2_Btn_ShowLines->setGeometry(QRect(300, 340, 112, 23));
        LiDAR2_Btn_ShowLines->setChecked(true);
        LiDAR2_Btn_ShowLines->setAutoExclusive(false);
        Tab_System->addTab(Tab_VLSensor, QString());
        Tab_AMR = new QWidget();
        Tab_AMR->setObjectName(QStringLiteral("Tab_AMR"));
        Control_GroupBox = new QGroupBox(Tab_AMR);
        Control_GroupBox->setObjectName(QStringLiteral("Control_GroupBox"));
        Control_GroupBox->setGeometry(QRect(10, 10, 431, 331));
        Control_GroupBox->setFont(font2);
        gridLayout_4 = new QGridLayout(Control_GroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(24);
        Control_GridLayout = new QGridLayout();
        Control_GridLayout->setSpacing(0);
        Control_GridLayout->setObjectName(QStringLiteral("Control_GridLayout"));
        Control_GridLayout->setContentsMargins(-1, 0, -1, 0);
        Control_Label_AMR = new QTabWidget(Control_GroupBox);
        Control_Label_AMR->setObjectName(QStringLiteral("Control_Label_AMR"));
        Tab_DiffControl = new QWidget();
        Tab_DiffControl->setObjectName(QStringLiteral("Tab_DiffControl"));
        gridLayoutWidget_2 = new QWidget(Tab_DiffControl);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 401, 241));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Diff_LineEdit_Linear = new QLineEdit(gridLayoutWidget_2);
        Diff_LineEdit_Linear->setObjectName(QStringLiteral("Diff_LineEdit_Linear"));
        Diff_LineEdit_Linear->setMinimumSize(QSize(0, 0));
        Diff_LineEdit_Linear->setMaximumSize(QSize(90, 90));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        Diff_LineEdit_Linear->setFont(font4);
        Diff_LineEdit_Linear->setLayoutDirection(Qt::LeftToRight);
        Diff_LineEdit_Linear->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Diff_LineEdit_Linear->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Diff_LineEdit_Linear, 3, 1, 1, 1);

        Diff_Label_Title_Top = new QLabel(gridLayoutWidget_2);
        Diff_Label_Title_Top->setObjectName(QStringLiteral("Diff_Label_Title_Top"));
        Diff_Label_Title_Top->setMinimumSize(QSize(300, 70));
        Diff_Label_Title_Top->setMaximumSize(QSize(300, 70));
        Diff_Label_Title_Top->setFont(font1);
        Diff_Label_Title_Top->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Diff_Label_Title_Top->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Diff_Label_Title_Top, 0, 0, 1, 3);

        Diff_Btn_Go = new QPushButton(gridLayoutWidget_2);
        Diff_Btn_Go->setObjectName(QStringLiteral("Diff_Btn_Go"));
        sizePolicy.setHeightForWidth(Diff_Btn_Go->sizePolicy().hasHeightForWidth());
        Diff_Btn_Go->setSizePolicy(sizePolicy);
        Diff_Btn_Go->setMinimumSize(QSize(80, 50));
        Diff_Btn_Go->setMaximumSize(QSize(80, 60));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        Diff_Btn_Go->setFont(font5);
        Diff_Btn_Go->setStyleSheet(QStringLiteral("background-color: rgb(125, 255, 125);"));

        gridLayout->addWidget(Diff_Btn_Go, 2, 2, 1, 1);

        Diff_Btn_Stop = new QPushButton(gridLayoutWidget_2);
        Diff_Btn_Stop->setObjectName(QStringLiteral("Diff_Btn_Stop"));
        sizePolicy.setHeightForWidth(Diff_Btn_Stop->sizePolicy().hasHeightForWidth());
        Diff_Btn_Stop->setSizePolicy(sizePolicy);
        Diff_Btn_Stop->setMinimumSize(QSize(80, 50));
        Diff_Btn_Stop->setMaximumSize(QSize(80, 60));
        Diff_Btn_Stop->setFont(font5);
        Diff_Btn_Stop->setStyleSheet(QStringLiteral("background-color: rgb(255, 125, 125);"));

        gridLayout->addWidget(Diff_Btn_Stop, 3, 2, 1, 1);

        Diff_Label_Title_Linear = new QLabel(gridLayoutWidget_2);
        Diff_Label_Title_Linear->setObjectName(QStringLiteral("Diff_Label_Title_Linear"));
        Diff_Label_Title_Linear->setMinimumSize(QSize(80, 50));
        Diff_Label_Title_Linear->setMaximumSize(QSize(80, 70));
        Diff_Label_Title_Linear->setFont(font1);
        Diff_Label_Title_Linear->setLayoutDirection(Qt::LeftToRight);
        Diff_Label_Title_Linear->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Diff_Label_Title_Linear->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Diff_Label_Title_Linear, 3, 0, 1, 1);

        Diff_Label_Title_Angular = new QLabel(gridLayoutWidget_2);
        Diff_Label_Title_Angular->setObjectName(QStringLiteral("Diff_Label_Title_Angular"));
        Diff_Label_Title_Angular->setMinimumSize(QSize(80, 50));
        Diff_Label_Title_Angular->setMaximumSize(QSize(80, 70));
        QFont font6;
        font6.setFamily(QStringLiteral("Ubuntu"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        Diff_Label_Title_Angular->setFont(font6);
        Diff_Label_Title_Angular->setLayoutDirection(Qt::LeftToRight);
        Diff_Label_Title_Angular->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Diff_Label_Title_Angular->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Diff_Label_Title_Angular, 2, 0, 1, 1);

        Diff_LineEdit_Angular = new QLineEdit(gridLayoutWidget_2);
        Diff_LineEdit_Angular->setObjectName(QStringLiteral("Diff_LineEdit_Angular"));
        Diff_LineEdit_Angular->setMinimumSize(QSize(0, 0));
        Diff_LineEdit_Angular->setMaximumSize(QSize(90, 90));
        Diff_LineEdit_Angular->setFont(font4);
        Diff_LineEdit_Angular->setLayoutDirection(Qt::LeftToRight);
        Diff_LineEdit_Angular->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Diff_LineEdit_Angular->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Diff_LineEdit_Angular, 2, 1, 1, 1);

        line_2 = new QFrame(gridLayoutWidget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 3);

        Control_Label_AMR->addTab(Tab_DiffControl, QString());
        Tab_KeyBoard = new QWidget();
        Tab_KeyBoard->setObjectName(QStringLiteral("Tab_KeyBoard"));
        gridLayoutWidget_3 = new QWidget(Tab_KeyBoard);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 401, 241));
        KeyBoard_GridLayout = new QGridLayout(gridLayoutWidget_3);
        KeyBoard_GridLayout->setObjectName(QStringLiteral("KeyBoard_GridLayout"));
        KeyBoard_GridLayout->setContentsMargins(0, 0, 0, 0);
        Control_Btn_RB = new QPushButton(gridLayoutWidget_3);
        Control_Btn_RB->setObjectName(QStringLiteral("Control_Btn_RB"));
        Control_Btn_RB->setMinimumSize(QSize(120, 50));
        Control_Btn_RB->setMaximumSize(QSize(120, 60));
        Control_Btn_RB->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/control/images/Back_Right.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_RB->setIcon(icon);
        Control_Btn_RB->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_RB, 4, 2, 1, 1);

        Control_Btn_LB = new QPushButton(gridLayoutWidget_3);
        Control_Btn_LB->setObjectName(QStringLiteral("Control_Btn_LB"));
        sizePolicy3.setHeightForWidth(Control_Btn_LB->sizePolicy().hasHeightForWidth());
        Control_Btn_LB->setSizePolicy(sizePolicy3);
        Control_Btn_LB->setMinimumSize(QSize(120, 50));
        Control_Btn_LB->setMaximumSize(QSize(120, 60));
        Control_Btn_LB->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/control/images/Back_Left.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_LB->setIcon(icon1);
        Control_Btn_LB->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_LB, 4, 0, 1, 1);

        Control_Slider_FSpeed = new QSlider(gridLayoutWidget_3);
        Control_Slider_FSpeed->setObjectName(QStringLiteral("Control_Slider_FSpeed"));
        Control_Slider_FSpeed->setMinimum(1);
        Control_Slider_FSpeed->setMaximum(30);
        Control_Slider_FSpeed->setPageStep(1);
        Control_Slider_FSpeed->setOrientation(Qt::Horizontal);
        Control_Slider_FSpeed->setInvertedControls(true);

        KeyBoard_GridLayout->addWidget(Control_Slider_FSpeed, 0, 0, 1, 2);

        Control_Btn_RF = new QPushButton(gridLayoutWidget_3);
        Control_Btn_RF->setObjectName(QStringLiteral("Control_Btn_RF"));
        Control_Btn_RF->setMinimumSize(QSize(120, 50));
        Control_Btn_RF->setMaximumSize(QSize(120, 60));
        Control_Btn_RF->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/control/images/For_Right.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_RF->setIcon(icon2);
        Control_Btn_RF->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_RF, 2, 2, 1, 1);

        Control_Btn_LF = new QPushButton(gridLayoutWidget_3);
        Control_Btn_LF->setObjectName(QStringLiteral("Control_Btn_LF"));
        sizePolicy3.setHeightForWidth(Control_Btn_LF->sizePolicy().hasHeightForWidth());
        Control_Btn_LF->setSizePolicy(sizePolicy3);
        Control_Btn_LF->setMinimumSize(QSize(120, 50));
        Control_Btn_LF->setMaximumSize(QSize(120, 60));
        Control_Btn_LF->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/control/images/For_Left.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_LF->setIcon(icon3);
        Control_Btn_LF->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_LF, 2, 0, 1, 1);

        Control_Label_FSpeed = new QLabel(gridLayoutWidget_3);
        Control_Label_FSpeed->setObjectName(QStringLiteral("Control_Label_FSpeed"));
        sizePolicy.setHeightForWidth(Control_Label_FSpeed->sizePolicy().hasHeightForWidth());
        Control_Label_FSpeed->setSizePolicy(sizePolicy);
        Control_Label_FSpeed->setMinimumSize(QSize(100, 20));
        Control_Label_FSpeed->setMaximumSize(QSize(100, 20));

        KeyBoard_GridLayout->addWidget(Control_Label_FSpeed, 0, 2, 1, 1);

        Control_Btn_RS = new QPushButton(gridLayoutWidget_3);
        Control_Btn_RS->setObjectName(QStringLiteral("Control_Btn_RS"));
        Control_Btn_RS->setMinimumSize(QSize(120, 50));
        Control_Btn_RS->setMaximumSize(QSize(120, 60));
        Control_Btn_RS->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/control/images/Self_Right.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_RS->setIcon(icon4);
        Control_Btn_RS->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_RS, 3, 2, 1, 1);

        Control_Btn_LS = new QPushButton(gridLayoutWidget_3);
        Control_Btn_LS->setObjectName(QStringLiteral("Control_Btn_LS"));
        sizePolicy3.setHeightForWidth(Control_Btn_LS->sizePolicy().hasHeightForWidth());
        Control_Btn_LS->setSizePolicy(sizePolicy3);
        Control_Btn_LS->setMinimumSize(QSize(120, 50));
        Control_Btn_LS->setMaximumSize(QSize(120, 60));
        Control_Btn_LS->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/control/images/Self_Left.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_LS->setIcon(icon5);
        Control_Btn_LS->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_LS, 3, 0, 1, 1);

        Control_Btn_SB = new QPushButton(gridLayoutWidget_3);
        Control_Btn_SB->setObjectName(QStringLiteral("Control_Btn_SB"));
        Control_Btn_SB->setMinimumSize(QSize(120, 50));
        Control_Btn_SB->setMaximumSize(QSize(120, 60));
        Control_Btn_SB->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/control/images/Backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_SB->setIcon(icon6);
        Control_Btn_SB->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_SB, 4, 1, 1, 1);

        Control_Btn_SF = new QPushButton(gridLayoutWidget_3);
        Control_Btn_SF->setObjectName(QStringLiteral("Control_Btn_SF"));
        Control_Btn_SF->setMinimumSize(QSize(120, 50));
        Control_Btn_SF->setMaximumSize(QSize(120, 60));
        Control_Btn_SF->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/control/images/Forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_SF->setIcon(icon7);
        Control_Btn_SF->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_SF, 2, 1, 1, 1);

        Control_Btn_SS = new QPushButton(gridLayoutWidget_3);
        Control_Btn_SS->setObjectName(QStringLiteral("Control_Btn_SS"));
        Control_Btn_SS->setMinimumSize(QSize(120, 50));
        Control_Btn_SS->setMaximumSize(QSize(120, 60));
        Control_Btn_SS->setStyleSheet(QStringLiteral("color: rgb(136, 138, 133);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/control/images/Stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        Control_Btn_SS->setIcon(icon8);
        Control_Btn_SS->setIconSize(QSize(60, 60));

        KeyBoard_GridLayout->addWidget(Control_Btn_SS, 3, 1, 1, 1);

        line = new QFrame(gridLayoutWidget_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        KeyBoard_GridLayout->addWidget(line, 1, 0, 1, 3);

        Control_Label_AMR->addTab(Tab_KeyBoard, QString());

        Control_GridLayout->addWidget(Control_Label_AMR, 0, 0, 1, 1);


        gridLayout_4->addLayout(Control_GridLayout, 0, 0, 1, 1);

        Pos_GroupBox = new QGroupBox(Tab_AMR);
        Pos_GroupBox->setObjectName(QStringLiteral("Pos_GroupBox"));
        Pos_GroupBox->setGeometry(QRect(10, 350, 391, 241));
        Pos_GroupBox->setFont(font2);
        gridLayout_5 = new QGridLayout(Pos_GroupBox);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        Pos_GridLayout = new QGridLayout();
        Pos_GridLayout->setSpacing(2);
        Pos_GridLayout->setObjectName(QStringLiteral("Pos_GridLayout"));
        Pos_Label_RotateX = new QLabel(Pos_GroupBox);
        Pos_Label_RotateX->setObjectName(QStringLiteral("Pos_Label_RotateX"));
        Pos_Label_RotateX->setMinimumSize(QSize(90, 0));
        Pos_Label_RotateX->setMaximumSize(QSize(90, 90));
        QFont font7;
        font7.setFamily(QStringLiteral("Bitstream Vera Sans"));
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        Pos_Label_RotateX->setFont(font7);
        Pos_Label_RotateX->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_RotateX->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_RotateX, 1, 2, 1, 1);

        Pos_Label_Title_Y = new QLabel(Pos_GroupBox);
        Pos_Label_Title_Y->setObjectName(QStringLiteral("Pos_Label_Title_Y"));
        Pos_Label_Title_Y->setMinimumSize(QSize(70, 0));
        Pos_Label_Title_Y->setMaximumSize(QSize(70, 90));
        Pos_Label_Title_Y->setFont(font1);
        Pos_Label_Title_Y->setLayoutDirection(Qt::LeftToRight);
        Pos_Label_Title_Y->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Pos_Label_Title_Y->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_Title_Y, 2, 0, 1, 1);

        Pos_Label_Title_Pos = new QLabel(Pos_GroupBox);
        Pos_Label_Title_Pos->setObjectName(QStringLiteral("Pos_Label_Title_Pos"));
        Pos_Label_Title_Pos->setMinimumSize(QSize(90, 0));
        Pos_Label_Title_Pos->setMaximumSize(QSize(90, 90));
        Pos_Label_Title_Pos->setFont(font1);
        Pos_Label_Title_Pos->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Pos_Label_Title_Pos->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_Title_Pos, 0, 1, 1, 1);

        Pos_Label_PosY = new QLabel(Pos_GroupBox);
        Pos_Label_PosY->setObjectName(QStringLiteral("Pos_Label_PosY"));
        Pos_Label_PosY->setMinimumSize(QSize(90, 0));
        Pos_Label_PosY->setMaximumSize(QSize(90, 90));
        Pos_Label_PosY->setFont(font7);
        Pos_Label_PosY->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_PosY->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_PosY, 2, 1, 1, 1);

        Pos_Label_RotateZ = new QLabel(Pos_GroupBox);
        Pos_Label_RotateZ->setObjectName(QStringLiteral("Pos_Label_RotateZ"));
        Pos_Label_RotateZ->setMinimumSize(QSize(90, 0));
        Pos_Label_RotateZ->setMaximumSize(QSize(90, 90));
        Pos_Label_RotateZ->setFont(font7);
        Pos_Label_RotateZ->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_RotateZ->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_RotateZ, 3, 2, 1, 1);

        Pos_Label_PosZ = new QLabel(Pos_GroupBox);
        Pos_Label_PosZ->setObjectName(QStringLiteral("Pos_Label_PosZ"));
        Pos_Label_PosZ->setMinimumSize(QSize(90, 0));
        Pos_Label_PosZ->setMaximumSize(QSize(90, 90));
        Pos_Label_PosZ->setFont(font1);
        Pos_Label_PosZ->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_PosZ->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_PosZ, 3, 1, 1, 1);

        Pos_Label_Title_X = new QLabel(Pos_GroupBox);
        Pos_Label_Title_X->setObjectName(QStringLiteral("Pos_Label_Title_X"));
        Pos_Label_Title_X->setMinimumSize(QSize(70, 0));
        Pos_Label_Title_X->setMaximumSize(QSize(70, 90));
        Pos_Label_Title_X->setFont(font6);
        Pos_Label_Title_X->setLayoutDirection(Qt::LeftToRight);
        Pos_Label_Title_X->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Pos_Label_Title_X->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_Title_X, 1, 0, 1, 1);

        Pos_Label_Title_Rotate = new QLabel(Pos_GroupBox);
        Pos_Label_Title_Rotate->setObjectName(QStringLiteral("Pos_Label_Title_Rotate"));
        Pos_Label_Title_Rotate->setMinimumSize(QSize(90, 0));
        Pos_Label_Title_Rotate->setMaximumSize(QSize(90, 90));
        Pos_Label_Title_Rotate->setFont(font1);
        Pos_Label_Title_Rotate->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Pos_Label_Title_Rotate->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_Title_Rotate, 0, 2, 1, 1);

        Pos_Label_RotateY = new QLabel(Pos_GroupBox);
        Pos_Label_RotateY->setObjectName(QStringLiteral("Pos_Label_RotateY"));
        Pos_Label_RotateY->setMinimumSize(QSize(90, 0));
        Pos_Label_RotateY->setMaximumSize(QSize(90, 90));
        Pos_Label_RotateY->setFont(font7);
        Pos_Label_RotateY->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_RotateY->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_RotateY, 2, 2, 1, 1);

        Pos_Label_PosX = new QLabel(Pos_GroupBox);
        Pos_Label_PosX->setObjectName(QStringLiteral("Pos_Label_PosX"));
        Pos_Label_PosX->setMinimumSize(QSize(90, 0));
        Pos_Label_PosX->setMaximumSize(QSize(90, 90));
        Pos_Label_PosX->setFont(font7);
        Pos_Label_PosX->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Pos_Label_PosX->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_PosX, 1, 1, 1, 1);

        Pos_Label_Title_Z = new QLabel(Pos_GroupBox);
        Pos_Label_Title_Z->setObjectName(QStringLiteral("Pos_Label_Title_Z"));
        Pos_Label_Title_Z->setMinimumSize(QSize(70, 0));
        Pos_Label_Title_Z->setMaximumSize(QSize(70, 90));
        Pos_Label_Title_Z->setFont(font1);
        Pos_Label_Title_Z->setLayoutDirection(Qt::LeftToRight);
        Pos_Label_Title_Z->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        Pos_Label_Title_Z->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_Title_Z, 3, 0, 1, 1);

        P2P_Btn_Go = new QPushButton(Pos_GroupBox);
        P2P_Btn_Go->setObjectName(QStringLiteral("P2P_Btn_Go"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(P2P_Btn_Go->sizePolicy().hasHeightForWidth());
        P2P_Btn_Go->setSizePolicy(sizePolicy4);
        P2P_Btn_Go->setMinimumSize(QSize(90, 0));
        P2P_Btn_Go->setMaximumSize(QSize(90, 16777215));

        Pos_GridLayout->addWidget(P2P_Btn_Go, 0, 3, 1, 1);

        P2P_LineEdit_X = new QLineEdit(Pos_GroupBox);
        P2P_LineEdit_X->setObjectName(QStringLiteral("P2P_LineEdit_X"));
        P2P_LineEdit_X->setMinimumSize(QSize(0, 0));
        P2P_LineEdit_X->setMaximumSize(QSize(90, 90));
        P2P_LineEdit_X->setFont(font4);
        P2P_LineEdit_X->setLayoutDirection(Qt::LeftToRight);
        P2P_LineEdit_X->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        P2P_LineEdit_X->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(P2P_LineEdit_X, 1, 3, 1, 1);

        P2P_LineEdit_Y = new QLineEdit(Pos_GroupBox);
        P2P_LineEdit_Y->setObjectName(QStringLiteral("P2P_LineEdit_Y"));
        P2P_LineEdit_Y->setMinimumSize(QSize(0, 0));
        P2P_LineEdit_Y->setMaximumSize(QSize(90, 90));
        P2P_LineEdit_Y->setFont(font4);
        P2P_LineEdit_Y->setLayoutDirection(Qt::LeftToRight);
        P2P_LineEdit_Y->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        P2P_LineEdit_Y->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(P2P_LineEdit_Y, 2, 3, 1, 1);

        P2P_LineEdit_Rotate = new QLineEdit(Pos_GroupBox);
        P2P_LineEdit_Rotate->setObjectName(QStringLiteral("P2P_LineEdit_Rotate"));
        P2P_LineEdit_Rotate->setMinimumSize(QSize(0, 0));
        P2P_LineEdit_Rotate->setMaximumSize(QSize(90, 90));
        P2P_LineEdit_Rotate->setFont(font4);
        P2P_LineEdit_Rotate->setLayoutDirection(Qt::LeftToRight);
        P2P_LineEdit_Rotate->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        P2P_LineEdit_Rotate->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(P2P_LineEdit_Rotate, 3, 3, 1, 1);

        Pos_Label_State = new QLabel(Pos_GroupBox);
        Pos_Label_State->setObjectName(QStringLiteral("Pos_Label_State"));
        Pos_Label_State->setMinimumSize(QSize(70, 0));
        Pos_Label_State->setMaximumSize(QSize(70, 90));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setWeight(50);
        Pos_Label_State->setFont(font8);
        Pos_Label_State->setLayoutDirection(Qt::LeftToRight);
        Pos_Label_State->setStyleSheet(QStringLiteral("background-color:rgb(125, 125, 125)"));
        Pos_Label_State->setAlignment(Qt::AlignCenter);

        Pos_GridLayout->addWidget(Pos_Label_State, 0, 0, 1, 1);


        gridLayout_5->addLayout(Pos_GridLayout, 0, 0, 1, 1);

        AMRInfo_GroupBox = new QGroupBox(Tab_AMR);
        AMRInfo_GroupBox->setObjectName(QStringLiteral("AMRInfo_GroupBox"));
        AMRInfo_GroupBox->setGeometry(QRect(410, 350, 451, 241));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(AMRInfo_GroupBox->sizePolicy().hasHeightForWidth());
        AMRInfo_GroupBox->setSizePolicy(sizePolicy5);
        AMRInfo_GroupBox->setFont(font2);
        gridLayout_7 = new QGridLayout(AMRInfo_GroupBox);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        AMRInfo_GridLayout = new QGridLayout();
        AMRInfo_GridLayout->setSpacing(1);
        AMRInfo_GridLayout->setObjectName(QStringLiteral("AMRInfo_GridLayout"));
        AMRInfo_Label_LeftVelocity = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_LeftVelocity->setObjectName(QStringLiteral("AMRInfo_Label_LeftVelocity"));
        AMRInfo_Label_LeftVelocity->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_LeftVelocity->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_LeftVelocity->setFont(font7);
        AMRInfo_Label_LeftVelocity->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        AMRInfo_Label_LeftVelocity->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_LeftVelocity, 3, 1, 1, 1);

        VelInfo_Label_Linear = new QLabel(AMRInfo_GroupBox);
        VelInfo_Label_Linear->setObjectName(QStringLiteral("VelInfo_Label_Linear"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(VelInfo_Label_Linear->sizePolicy().hasHeightForWidth());
        VelInfo_Label_Linear->setSizePolicy(sizePolicy6);
        VelInfo_Label_Linear->setMinimumSize(QSize(80, 50));
        VelInfo_Label_Linear->setMaximumSize(QSize(80, 70));
        VelInfo_Label_Linear->setFont(font7);
        VelInfo_Label_Linear->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        VelInfo_Label_Linear->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(VelInfo_Label_Linear, 3, 5, 1, 1);

        AMRInfo_Label_LeftMotor = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_LeftMotor->setObjectName(QStringLiteral("AMRInfo_Label_LeftMotor"));
        AMRInfo_Label_LeftMotor->setMinimumSize(QSize(80, 20));
        AMRInfo_Label_LeftMotor->setMaximumSize(QSize(80, 20));
        AMRInfo_Label_LeftMotor->setFont(font1);
        AMRInfo_Label_LeftMotor->setAutoFillBackground(false);
        AMRInfo_Label_LeftMotor->setStyleSheet(QStringLiteral(""));
        AMRInfo_Label_LeftMotor->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_LeftMotor, 0, 1, 1, 1);

        VelInfo_Label_Title_Linear = new QLabel(AMRInfo_GroupBox);
        VelInfo_Label_Title_Linear->setObjectName(QStringLiteral("VelInfo_Label_Title_Linear"));
        VelInfo_Label_Title_Linear->setMinimumSize(QSize(80, 50));
        VelInfo_Label_Title_Linear->setMaximumSize(QSize(80, 70));
        VelInfo_Label_Title_Linear->setFont(font1);
        VelInfo_Label_Title_Linear->setLayoutDirection(Qt::LeftToRight);
        VelInfo_Label_Title_Linear->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        VelInfo_Label_Title_Linear->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(VelInfo_Label_Title_Linear, 3, 4, 1, 1);

        AMRInfo_Label_Angle = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_Angle->setObjectName(QStringLiteral("AMRInfo_Label_Angle"));
        sizePolicy.setHeightForWidth(AMRInfo_Label_Angle->sizePolicy().hasHeightForWidth());
        AMRInfo_Label_Angle->setSizePolicy(sizePolicy);
        AMRInfo_Label_Angle->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_Angle->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_Angle->setFont(font6);
        AMRInfo_Label_Angle->setLayoutDirection(Qt::LeftToRight);
        AMRInfo_Label_Angle->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        AMRInfo_Label_Angle->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_Angle, 2, 0, 1, 1);

        AMRInfo_Label_RightAngle = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_RightAngle->setObjectName(QStringLiteral("AMRInfo_Label_RightAngle"));
        AMRInfo_Label_RightAngle->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_RightAngle->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_RightAngle->setFont(font7);
        AMRInfo_Label_RightAngle->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        AMRInfo_Label_RightAngle->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_RightAngle, 2, 2, 1, 1);

        VelInfo_Label_Title_Angular = new QLabel(AMRInfo_GroupBox);
        VelInfo_Label_Title_Angular->setObjectName(QStringLiteral("VelInfo_Label_Title_Angular"));
        VelInfo_Label_Title_Angular->setMinimumSize(QSize(80, 50));
        VelInfo_Label_Title_Angular->setMaximumSize(QSize(80, 70));
        VelInfo_Label_Title_Angular->setFont(font6);
        VelInfo_Label_Title_Angular->setLayoutDirection(Qt::LeftToRight);
        VelInfo_Label_Title_Angular->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        VelInfo_Label_Title_Angular->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(VelInfo_Label_Title_Angular, 2, 4, 1, 1);

        AMRInfo_Label_Velocity = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_Velocity->setObjectName(QStringLiteral("AMRInfo_Label_Velocity"));
        sizePolicy.setHeightForWidth(AMRInfo_Label_Velocity->sizePolicy().hasHeightForWidth());
        AMRInfo_Label_Velocity->setSizePolicy(sizePolicy);
        AMRInfo_Label_Velocity->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_Velocity->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_Velocity->setFont(font1);
        AMRInfo_Label_Velocity->setLayoutDirection(Qt::LeftToRight);
        AMRInfo_Label_Velocity->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        AMRInfo_Label_Velocity->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_Velocity, 3, 0, 1, 1);

        VelInfo_Label_Title_Top = new QLabel(AMRInfo_GroupBox);
        VelInfo_Label_Title_Top->setObjectName(QStringLiteral("VelInfo_Label_Title_Top"));
        sizePolicy6.setHeightForWidth(VelInfo_Label_Title_Top->sizePolicy().hasHeightForWidth());
        VelInfo_Label_Title_Top->setSizePolicy(sizePolicy6);
        VelInfo_Label_Title_Top->setMinimumSize(QSize(170, 50));
        VelInfo_Label_Title_Top->setMaximumSize(QSize(80, 70));
        VelInfo_Label_Title_Top->setFont(font1);
        VelInfo_Label_Title_Top->setStyleSheet(QStringLiteral("background-color:rgb(232, 232, 232)"));
        VelInfo_Label_Title_Top->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(VelInfo_Label_Title_Top, 0, 4, 2, 2);

        AMRInfo_Label_RightMotor = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_RightMotor->setObjectName(QStringLiteral("AMRInfo_Label_RightMotor"));
        AMRInfo_Label_RightMotor->setMinimumSize(QSize(80, 20));
        AMRInfo_Label_RightMotor->setMaximumSize(QSize(80, 20));
        AMRInfo_Label_RightMotor->setFont(font1);
        AMRInfo_Label_RightMotor->setAutoFillBackground(false);
        AMRInfo_Label_RightMotor->setStyleSheet(QStringLiteral(""));
        AMRInfo_Label_RightMotor->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_RightMotor, 0, 2, 1, 1);

        AMRInfo_Label_RightVelocity = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_RightVelocity->setObjectName(QStringLiteral("AMRInfo_Label_RightVelocity"));
        AMRInfo_Label_RightVelocity->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_RightVelocity->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_RightVelocity->setFont(font7);
        AMRInfo_Label_RightVelocity->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        AMRInfo_Label_RightVelocity->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_RightVelocity, 3, 2, 1, 1);

        AMRInfo_Label_LeftAngle = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_LeftAngle->setObjectName(QStringLiteral("AMRInfo_Label_LeftAngle"));
        AMRInfo_Label_LeftAngle->setMinimumSize(QSize(80, 50));
        AMRInfo_Label_LeftAngle->setMaximumSize(QSize(80, 70));
        AMRInfo_Label_LeftAngle->setFont(font7);
        AMRInfo_Label_LeftAngle->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        AMRInfo_Label_LeftAngle->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_LeftAngle, 2, 1, 1, 1);

        AMRInfo_Btn_TorqueSwitch = new QPushButton(AMRInfo_GroupBox);
        AMRInfo_Btn_TorqueSwitch->setObjectName(QStringLiteral("AMRInfo_Btn_TorqueSwitch"));
        sizePolicy.setHeightForWidth(AMRInfo_Btn_TorqueSwitch->sizePolicy().hasHeightForWidth());
        AMRInfo_Btn_TorqueSwitch->setSizePolicy(sizePolicy);
        AMRInfo_Btn_TorqueSwitch->setMinimumSize(QSize(80, 50));
        AMRInfo_Btn_TorqueSwitch->setMaximumSize(QSize(80, 60));
        AMRInfo_Btn_TorqueSwitch->setFont(font5);
        AMRInfo_Btn_TorqueSwitch->setStyleSheet(QStringLiteral("background-color: rgb(125, 255, 125);"));

        AMRInfo_GridLayout->addWidget(AMRInfo_Btn_TorqueSwitch, 0, 0, 2, 1);

        AMRInfo_Label_LeftID = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_LeftID->setObjectName(QStringLiteral("AMRInfo_Label_LeftID"));
        AMRInfo_Label_LeftID->setMinimumSize(QSize(50, 20));
        AMRInfo_Label_LeftID->setMaximumSize(QSize(80, 20));
        AMRInfo_Label_LeftID->setFont(font1);
        AMRInfo_Label_LeftID->setAutoFillBackground(false);
        AMRInfo_Label_LeftID->setStyleSheet(QStringLiteral("background-color:rgb(255, 125, 125)"));
        AMRInfo_Label_LeftID->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_LeftID, 1, 1, 1, 1);

        VelInfo_Label_Angular = new QLabel(AMRInfo_GroupBox);
        VelInfo_Label_Angular->setObjectName(QStringLiteral("VelInfo_Label_Angular"));
        sizePolicy6.setHeightForWidth(VelInfo_Label_Angular->sizePolicy().hasHeightForWidth());
        VelInfo_Label_Angular->setSizePolicy(sizePolicy6);
        VelInfo_Label_Angular->setMinimumSize(QSize(80, 50));
        VelInfo_Label_Angular->setMaximumSize(QSize(80, 70));
        VelInfo_Label_Angular->setFont(font7);
        VelInfo_Label_Angular->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        VelInfo_Label_Angular->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(VelInfo_Label_Angular, 2, 5, 1, 1);

        AMRInfo_Label_RightID = new QLabel(AMRInfo_GroupBox);
        AMRInfo_Label_RightID->setObjectName(QStringLiteral("AMRInfo_Label_RightID"));
        AMRInfo_Label_RightID->setMinimumSize(QSize(50, 20));
        AMRInfo_Label_RightID->setMaximumSize(QSize(80, 20));
        AMRInfo_Label_RightID->setFont(font1);
        AMRInfo_Label_RightID->setStyleSheet(QStringLiteral("background-color:rgb(255, 125, 125)"));
        AMRInfo_Label_RightID->setAlignment(Qt::AlignCenter);

        AMRInfo_GridLayout->addWidget(AMRInfo_Label_RightID, 1, 2, 1, 1);

        AMRInfo_Line_Spacer = new QFrame(AMRInfo_GroupBox);
        AMRInfo_Line_Spacer->setObjectName(QStringLiteral("AMRInfo_Line_Spacer"));
        AMRInfo_Line_Spacer->setFrameShape(QFrame::VLine);
        AMRInfo_Line_Spacer->setFrameShadow(QFrame::Sunken);

        AMRInfo_GridLayout->addWidget(AMRInfo_Line_Spacer, 0, 3, 4, 1);


        gridLayout_7->addLayout(AMRInfo_GridLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Tab_AMR);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(510, 0, 341, 341));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        MAP_graphics_small = new QGraphicsView(tab_3);
        MAP_graphics_small->setObjectName(QStringLiteral("MAP_graphics_small"));
        MAP_graphics_small->setGeometry(QRect(10, 10, 317, 290));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        layoutWidget_5 = new QWidget(tab_4);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(0, 0, 341, 241));
        Conveyor_GridLayout = new QGridLayout(layoutWidget_5);
        Conveyor_GridLayout->setSpacing(2);
        Conveyor_GridLayout->setObjectName(QStringLiteral("Conveyor_GridLayout"));
        Conveyor_GridLayout->setContentsMargins(0, 0, 0, 0);
        Conveyor_lineEdit_Angle = new QLineEdit(layoutWidget_5);
        Conveyor_lineEdit_Angle->setObjectName(QStringLiteral("Conveyor_lineEdit_Angle"));
        Conveyor_lineEdit_Angle->setMinimumSize(QSize(0, 0));
        Conveyor_lineEdit_Angle->setMaximumSize(QSize(80, 90));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font9.setPointSize(16);
        font9.setBold(true);
        font9.setWeight(75);
        Conveyor_lineEdit_Angle->setFont(font9);
        Conveyor_lineEdit_Angle->setLayoutDirection(Qt::LeftToRight);
        Conveyor_lineEdit_Angle->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Conveyor_lineEdit_Angle->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_lineEdit_Angle, 1, 3, 1, 1);

        Conveyor_label_title_velocity = new QLabel(layoutWidget_5);
        Conveyor_label_title_velocity->setObjectName(QStringLiteral("Conveyor_label_title_velocity"));
        Conveyor_label_title_velocity->setFont(font1);
        Conveyor_label_title_velocity->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Conveyor_label_title_velocity->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_title_velocity, 2, 0, 1, 1);

        Conveyor_label_title_torque = new QLabel(layoutWidget_5);
        Conveyor_label_title_torque->setObjectName(QStringLiteral("Conveyor_label_title_torque"));
        Conveyor_label_title_torque->setFont(font1);
        Conveyor_label_title_torque->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Conveyor_label_title_torque->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_title_torque, 4, 0, 1, 1);

        Conveyor_label_velocity_1 = new QLabel(layoutWidget_5);
        Conveyor_label_velocity_1->setObjectName(QStringLiteral("Conveyor_label_velocity_1"));
        Conveyor_label_velocity_1->setFont(font2);
        Conveyor_label_velocity_1->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Conveyor_label_velocity_1->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_velocity_1, 2, 1, 1, 1);

        Conveyor_label_angle_1 = new QLabel(layoutWidget_5);
        Conveyor_label_angle_1->setObjectName(QStringLiteral("Conveyor_label_angle_1"));
        Conveyor_label_angle_1->setFont(font2);
        Conveyor_label_angle_1->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Conveyor_label_angle_1->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_angle_1, 1, 1, 1, 1);

        Conveyor_label_ID_1 = new QLabel(layoutWidget_5);
        Conveyor_label_ID_1->setObjectName(QStringLiteral("Conveyor_label_ID_1"));
        Conveyor_label_ID_1->setFont(font2);
        Conveyor_label_ID_1->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Conveyor_label_ID_1->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_ID_1, 0, 1, 1, 1);

        Conveyor_label_torque_1 = new QLabel(layoutWidget_5);
        Conveyor_label_torque_1->setObjectName(QStringLiteral("Conveyor_label_torque_1"));
        Conveyor_label_torque_1->setFont(font2);
        Conveyor_label_torque_1->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Conveyor_label_torque_1->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_torque_1, 4, 1, 1, 1);

        Conveyor_label_title_angle = new QLabel(layoutWidget_5);
        Conveyor_label_title_angle->setObjectName(QStringLiteral("Conveyor_label_title_angle"));
        Conveyor_label_title_angle->setFont(font1);
        Conveyor_label_title_angle->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Conveyor_label_title_angle->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_title_angle, 1, 0, 1, 1);

        Conveyor_label_ID_2 = new QLabel(layoutWidget_5);
        Conveyor_label_ID_2->setObjectName(QStringLiteral("Conveyor_label_ID_2"));
        Conveyor_label_ID_2->setFont(font2);
        Conveyor_label_ID_2->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Conveyor_label_ID_2->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_ID_2, 0, 2, 1, 1);

        Conveyor_label_angle_2 = new QLabel(layoutWidget_5);
        Conveyor_label_angle_2->setObjectName(QStringLiteral("Conveyor_label_angle_2"));
        Conveyor_label_angle_2->setFont(font2);
        Conveyor_label_angle_2->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Conveyor_label_angle_2->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_angle_2, 1, 2, 1, 1);

        Conveyor_label_velocity_2 = new QLabel(layoutWidget_5);
        Conveyor_label_velocity_2->setObjectName(QStringLiteral("Conveyor_label_velocity_2"));
        Conveyor_label_velocity_2->setFont(font2);
        Conveyor_label_velocity_2->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Conveyor_label_velocity_2->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_velocity_2, 2, 2, 1, 1);

        Conveyor_lineEdit_Velocity = new QLineEdit(layoutWidget_5);
        Conveyor_lineEdit_Velocity->setObjectName(QStringLiteral("Conveyor_lineEdit_Velocity"));
        Conveyor_lineEdit_Velocity->setMinimumSize(QSize(0, 0));
        Conveyor_lineEdit_Velocity->setMaximumSize(QSize(80, 90));
        Conveyor_lineEdit_Velocity->setFont(font9);
        Conveyor_lineEdit_Velocity->setLayoutDirection(Qt::LeftToRight);
        Conveyor_lineEdit_Velocity->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Conveyor_lineEdit_Velocity->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_lineEdit_Velocity, 2, 3, 1, 1);

        Conveyor_label_torque_2 = new QLabel(layoutWidget_5);
        Conveyor_label_torque_2->setObjectName(QStringLiteral("Conveyor_label_torque_2"));
        Conveyor_label_torque_2->setFont(font2);
        Conveyor_label_torque_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Conveyor_label_torque_2->setAlignment(Qt::AlignCenter);

        Conveyor_GridLayout->addWidget(Conveyor_label_torque_2, 4, 2, 1, 1);

        Conveyor_btn_Rot = new QPushButton(tab_4);
        Conveyor_btn_Rot->setObjectName(QStringLiteral("Conveyor_btn_Rot"));
        Conveyor_btn_Rot->setGeometry(QRect(70, 250, 111, 60));
        Conveyor_btn_Rot->setMinimumSize(QSize(0, 0));
        Conveyor_btn_Rot->setMaximumSize(QSize(150, 60));
        QFont font10;
        font10.setFamily(QStringLiteral("Bitstream Vera Sans"));
        font10.setPointSize(20);
        font10.setBold(true);
        font10.setWeight(75);
        Conveyor_btn_Rot->setFont(font10);
        Conveyor_btn_Rot->setStyleSheet(QStringLiteral("background-color :rgb(225, 225, 225)"));
        Conveyor_btn_Rot->setAutoExclusive(true);
        Conveyor_btn_Put = new QPushButton(tab_4);
        Conveyor_btn_Put->setObjectName(QStringLiteral("Conveyor_btn_Put"));
        Conveyor_btn_Put->setGeometry(QRect(210, 250, 80, 60));
        Conveyor_btn_Put->setMinimumSize(QSize(0, 0));
        Conveyor_btn_Put->setMaximumSize(QSize(80, 60));
        Conveyor_btn_Put->setFont(font10);
        Conveyor_btn_Put->setStyleSheet(QStringLiteral("background-color :rgb(225, 225, 225)"));
        Conveyor_btn_Put->setAutoExclusive(true);
        tabWidget->addTab(tab_4, QString());
        Tab_System->addTab(Tab_AMR, QString());
        Tab_Manipulator = new QWidget();
        Tab_Manipulator->setObjectName(QStringLiteral("Tab_Manipulator"));
        ArmMotorInfo_GroupBox = new QGroupBox(Tab_Manipulator);
        ArmMotorInfo_GroupBox->setObjectName(QStringLiteral("ArmMotorInfo_GroupBox"));
        ArmMotorInfo_GroupBox->setGeometry(QRect(0, 0, 591, 291));
        ArmMotorInfo_GroupBox->setFont(font2);
        gridLayoutWidget_6 = new QWidget(ArmMotorInfo_GroupBox);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 40, 571, 241));
        Arm_GridLayout = new QGridLayout(gridLayoutWidget_6);
        Arm_GridLayout->setObjectName(QStringLiteral("Arm_GridLayout"));
        Arm_GridLayout->setContentsMargins(0, 0, 0, 0);
        Arm_label_velocity_3 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_3->setObjectName(QStringLiteral("Arm_label_velocity_3"));
        Arm_label_velocity_3->setFont(font2);
        Arm_label_velocity_3->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_3->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_3, 2, 4, 1, 1);

        Arm_label_torque_3 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_3->setObjectName(QStringLiteral("Arm_label_torque_3"));
        Arm_label_torque_3->setFont(font2);
        Arm_label_torque_3->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_3->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_3, 3, 4, 1, 1);

        Arm_label_angle_3 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_3->setObjectName(QStringLiteral("Arm_label_angle_3"));
        Arm_label_angle_3->setFont(font2);
        Arm_label_angle_3->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_3->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_3, 1, 4, 1, 1);

        Arm_label_angle_5 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_5->setObjectName(QStringLiteral("Arm_label_angle_5"));
        Arm_label_angle_5->setFont(font2);
        Arm_label_angle_5->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_5->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_5, 1, 6, 1, 1);

        Arm_label_title_torque = new QLabel(gridLayoutWidget_6);
        Arm_label_title_torque->setObjectName(QStringLiteral("Arm_label_title_torque"));
        Arm_label_title_torque->setFont(font1);
        Arm_label_title_torque->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_title_torque->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_title_torque, 3, 0, 1, 1);

        Arm_label_ID_3 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_3->setObjectName(QStringLiteral("Arm_label_ID_3"));
        Arm_label_ID_3->setFont(font2);
        Arm_label_ID_3->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_3->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_3, 0, 4, 1, 1);

        Arm_label_torque_2 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_2->setObjectName(QStringLiteral("Arm_label_torque_2"));
        Arm_label_torque_2->setFont(font2);
        Arm_label_torque_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_2, 3, 3, 1, 1);

        Arm_label_ID_4 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_4->setObjectName(QStringLiteral("Arm_label_ID_4"));
        Arm_label_ID_4->setFont(font2);
        Arm_label_ID_4->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_4->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_4, 0, 5, 1, 1);

        Arm_label_angle_1 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_1->setObjectName(QStringLiteral("Arm_label_angle_1"));
        Arm_label_angle_1->setFont(font2);
        Arm_label_angle_1->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_1->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_1, 1, 2, 1, 1);

        Arm_label_torque_5 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_5->setObjectName(QStringLiteral("Arm_label_torque_5"));
        Arm_label_torque_5->setFont(font2);
        Arm_label_torque_5->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_5->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_5, 3, 6, 1, 1);

        Arm_label_torque_1 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_1->setObjectName(QStringLiteral("Arm_label_torque_1"));
        Arm_label_torque_1->setFont(font2);
        Arm_label_torque_1->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_1->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_1, 3, 2, 1, 1);

        Arm_label_velocity_1 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_1->setObjectName(QStringLiteral("Arm_label_velocity_1"));
        Arm_label_velocity_1->setFont(font2);
        Arm_label_velocity_1->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_1->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_1, 2, 2, 1, 1);

        Arm_label_angle_0 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_0->setObjectName(QStringLiteral("Arm_label_angle_0"));
        Arm_label_angle_0->setFont(font2);
        Arm_label_angle_0->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_0->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_0, 1, 1, 1, 1);

        Arm_label_angle_2 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_2->setObjectName(QStringLiteral("Arm_label_angle_2"));
        Arm_label_angle_2->setFont(font2);
        Arm_label_angle_2->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_2, 1, 3, 1, 1);

        Arm_label_ID_1 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_1->setObjectName(QStringLiteral("Arm_label_ID_1"));
        Arm_label_ID_1->setFont(font2);
        Arm_label_ID_1->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_1->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_1, 0, 2, 1, 1);

        Arm_label_torque_4 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_4->setObjectName(QStringLiteral("Arm_label_torque_4"));
        Arm_label_torque_4->setFont(font2);
        Arm_label_torque_4->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_4->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_4, 3, 5, 1, 1);

        Arm_label_ID_2 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_2->setObjectName(QStringLiteral("Arm_label_ID_2"));
        Arm_label_ID_2->setFont(font2);
        Arm_label_ID_2->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_2, 0, 3, 1, 1);

        Arm_label_torque_0 = new QLabel(gridLayoutWidget_6);
        Arm_label_torque_0->setObjectName(QStringLiteral("Arm_label_torque_0"));
        Arm_label_torque_0->setFont(font2);
        Arm_label_torque_0->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_0->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_torque_0, 3, 1, 1, 1);

        Arm_label_velocity_0 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_0->setObjectName(QStringLiteral("Arm_label_velocity_0"));
        Arm_label_velocity_0->setFont(font2);
        Arm_label_velocity_0->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_0->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_0, 2, 1, 1, 1);

        Arm_label_ID_5 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_5->setObjectName(QStringLiteral("Arm_label_ID_5"));
        Arm_label_ID_5->setFont(font2);
        Arm_label_ID_5->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_5->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_5, 0, 6, 1, 1);

        Arm_label_velocity_2 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_2->setObjectName(QStringLiteral("Arm_label_velocity_2"));
        Arm_label_velocity_2->setFont(font2);
        Arm_label_velocity_2->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_2, 2, 3, 1, 1);

        Arm_label_ID_0 = new QLabel(gridLayoutWidget_6);
        Arm_label_ID_0->setObjectName(QStringLiteral("Arm_label_ID_0"));
        Arm_label_ID_0->setFont(font2);
        Arm_label_ID_0->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_0->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_ID_0, 0, 1, 1, 1);

        Arm_label_angle_4 = new QLabel(gridLayoutWidget_6);
        Arm_label_angle_4->setObjectName(QStringLiteral("Arm_label_angle_4"));
        Arm_label_angle_4->setFont(font2);
        Arm_label_angle_4->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_4->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_angle_4, 1, 5, 1, 1);

        Arm_label_velocity_4 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_4->setObjectName(QStringLiteral("Arm_label_velocity_4"));
        Arm_label_velocity_4->setFont(font2);
        Arm_label_velocity_4->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_4->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_4, 2, 5, 1, 1);

        Arm_label_velocity_5 = new QLabel(gridLayoutWidget_6);
        Arm_label_velocity_5->setObjectName(QStringLiteral("Arm_label_velocity_5"));
        Arm_label_velocity_5->setFont(font2);
        Arm_label_velocity_5->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_5->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_velocity_5, 2, 6, 1, 1);

        Arm_label_title_velocity = new QLabel(gridLayoutWidget_6);
        Arm_label_title_velocity->setObjectName(QStringLiteral("Arm_label_title_velocity"));
        Arm_label_title_velocity->setFont(font1);
        Arm_label_title_velocity->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_title_velocity->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_title_velocity, 2, 0, 1, 1);

        Arm_label_title_angle = new QLabel(gridLayoutWidget_6);
        Arm_label_title_angle->setObjectName(QStringLiteral("Arm_label_title_angle"));
        Arm_label_title_angle->setFont(font1);
        Arm_label_title_angle->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_angle->setAlignment(Qt::AlignCenter);

        Arm_GridLayout->addWidget(Arm_label_title_angle, 1, 0, 1, 1);

        ArmPosition_GroupBox = new QGroupBox(Tab_Manipulator);
        ArmPosition_GroupBox->setObjectName(QStringLiteral("ArmPosition_GroupBox"));
        ArmPosition_GroupBox->setGeometry(QRect(0, 290, 531, 291));
        ArmPosition_GroupBox->setFont(font2);
        gridLayoutWidget_7 = new QWidget(ArmPosition_GroupBox);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(10, 40, 171, 241));
        Arm_GridLayout_Pos = new QGridLayout(gridLayoutWidget_7);
        Arm_GridLayout_Pos->setObjectName(QStringLiteral("Arm_GridLayout_Pos"));
        Arm_GridLayout_Pos->setContentsMargins(0, 0, 0, 0);
        Arm_label_title_currentRot = new QLabel(gridLayoutWidget_7);
        Arm_label_title_currentRot->setObjectName(QStringLiteral("Arm_label_title_currentRot"));
        Arm_label_title_currentRot->setMaximumSize(QSize(50, 16777215));
        Arm_label_title_currentRot->setFont(font2);
        Arm_label_title_currentRot->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_currentRot->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_title_currentRot, 0, 2, 1, 1);

        Arm_label_currentPosY = new QLabel(gridLayoutWidget_7);
        Arm_label_currentPosY->setObjectName(QStringLiteral("Arm_label_currentPosY"));
        Arm_label_currentPosY->setFont(font2);
        Arm_label_currentPosY->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentPosY->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentPosY, 2, 1, 1, 1);

        Arm_label_title_currentPos = new QLabel(gridLayoutWidget_7);
        Arm_label_title_currentPos->setObjectName(QStringLiteral("Arm_label_title_currentPos"));
        Arm_label_title_currentPos->setMaximumSize(QSize(50, 16777215));
        Arm_label_title_currentPos->setFont(font2);
        Arm_label_title_currentPos->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_currentPos->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_title_currentPos, 0, 1, 1, 1);

        Arm_label_title_currentZ = new QLabel(gridLayoutWidget_7);
        Arm_label_title_currentZ->setObjectName(QStringLiteral("Arm_label_title_currentZ"));
        Arm_label_title_currentZ->setMaximumSize(QSize(50, 16777215));
        Arm_label_title_currentZ->setFont(font2);
        Arm_label_title_currentZ->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_currentZ->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_title_currentZ, 3, 0, 1, 1);

        Arm_label_currentRotY = new QLabel(gridLayoutWidget_7);
        Arm_label_currentRotY->setObjectName(QStringLiteral("Arm_label_currentRotY"));
        Arm_label_currentRotY->setFont(font2);
        Arm_label_currentRotY->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentRotY->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentRotY, 2, 2, 1, 1);

        Arm_label_currentRotZ = new QLabel(gridLayoutWidget_7);
        Arm_label_currentRotZ->setObjectName(QStringLiteral("Arm_label_currentRotZ"));
        Arm_label_currentRotZ->setFont(font2);
        Arm_label_currentRotZ->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentRotZ->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentRotZ, 3, 2, 1, 1);

        Arm_label_title_currentY = new QLabel(gridLayoutWidget_7);
        Arm_label_title_currentY->setObjectName(QStringLiteral("Arm_label_title_currentY"));
        Arm_label_title_currentY->setMaximumSize(QSize(50, 16777215));
        Arm_label_title_currentY->setFont(font2);
        Arm_label_title_currentY->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_currentY->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_title_currentY, 2, 0, 1, 1);

        Arm_label_currentPosX = new QLabel(gridLayoutWidget_7);
        Arm_label_currentPosX->setObjectName(QStringLiteral("Arm_label_currentPosX"));
        Arm_label_currentPosX->setFont(font2);
        Arm_label_currentPosX->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentPosX->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentPosX, 1, 1, 1, 1);

        Arm_label_title_currentX = new QLabel(gridLayoutWidget_7);
        Arm_label_title_currentX->setObjectName(QStringLiteral("Arm_label_title_currentX"));
        Arm_label_title_currentX->setMaximumSize(QSize(50, 16777215));
        Arm_label_title_currentX->setFont(font2);
        Arm_label_title_currentX->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_currentX->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_title_currentX, 1, 0, 1, 1);

        Arm_label_currentPosZ = new QLabel(gridLayoutWidget_7);
        Arm_label_currentPosZ->setObjectName(QStringLiteral("Arm_label_currentPosZ"));
        Arm_label_currentPosZ->setFont(font2);
        Arm_label_currentPosZ->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentPosZ->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentPosZ, 3, 1, 1, 1);

        Arm_label_currentRotX = new QLabel(gridLayoutWidget_7);
        Arm_label_currentRotX->setObjectName(QStringLiteral("Arm_label_currentRotX"));
        Arm_label_currentRotX->setFont(font2);
        Arm_label_currentRotX->setStyleSheet(QStringLiteral("background-color:rgb(251, 255, 231)"));
        Arm_label_currentRotX->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Pos->addWidget(Arm_label_currentRotX, 1, 2, 1, 1);

        layoutWidget_3 = new QWidget(ArmPosition_GroupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(190, 40, 231, 241));
        Arm_GridLayout_Control = new QGridLayout(layoutWidget_3);
        Arm_GridLayout_Control->setSpacing(2);
        Arm_GridLayout_Control->setObjectName(QStringLiteral("Arm_GridLayout_Control"));
        Arm_GridLayout_Control->setContentsMargins(0, 0, 0, 0);
        Arm_lineEdit_Oz = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_Oz->setObjectName(QStringLiteral("Arm_lineEdit_Oz"));
        Arm_lineEdit_Oz->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Oz->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_Oz->setFont(font9);
        Arm_lineEdit_Oz->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Oz->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Oz->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_Oz, 4, 2, 1, 1);

        Arm_label_title_controlY = new QLabel(layoutWidget_3);
        Arm_label_title_controlY->setObjectName(QStringLiteral("Arm_label_title_controlY"));
        Arm_label_title_controlY->setMinimumSize(QSize(0, 0));
        Arm_label_title_controlY->setMaximumSize(QSize(50, 90));
        Arm_label_title_controlY->setFont(font2);
        Arm_label_title_controlY->setLayoutDirection(Qt::LeftToRight);
        Arm_label_title_controlY->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_controlY->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_label_title_controlY, 2, 0, 1, 1);

        Arm_label_title_controlPos = new QLabel(layoutWidget_3);
        Arm_label_title_controlPos->setObjectName(QStringLiteral("Arm_label_title_controlPos"));
        Arm_label_title_controlPos->setMaximumSize(QSize(70, 90));
        Arm_label_title_controlPos->setFont(font2);
        Arm_label_title_controlPos->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_controlPos->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_label_title_controlPos, 0, 1, 1, 1);

        Arm_label_title_controlX = new QLabel(layoutWidget_3);
        Arm_label_title_controlX->setObjectName(QStringLiteral("Arm_label_title_controlX"));
        Arm_label_title_controlX->setMinimumSize(QSize(0, 0));
        Arm_label_title_controlX->setMaximumSize(QSize(50, 90));
        QFont font11;
        font11.setFamily(QStringLiteral("Ubuntu"));
        font11.setPointSize(16);
        font11.setBold(true);
        font11.setItalic(false);
        font11.setWeight(75);
        Arm_label_title_controlX->setFont(font11);
        Arm_label_title_controlX->setLayoutDirection(Qt::LeftToRight);
        Arm_label_title_controlX->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_controlX->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_label_title_controlX, 1, 0, 1, 1);

        Arm_lineEdit_Y = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_Y->setObjectName(QStringLiteral("Arm_lineEdit_Y"));
        Arm_lineEdit_Y->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Y->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_Y->setFont(font9);
        Arm_lineEdit_Y->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Y->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Y->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_Y, 2, 1, 1, 1);

        Arm_lineEdit_Z = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_Z->setObjectName(QStringLiteral("Arm_lineEdit_Z"));
        Arm_lineEdit_Z->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Z->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_Z->setFont(font9);
        Arm_lineEdit_Z->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Z->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Z->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_Z, 4, 1, 1, 1);

        Arm_lineEdit_Oy = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_Oy->setObjectName(QStringLiteral("Arm_lineEdit_Oy"));
        Arm_lineEdit_Oy->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Oy->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_Oy->setFont(font9);
        Arm_lineEdit_Oy->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Oy->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Oy->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_Oy, 2, 2, 1, 1);

        Arm_lineEdit_Ox = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_Ox->setObjectName(QStringLiteral("Arm_lineEdit_Ox"));
        Arm_lineEdit_Ox->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Ox->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_Ox->setFont(font9);
        Arm_lineEdit_Ox->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Ox->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Ox->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_Ox, 1, 2, 1, 1);

        Arm_label_title_controlZ = new QLabel(layoutWidget_3);
        Arm_label_title_controlZ->setObjectName(QStringLiteral("Arm_label_title_controlZ"));
        Arm_label_title_controlZ->setMinimumSize(QSize(0, 0));
        Arm_label_title_controlZ->setMaximumSize(QSize(50, 90));
        Arm_label_title_controlZ->setFont(font2);
        Arm_label_title_controlZ->setLayoutDirection(Qt::LeftToRight);
        Arm_label_title_controlZ->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_controlZ->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_label_title_controlZ, 4, 0, 1, 1);

        Arm_lineEdit_X = new QLineEdit(layoutWidget_3);
        Arm_lineEdit_X->setObjectName(QStringLiteral("Arm_lineEdit_X"));
        Arm_lineEdit_X->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_X->setMaximumSize(QSize(70, 90));
        Arm_lineEdit_X->setFont(font9);
        Arm_lineEdit_X->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_X->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_X->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_lineEdit_X, 1, 1, 1, 1);

        Arm_label_title_controlRot = new QLabel(layoutWidget_3);
        Arm_label_title_controlRot->setObjectName(QStringLiteral("Arm_label_title_controlRot"));
        Arm_label_title_controlRot->setMaximumSize(QSize(70, 90));
        Arm_label_title_controlRot->setFont(font2);
        Arm_label_title_controlRot->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_controlRot->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Control->addWidget(Arm_label_title_controlRot, 0, 2, 1, 1);

        layoutWidget = new QWidget(ArmPosition_GroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 40, 91, 241));
        Arm_VerticalLayout_Control = new QVBoxLayout(layoutWidget);
        Arm_VerticalLayout_Control->setObjectName(QStringLiteral("Arm_VerticalLayout_Control"));
        Arm_VerticalLayout_Control->setContentsMargins(0, 0, 0, 0);
        Arm_btn_Start = new QPushButton(layoutWidget);
        Arm_btn_Start->setObjectName(QStringLiteral("Arm_btn_Start"));
        Arm_btn_Start->setMaximumSize(QSize(90, 70));
        QFont font12;
        font12.setPointSize(16);
        Arm_btn_Start->setFont(font12);
        Arm_btn_Start->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));

        Arm_VerticalLayout_Control->addWidget(Arm_btn_Start);

        Arm_btn_Stop = new QPushButton(layoutWidget);
        Arm_btn_Stop->setObjectName(QStringLiteral("Arm_btn_Stop"));
        Arm_btn_Stop->setMaximumSize(QSize(90, 70));
        Arm_btn_Stop->setFont(font12);
        Arm_btn_Stop->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));

        Arm_VerticalLayout_Control->addWidget(Arm_btn_Stop);

        Arm_btn_PosGo = new QPushButton(layoutWidget);
        Arm_btn_PosGo->setObjectName(QStringLiteral("Arm_btn_PosGo"));
        Arm_btn_PosGo->setMinimumSize(QSize(0, 0));
        Arm_btn_PosGo->setMaximumSize(QSize(90, 70));
        Arm_btn_PosGo->setFont(font10);
        Arm_btn_PosGo->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        Arm_btn_PosGo->setAutoExclusive(true);

        Arm_VerticalLayout_Control->addWidget(Arm_btn_PosGo);

        ArmRotation_GroupBox = new QGroupBox(Tab_Manipulator);
        ArmRotation_GroupBox->setObjectName(QStringLiteral("ArmRotation_GroupBox"));
        ArmRotation_GroupBox->setGeometry(QRect(540, 290, 371, 291));
        ArmRotation_GroupBox->setFont(font2);
        ArmRotation_GroupBox->setStyleSheet(QStringLiteral(""));
        layoutWidget_4 = new QWidget(ArmRotation_GroupBox);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 40, 261, 241));
        Arm_GridLayout_Rot = new QGridLayout(layoutWidget_4);
        Arm_GridLayout_Rot->setSpacing(2);
        Arm_GridLayout_Rot->setObjectName(QStringLiteral("Arm_GridLayout_Rot"));
        Arm_GridLayout_Rot->setContentsMargins(0, 0, 0, 0);
        Arm_label_title_velocity_2 = new QLabel(layoutWidget_4);
        Arm_label_title_velocity_2->setObjectName(QStringLiteral("Arm_label_title_velocity_2"));
        Arm_label_title_velocity_2->setFont(font1);
        Arm_label_title_velocity_2->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_title_velocity_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_title_velocity_2, 2, 0, 1, 1);

        Arm_label_title_armRot = new QLabel(layoutWidget_4);
        Arm_label_title_armRot->setObjectName(QStringLiteral("Arm_label_title_armRot"));
        Arm_label_title_armRot->setMaximumSize(QSize(80, 90));
        Arm_label_title_armRot->setFont(font2);
        Arm_label_title_armRot->setStyleSheet(QStringLiteral("background-color:rgb(232, 255, 229)"));
        Arm_label_title_armRot->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_title_armRot, 0, 2, 1, 1);

        Arm_lineEdit_Angle = new QLineEdit(layoutWidget_4);
        Arm_lineEdit_Angle->setObjectName(QStringLiteral("Arm_lineEdit_Angle"));
        Arm_lineEdit_Angle->setMinimumSize(QSize(0, 0));
        Arm_lineEdit_Angle->setMaximumSize(QSize(80, 90));
        Arm_lineEdit_Angle->setFont(font9);
        Arm_lineEdit_Angle->setLayoutDirection(Qt::LeftToRight);
        Arm_lineEdit_Angle->setStyleSheet(QStringLiteral("background-color:rgb(255, 248, 252)"));
        Arm_lineEdit_Angle->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_lineEdit_Angle, 1, 2, 1, 1);

        Arm_label_ID_6 = new QLabel(layoutWidget_4);
        Arm_label_ID_6->setObjectName(QStringLiteral("Arm_label_ID_6"));
        Arm_label_ID_6->setFont(font2);
        Arm_label_ID_6->setStyleSheet(QStringLiteral("background-color :rgb(255, 60, 63)"));
        Arm_label_ID_6->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_ID_6, 0, 1, 1, 1);

        Arm_label_velocity_6 = new QLabel(layoutWidget_4);
        Arm_label_velocity_6->setObjectName(QStringLiteral("Arm_label_velocity_6"));
        Arm_label_velocity_6->setFont(font2);
        Arm_label_velocity_6->setStyleSheet(QStringLiteral("background-color: rgb(214, 212, 231)"));
        Arm_label_velocity_6->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_velocity_6, 2, 1, 1, 1);

        Arm_label_torque_6 = new QLabel(layoutWidget_4);
        Arm_label_torque_6->setObjectName(QStringLiteral("Arm_label_torque_6"));
        Arm_label_torque_6->setFont(font2);
        Arm_label_torque_6->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_torque_6->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_torque_6, 4, 1, 1, 1);

        Arm_label_angle_6 = new QLabel(layoutWidget_4);
        Arm_label_angle_6->setObjectName(QStringLiteral("Arm_label_angle_6"));
        Arm_label_angle_6->setFont(font2);
        Arm_label_angle_6->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_angle_6->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_angle_6, 1, 1, 1, 1);

        Arm_label_title_angle_2 = new QLabel(layoutWidget_4);
        Arm_label_title_angle_2->setObjectName(QStringLiteral("Arm_label_title_angle_2"));
        Arm_label_title_angle_2->setFont(font1);
        Arm_label_title_angle_2->setStyleSheet(QStringLiteral("background-color: rgb(229, 229, 229)"));
        Arm_label_title_angle_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_title_angle_2, 1, 0, 1, 1);

        Arm_label_title_torque_2 = new QLabel(layoutWidget_4);
        Arm_label_title_torque_2->setObjectName(QStringLiteral("Arm_label_title_torque_2"));
        Arm_label_title_torque_2->setFont(font1);
        Arm_label_title_torque_2->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        Arm_label_title_torque_2->setAlignment(Qt::AlignCenter);

        Arm_GridLayout_Rot->addWidget(Arm_label_title_torque_2, 4, 0, 1, 1);

        Arm_btn_RotGo = new QPushButton(ArmRotation_GroupBox);
        Arm_btn_RotGo->setObjectName(QStringLiteral("Arm_btn_RotGo"));
        Arm_btn_RotGo->setGeometry(QRect(280, 210, 80, 70));
        Arm_btn_RotGo->setMinimumSize(QSize(0, 0));
        Arm_btn_RotGo->setMaximumSize(QSize(80, 70));
        Arm_btn_RotGo->setFont(font10);
        Arm_btn_RotGo->setStyleSheet(QStringLiteral("background-color :rgb(225, 225, 225)"));
        Arm_btn_RotGo->setAutoExclusive(true);
        Gripper_GroupBox = new QGroupBox(Tab_Manipulator);
        Gripper_GroupBox->setObjectName(QStringLiteral("Gripper_GroupBox"));
        Gripper_GroupBox->setGeometry(QRect(600, 0, 311, 291));
        Gripper_GroupBox->setFont(font2);
        layoutWidget1 = new QWidget(Gripper_GroupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(71, 37, 171, 241));
        Gripper_VerticalLayout = new QVBoxLayout(layoutWidget1);
        Gripper_VerticalLayout->setObjectName(QStringLiteral("Gripper_VerticalLayout"));
        Gripper_VerticalLayout->setContentsMargins(0, 0, 0, 0);
        Arm_btn_GripperOn = new QPushButton(layoutWidget1);
        Arm_btn_GripperOn->setObjectName(QStringLiteral("Arm_btn_GripperOn"));
        Arm_btn_GripperOn->setMaximumSize(QSize(170, 80));
        QFont font13;
        font13.setPointSize(20);
        font13.setBold(true);
        font13.setWeight(75);
        Arm_btn_GripperOn->setFont(font13);

        Gripper_VerticalLayout->addWidget(Arm_btn_GripperOn);

        Arm_btn_GripperOff = new QPushButton(layoutWidget1);
        Arm_btn_GripperOff->setObjectName(QStringLiteral("Arm_btn_GripperOff"));
        Arm_btn_GripperOff->setMaximumSize(QSize(170, 80));
        Arm_btn_GripperOff->setFont(font13);

        Gripper_VerticalLayout->addWidget(Arm_btn_GripperOff);

        Tab_System->addTab(Tab_Manipulator, QString());

        verticalLayout->addWidget(Tab_System);

        AMMR_Btn_Reconnect = new QPushButton(centralwidget);
        AMMR_Btn_Reconnect->setObjectName(QStringLiteral("AMMR_Btn_Reconnect"));

        verticalLayout->addWidget(AMMR_Btn_Reconnect);

        Form_AMMR->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form_AMMR);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 917, 22));
        Form_AMMR->setMenuBar(menubar);
        statusbar = new QStatusBar(Form_AMMR);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Form_AMMR->setStatusBar(statusbar);

        retranslateUi(Form_AMMR);

        Tab_System->setCurrentIndex(1);
        Control_Label_AMR->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_AMMR);
    } // setupUi

    void retranslateUi(QMainWindow *Form_AMMR)
    {
        Form_AMMR->setWindowTitle(QApplication::translate("Form_AMMR", "MainWindow", Q_NULLPTR));
        Color_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Color", Q_NULLPTR));
        LiDAR1_GroupBox->setTitle(QApplication::translate("Form_AMMR", "LiDAR 1", Q_NULLPTR));
        LiDAR1_Label_Range->setText(QApplication::translate("Form_AMMR", "\302\261 1m", Q_NULLPTR));
        LiDAR2_GroupBox->setTitle(QApplication::translate("Form_AMMR", "LiDAR 2", Q_NULLPTR));
        LiDAR2_Label_Range->setText(QApplication::translate("Form_AMMR", "\302\261 1 m", Q_NULLPTR));
        Depth_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Depth", Q_NULLPTR));
        LiDAR1_Btn_InvertZ->setText(QApplication::translate("Form_AMMR", "Invert", Q_NULLPTR));
        LiDAR2_Btn_InvertZ->setText(QApplication::translate("Form_AMMR", "Invert", Q_NULLPTR));
        LiDAR1_Text_Info->setHtml(QApplication::translate("Form_AMMR", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Range -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Min: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Max: 5.6</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\"># of Scan -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    All: 637</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Valid: 637</span></p></body></html>", Q_NULLPTR));
        LiDAR2_Text_Info->setHtml(QApplication::translate("Form_AMMR", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Range -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Min:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Max:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                        "-qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\"># of Scan -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    All:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    Valid:</span></p></body></html>", Q_NULLPTR));
        Color_Text_Info->setHtml(QApplication::translate("Form_AMMR", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Resolution -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    240x320</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Intrinsic -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    FX:  286.44</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    FY:  271.37</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    CX: 157.32</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    CY: 120.08</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-size:11pt; font-weight:400;\">    K1: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    K2: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    P1: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    P2: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    K3: 0</span></p></body></html>", Q_NULLPTR));
        Depth_Text_Info->setHtml(QApplication::translate("Form_AMMR", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Resolution -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    240x320</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">Intrinsic -</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    FX:  286.44</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    FY:  271.37</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    CX: 157.32</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    CY: 120.08</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-size:11pt; font-weight:400;\">    K1: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    K2: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    P1: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    P2: 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">    K3: 0</span></p></body></html>", Q_NULLPTR));
        LiDAR1_Btn_ShowLines->setText(QApplication::translate("Form_AMMR", "Show Lines", Q_NULLPTR));
        LiDAR2_Btn_ShowLines->setText(QApplication::translate("Form_AMMR", "Show Lines", Q_NULLPTR));
        Tab_System->setTabText(Tab_System->indexOf(Tab_VLSensor), QApplication::translate("Form_AMMR", "Vision, LiDAR", Q_NULLPTR));
        Control_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Motion Control", Q_NULLPTR));
        Diff_LineEdit_Linear->setText(QString());
        Diff_Label_Title_Top->setText(QApplication::translate("Form_AMMR", "AMR Velocity", Q_NULLPTR));
        Diff_Btn_Go->setText(QApplication::translate("Form_AMMR", "GO", Q_NULLPTR));
        Diff_Btn_Stop->setText(QApplication::translate("Form_AMMR", "Stop", Q_NULLPTR));
        Diff_Label_Title_Linear->setText(QApplication::translate("Form_AMMR", "Linear\n"
"(m/s)", Q_NULLPTR));
        Diff_Label_Title_Angular->setText(QApplication::translate("Form_AMMR", "Angular\n"
"(rad/s)", Q_NULLPTR));
        Diff_LineEdit_Angular->setText(QString());
        Control_Label_AMR->setTabText(Control_Label_AMR->indexOf(Tab_DiffControl), QApplication::translate("Form_AMMR", "Differential", Q_NULLPTR));
        Control_Btn_RB->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"C", Q_NULLPTR));
        Control_Btn_LB->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"Z", Q_NULLPTR));
        Control_Btn_RF->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"E", Q_NULLPTR));
        Control_Btn_LF->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"Q", Q_NULLPTR));
        Control_Label_FSpeed->setText(QApplication::translate("Form_AMMR", "1 RPM", Q_NULLPTR));
        Control_Btn_RS->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"D", Q_NULLPTR));
        Control_Btn_LS->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"A", Q_NULLPTR));
        Control_Btn_SB->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"X", Q_NULLPTR));
        Control_Btn_SF->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"W", Q_NULLPTR));
        Control_Btn_SS->setText(QApplication::translate("Form_AMMR", "\n"
"\n"
"S", Q_NULLPTR));
        Control_Label_AMR->setTabText(Control_Label_AMR->indexOf(Tab_KeyBoard), QApplication::translate("Form_AMMR", "KeyBoard", Q_NULLPTR));
        Pos_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Robot Position in Map", Q_NULLPTR));
        Pos_Label_RotateX->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        Pos_Label_Title_Y->setText(QApplication::translate("Form_AMMR", "Y", Q_NULLPTR));
        Pos_Label_Title_Pos->setText(QApplication::translate("Form_AMMR", "Pos(m)", Q_NULLPTR));
        Pos_Label_PosY->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Pos_Label_RotateZ->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Pos_Label_PosZ->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        Pos_Label_Title_X->setText(QApplication::translate("Form_AMMR", "X", Q_NULLPTR));
        Pos_Label_Title_Rotate->setText(QApplication::translate("Form_AMMR", "Rot(\302\260)", Q_NULLPTR));
        Pos_Label_RotateY->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        Pos_Label_PosX->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Pos_Label_Title_Z->setText(QApplication::translate("Form_AMMR", "Z", Q_NULLPTR));
        P2P_Btn_Go->setText(QApplication::translate("Form_AMMR", "Go", Q_NULLPTR));
        P2P_LineEdit_X->setText(QString());
        P2P_LineEdit_Y->setText(QString());
        P2P_LineEdit_Rotate->setText(QString());
        Pos_Label_State->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        AMRInfo_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Motor Information", Q_NULLPTR));
        AMRInfo_Label_LeftVelocity->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        VelInfo_Label_Linear->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        AMRInfo_Label_LeftMotor->setText(QApplication::translate("Form_AMMR", "Left", Q_NULLPTR));
        VelInfo_Label_Title_Linear->setText(QApplication::translate("Form_AMMR", "Linear\n"
"(m/s)", Q_NULLPTR));
        AMRInfo_Label_Angle->setText(QApplication::translate("Form_AMMR", "Angle(\302\260)", Q_NULLPTR));
        AMRInfo_Label_RightAngle->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        VelInfo_Label_Title_Angular->setText(QApplication::translate("Form_AMMR", "Angular\n"
"(rad/s)", Q_NULLPTR));
        AMRInfo_Label_Velocity->setText(QApplication::translate("Form_AMMR", "Velocity\n"
"(RPM)", Q_NULLPTR));
        VelInfo_Label_Title_Top->setText(QApplication::translate("Form_AMMR", "AMR\n"
"Velocity", Q_NULLPTR));
        AMRInfo_Label_RightMotor->setText(QApplication::translate("Form_AMMR", "Right", Q_NULLPTR));
        AMRInfo_Label_RightVelocity->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        AMRInfo_Label_LeftAngle->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        AMRInfo_Btn_TorqueSwitch->setText(QApplication::translate("Form_AMMR", "ON", Q_NULLPTR));
        AMRInfo_Label_LeftID->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        VelInfo_Label_Angular->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        AMRInfo_Label_RightID->setText(QApplication::translate("Form_AMMR", "-", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form_AMMR", "Occupancy MAP", Q_NULLPTR));
        Conveyor_lineEdit_Angle->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_title_velocity->setText(QApplication::translate("Form_AMMR", "Velocity", Q_NULLPTR));
        Conveyor_label_title_torque->setText(QApplication::translate("Form_AMMR", "Torque", Q_NULLPTR));
        Conveyor_label_velocity_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_angle_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_ID_1->setText(QApplication::translate("Form_AMMR", "2", Q_NULLPTR));
        Conveyor_label_torque_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_title_angle->setText(QApplication::translate("Form_AMMR", "Angle", Q_NULLPTR));
        Conveyor_label_ID_2->setText(QApplication::translate("Form_AMMR", "3", Q_NULLPTR));
        Conveyor_label_angle_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_velocity_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_lineEdit_Velocity->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_label_torque_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Conveyor_btn_Rot->setText(QApplication::translate("Form_AMMR", "Rotate", Q_NULLPTR));
        Conveyor_btn_Put->setText(QApplication::translate("Form_AMMR", "Put", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Form_AMMR", "Conveyor(AGV Only)", Q_NULLPTR));
        Tab_System->setTabText(Tab_System->indexOf(Tab_AMR), QApplication::translate("Form_AMMR", "AMR", Q_NULLPTR));
        ArmMotorInfo_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Motor Info.", Q_NULLPTR));
        Arm_label_velocity_3->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_torque_3->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_3->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_5->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_torque->setText(QApplication::translate("Form_AMMR", "Torque", Q_NULLPTR));
        Arm_label_ID_3->setText(QApplication::translate("Form_AMMR", "3", Q_NULLPTR));
        Arm_label_torque_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_4->setText(QApplication::translate("Form_AMMR", "4", Q_NULLPTR));
        Arm_label_angle_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_torque_5->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_torque_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_velocity_1->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_0->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_1->setText(QApplication::translate("Form_AMMR", "1", Q_NULLPTR));
        Arm_label_torque_4->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_2->setText(QApplication::translate("Form_AMMR", "2", Q_NULLPTR));
        Arm_label_torque_0->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_velocity_0->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_5->setText(QApplication::translate("Form_AMMR", "5", Q_NULLPTR));
        Arm_label_velocity_2->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_0->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_4->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_velocity_4->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_velocity_5->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_velocity->setText(QApplication::translate("Form_AMMR", "Velocity", Q_NULLPTR));
        Arm_label_title_angle->setText(QApplication::translate("Form_AMMR", "Angle", Q_NULLPTR));
        ArmPosition_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Position", Q_NULLPTR));
        Arm_label_title_currentRot->setText(QApplication::translate("Form_AMMR", "Rot", Q_NULLPTR));
        Arm_label_currentPosY->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_currentPos->setText(QApplication::translate("Form_AMMR", "Pos", Q_NULLPTR));
        Arm_label_title_currentZ->setText(QApplication::translate("Form_AMMR", "Z", Q_NULLPTR));
        Arm_label_currentRotY->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_currentRotZ->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_currentY->setText(QApplication::translate("Form_AMMR", "Y", Q_NULLPTR));
        Arm_label_currentPosX->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_currentX->setText(QApplication::translate("Form_AMMR", "X", Q_NULLPTR));
        Arm_label_currentPosZ->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_currentRotX->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_lineEdit_Oz->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_controlY->setText(QApplication::translate("Form_AMMR", "Y", Q_NULLPTR));
        Arm_label_title_controlPos->setText(QApplication::translate("Form_AMMR", "Pos", Q_NULLPTR));
        Arm_label_title_controlX->setText(QApplication::translate("Form_AMMR", "X", Q_NULLPTR));
        Arm_lineEdit_Y->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_lineEdit_Z->setText(QApplication::translate("Form_AMMR", "300", Q_NULLPTR));
        Arm_lineEdit_Oy->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_lineEdit_Ox->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_controlZ->setText(QApplication::translate("Form_AMMR", "Z", Q_NULLPTR));
        Arm_lineEdit_X->setText(QApplication::translate("Form_AMMR", "300", Q_NULLPTR));
        Arm_label_title_controlRot->setText(QApplication::translate("Form_AMMR", "Rot", Q_NULLPTR));
        Arm_btn_Start->setText(QApplication::translate("Form_AMMR", "ON", Q_NULLPTR));
        Arm_btn_Stop->setText(QApplication::translate("Form_AMMR", "OFF", Q_NULLPTR));
        Arm_btn_PosGo->setText(QApplication::translate("Form_AMMR", "Go", Q_NULLPTR));
        ArmRotation_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Rotation", Q_NULLPTR));
        Arm_label_title_velocity_2->setText(QApplication::translate("Form_AMMR", "Velocity", Q_NULLPTR));
        Arm_label_title_armRot->setText(QApplication::translate("Form_AMMR", "Rot", Q_NULLPTR));
        Arm_lineEdit_Angle->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_ID_6->setText(QApplication::translate("Form_AMMR", "6", Q_NULLPTR));
        Arm_label_velocity_6->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_torque_6->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_angle_6->setText(QApplication::translate("Form_AMMR", "0", Q_NULLPTR));
        Arm_label_title_angle_2->setText(QApplication::translate("Form_AMMR", "Angle", Q_NULLPTR));
        Arm_label_title_torque_2->setText(QApplication::translate("Form_AMMR", "Torque", Q_NULLPTR));
        Arm_btn_RotGo->setText(QApplication::translate("Form_AMMR", "Go", Q_NULLPTR));
        Gripper_GroupBox->setTitle(QApplication::translate("Form_AMMR", "Gripper", Q_NULLPTR));
        Arm_btn_GripperOn->setText(QApplication::translate("Form_AMMR", "ON", Q_NULLPTR));
        Arm_btn_GripperOff->setText(QApplication::translate("Form_AMMR", "OFF", Q_NULLPTR));
        Tab_System->setTabText(Tab_System->indexOf(Tab_Manipulator), QApplication::translate("Form_AMMR", "Manipulator", Q_NULLPTR));
        AMMR_Btn_Reconnect->setText(QApplication::translate("Form_AMMR", "Reconnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form_AMMR: public Ui_Form_AMMR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_AMMR_H
