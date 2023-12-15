#ifndef FORM_MANIPULATOR_H
#define FORM_MANIPULATOR_H

#include <QtCore/QObject>
#include <QLabel>
#include "AMMR/AMMR.h"

namespace Ui {
class Form_AMMR;
}

class Form_Manipulator : public QObject
{
    Q_OBJECT

public:
    Form_Manipulator(Ui::Form_AMMR *_ui, QObject *parent = nullptr);
    ~Form_Manipulator(){};
    void SetAMMR(AMMR *_AMMR)
    {
        mpAMMR = _AMMR;
        mpManipulator = _AMMR->mpManipulator;
    }
    void Display();
    void SetBtnState(bool bEnable);

private slots:
    void on_Arm_btn_PosGo_clicked();
    // void on_Arm_btn_ImpedancePosGo_clicked();
    void on_Arm_btn_RotGo_clicked();
    void on_Arm_btn_GripperOn_clicked();
    void on_Arm_btn_GripperOff_clicked();
    void on_Arm_btn_Start_clicked();
    void on_Arm_btn_Stop_clicked();

// System
private:
    Ui::Form_AMMR *ui;
    AMMR *mpAMMR;
    Manipulator *mpManipulator;

    void isOK(bool checked_thing, QLabel *label);
    void Red(QLabel *label);
    void Green(QLabel *label);

    static int time_tick_;

    const int torque_threshold;
};
#endif // FORM_MANIPULATOR_H