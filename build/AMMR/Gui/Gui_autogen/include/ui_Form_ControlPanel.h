/********************************************************************************
** Form generated from reading UI file 'Form_ControlPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_CONTROLPANEL_H
#define UI_FORM_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ControlPanel
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Control_Btn_AMMR;
    QPushButton *Control_Btn_CircularAMR;
    QPushButton *Control_Btn_AGV;
    QPushButton *Control_Btn_Strategy;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Form_ControlPanel)
    {
        if (Form_ControlPanel->objectName().isEmpty())
            Form_ControlPanel->setObjectName(QStringLiteral("Form_ControlPanel"));
        Form_ControlPanel->resize(204, 361);
        Form_ControlPanel->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        centralWidget = new QWidget(Form_ControlPanel);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(12);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Control_Btn_AMMR = new QPushButton(centralWidget);
        Control_Btn_AMMR->setObjectName(QStringLiteral("Control_Btn_AMMR"));
        Control_Btn_AMMR->setMinimumSize(QSize(150, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        Control_Btn_AMMR->setFont(font);
        Control_Btn_AMMR->setMouseTracking(true);
        Control_Btn_AMMR->setStyleSheet(QStringLiteral("background-color: rgb(196, 248, 255);"));

        verticalLayout->addWidget(Control_Btn_AMMR);

        Control_Btn_CircularAMR = new QPushButton(centralWidget);
        Control_Btn_CircularAMR->setObjectName(QStringLiteral("Control_Btn_CircularAMR"));
        Control_Btn_CircularAMR->setMinimumSize(QSize(150, 60));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans CJK TC"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        Control_Btn_CircularAMR->setFont(font1);
        Control_Btn_CircularAMR->setStyleSheet(QStringLiteral("background-color: rgb(255, 196, 248);"));

        verticalLayout->addWidget(Control_Btn_CircularAMR);

        Control_Btn_AGV = new QPushButton(centralWidget);
        Control_Btn_AGV->setObjectName(QStringLiteral("Control_Btn_AGV"));
        Control_Btn_AGV->setMinimumSize(QSize(150, 60));
        Control_Btn_AGV->setFont(font1);
        Control_Btn_AGV->setStyleSheet(QStringLiteral("background-color: rgb(239, 245, 213);"));

        verticalLayout->addWidget(Control_Btn_AGV);

        Control_Btn_Strategy = new QPushButton(centralWidget);
        Control_Btn_Strategy->setObjectName(QStringLiteral("Control_Btn_Strategy"));
        Control_Btn_Strategy->setMinimumSize(QSize(150, 60));
        Control_Btn_Strategy->setFont(font);
        Control_Btn_Strategy->setMouseTracking(true);
        Control_Btn_Strategy->setStyleSheet(QStringLiteral("background-color: rgb(246, 219, 255);"));

        verticalLayout->addWidget(Control_Btn_Strategy);

        Form_ControlPanel->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Form_ControlPanel);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 204, 22));
        Form_ControlPanel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Form_ControlPanel);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Form_ControlPanel->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Form_ControlPanel);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Form_ControlPanel->setStatusBar(statusBar);

        retranslateUi(Form_ControlPanel);

        QMetaObject::connectSlotsByName(Form_ControlPanel);
    } // setupUi

    void retranslateUi(QMainWindow *Form_ControlPanel)
    {
        Form_ControlPanel->setWindowTitle(QApplication::translate("Form_ControlPanel", "Form_ControlPanel", Q_NULLPTR));
        Control_Btn_AMMR->setText(QApplication::translate("Form_ControlPanel", "AMMR", Q_NULLPTR));
        Control_Btn_CircularAMR->setText(QApplication::translate("Form_ControlPanel", "Circular AMR", Q_NULLPTR));
        Control_Btn_AGV->setText(QApplication::translate("Form_ControlPanel", "AGV", Q_NULLPTR));
        Control_Btn_Strategy->setText(QApplication::translate("Form_ControlPanel", "Strategy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form_ControlPanel: public Ui_Form_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_CONTROLPANEL_H
