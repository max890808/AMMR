#ifndef FORM_AMR_H
#define FORM_AMR_H

#include <QtCore/QObject>
#include <QLabel>
#include <thread>

#include "AMMR/AMMR.h"

namespace Ui {
class Form_AMMR;
}

class Form_AMR : public QObject
{
    Q_OBJECT

public:
    Form_AMR(Ui::Form_AMMR *_ui, QObject *parent = nullptr);
    ~Form_AMR(){};
    void SetAMMR(AMMR *_AMMR)
    {
        mpAMMR = _AMMR;
        mpAMR = _AMMR->mpAMR;
    }
    void Display();

private slots:
    void on_AMRInfo_Btn_TorqueSwitch_clicked();
    void on_Control_Btn_LF_clicked();
    void on_Control_Btn_SF_clicked();
    void on_Control_Btn_RF_clicked();
    void on_Control_Btn_LS_clicked();
    void on_Control_Btn_SS_clicked();
    void on_Control_Btn_RS_clicked();
    void on_Control_Btn_LB_clicked();
    void on_Control_Btn_SB_clicked();
    void on_Control_Btn_RB_clicked();
    void on_Control_Slider_FSpeed_valueChanged(int nSliderValue);
    void on_Diff_Btn_Go_clicked();
    void on_Diff_Btn_Stop_clicked();
    void on_P2P_Btn_Go_clicked();
    void on_Conveyor_btn_Put_clicked();
    void on_Conveyor_btn_Rot_clicked();

private:
    void isOK(bool checked, QWidget *widget);
    void Checked(QWidget *widget);
    void UnChecked(QWidget *widget);

// System
private:
    Ui::Form_AMMR *ui;
    AMMR *mpAMMR;
    AMR *mpAMR;

    const int torque_threshold;
};

#endif // FORM_AMR_H