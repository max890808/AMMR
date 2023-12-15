#ifndef FORM_CONTROLPANEL_H
#define FORM_CONTROLPANEL_H

#include <QtWidgets/QMainWindow>
#include "Form_AMMR.h"
#include "Form_Strategy.h"

namespace Ui {
class Form_ControlPanel;
}

class Form_ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form_ControlPanel(QWidget *parent = nullptr);
    ~Form_ControlPanel();

private:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_Control_Btn_AMMR_clicked();
    void on_Control_Btn_CircularAMR_clicked();
    void on_Control_Btn_Strategy_clicked();
    void on_Control_Btn_AGV_clicked();

private:
    Ui::Form_ControlPanel *ui;

    Form_AMMR *mpForm_AMMR;
    Form_Strategy *mpForm_Strategy;
};

#endif // FORM_CONTROLPANEL_H
