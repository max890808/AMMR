#include <Form_ControlPanel.h>
#include <ui_Form_ControlPanel.h>

Form_ControlPanel::Form_ControlPanel(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::Form_ControlPanel)
{
	ui->setupUi(this);
	mpForm_AMMR = new Form_AMMR(this);
	mpForm_Strategy = new Form_Strategy(this);
}

Form_ControlPanel::~Form_ControlPanel()
{
	delete ui;
}

void Form_ControlPanel::on_Control_Btn_AMMR_clicked()
{
	// ui->Control_Btn_CircularAMR->setEnabled(false);
	mpForm_AMMR->SetRobotType(eAMMRType::Type_AMMR);

	if (mpForm_AMMR->isHidden())
		mpForm_AMMR->show();
	else
		mpForm_AMMR->hide();
}

void Form_ControlPanel::on_Control_Btn_CircularAMR_clicked()
{
	// ui->Control_Btn_AMMR->setEnabled(false);
	mpForm_AMMR->SetRobotType(eAMMRType::Type_AMR);

	if (mpForm_AMMR->isHidden())
		mpForm_AMMR->show();
	else
		mpForm_AMMR->hide();
}

void Form_ControlPanel::on_Control_Btn_AGV_clicked()
{
	// ui->Control_Btn_AMMR->setEnabled(false);
	mpForm_AMMR->SetRobotType(eAMMRType::Type_AGV);

	if (mpForm_AMMR->isHidden())
		mpForm_AMMR->show();
	else
		mpForm_AMMR->hide();
}

void Form_ControlPanel::on_Control_Btn_Strategy_clicked()
{
	if (mpForm_Strategy->isHidden())
		mpForm_Strategy->show();
	else
		mpForm_Strategy->hide();
}

void Form_ControlPanel::closeEvent(QCloseEvent *event)
{
	if (mpForm_AMMR->isVisible())
		mpForm_AMMR->close();
	if (mpForm_Strategy->isVisible())
		mpForm_Strategy->close();
}
