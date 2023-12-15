#ifndef FORM_STRATEGY_H
#define FORM_STRATEGY_H

#include <QtWidgets/QDialog>
#include "Strategy/Strategy.h"
#include <fstream>
#include <iostream>
#include <thread>

namespace Ui {
class Form_Strategy;
}

class Form_Strategy : public QDialog
{
	Q_OBJECT

public:
	explicit Form_Strategy(QWidget *parent = nullptr);
	~Form_Strategy();

private slots:
	void on_button_RunStrategy_clicked();
	void on_button_EndStrategy_clicked();
	void on_button_ClearLog_clicked();

private:
	Ui::Form_Strategy *ui;
	std::fstream mfFile_strategy_name;
	std::thread *mptStrategy;
	Strategy *mpStrategy;
};

#endif // FORM_STRATEGY_H
