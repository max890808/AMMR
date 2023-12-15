#ifndef FORM_AMMR_H
#define FORM_AMMR_H

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <thread>
#include <vector>

#include "Form_AMR.h"
#include "Form_Manipulator.h"
#include "Form_VLSensor.h"
#include "AMMR/AMMR.h"

namespace Ui {
class Form_AMMR;
}

class Form_AMMR : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form_AMMR(QWidget *parent = nullptr);
    ~Form_AMMR();

public:
    void SetRobotType(eAMMRType nRobotType);
    eAMMRType mnRobotType;

private:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void SetForm();

private slots:
    void on_AMMR_Btn_Reconnect_clicked();
    void Display();

private:
    Ui::Form_AMMR *ui;
    Form_AMR *mpForm_AMR;
    Form_Manipulator *mpForm_Manipulator;
    Form_VLSensor *mpForm_VLSensor;

    AMMR *mpAMMR;

    QThread *mpQThread_AMMR;

	// Display
    QTimer *mpTimerDisplay;
};

#endif // FORM_AMMR_H