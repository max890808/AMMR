#include <Form_Strategy.h>
#include <ui_Form_Strategy.h>

Form_Strategy::Form_Strategy(QWidget *parent):
    QDialog(parent),
	ui(new Ui::Form_Strategy)
{
	ui->setupUi(this);
	std::string strStrategy;

	// mfFile_strategy_name.open(std::string(getenv("PWD")) + "/src/AMMR/Strategy/name.txt");
	mfFile_strategy_name.open(std::string("/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/Strategy/name.txt"));
	if(mfFile_strategy_name.is_open())
	{
		while(getline(mfFile_strategy_name, strStrategy))
		{
			std::cout << "Found Stratefy: "<< strStrategy << std::endl;
			ui->comboBox_SelectStrategy->addItem(QString::fromStdString(strStrategy));
		} 
	}
	else
	{
		std::cout << "Load Strategy error, place the name of strategy in: " << 
					std::string(getenv("PWD")) + "/src/Strategy/name.txt" << std::endl;
	}

	mfFile_strategy_name.close();
	mpStrategy = new Strategy();
}

Form_Strategy::~Form_Strategy()
{
	delete mpStrategy;
	this->deleteLater();		
	delete ui;
}

void Form_Strategy::on_button_RunStrategy_clicked()
{
	ui->button_RunStrategy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"));
	ui->button_RunStrategy->setEnabled(false);
	ui->comboBox_SelectStrategy->setEnabled(false);

	mptStrategy = new std::thread(&Strategy::select_strategy, mpStrategy, ui->comboBox_SelectStrategy->currentText().toStdString());
}

void Form_Strategy::on_button_EndStrategy_clicked()
{
	mpStrategy->terminate_strategy();
	if(mptStrategy->joinable())
	{
		mptStrategy->join();
	}
	
	ui->button_RunStrategy->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"));
	ui->button_RunStrategy->setEnabled(true);
	ui->comboBox_SelectStrategy->setEnabled(true);
}

void Form_Strategy::on_button_ClearLog_clicked()
{
	ui->listWidget_StrategyStageLog->clear();
}