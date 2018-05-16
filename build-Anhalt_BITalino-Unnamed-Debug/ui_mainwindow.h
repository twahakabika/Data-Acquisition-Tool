/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCustomPlot *ecgplot;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QComboBox *comboBox_Fileformat;
    QCustomPlot *emgplot;
    QWidget *edaplot_2;
    QWidget *accplot_2;
    QWidget *eegplot_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *Checkbox_default;
    QCheckBox *Checkbox_emg;
    QCheckBox *Checkbox_ecg;
    QCheckBox *Checkbox_eda;
    QCheckBox *Checkbox_eeg;
    QCheckBox *Checkbox_acc;
    QCustomPlot *eegplot;
    QCustomPlot *accplot;
    QCustomPlot *edaplot;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Start;
    QPushButton *Stop;
    QPushButton *Refresh;
    QPushButton *Exit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_Mode;
    QLabel *label;
    QComboBox *comboBox_SampRate;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 685);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ecgplot = new QCustomPlot(centralWidget);
        ecgplot->setObjectName(QString::fromUtf8("ecgplot"));

        gridLayout->addWidget(ecgplot, 1, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(label_2, 0, Qt::AlignHCenter);

        comboBox_Fileformat = new QComboBox(centralWidget);
        comboBox_Fileformat->setObjectName(QString::fromUtf8("comboBox_Fileformat"));

        verticalLayout_7->addWidget(comboBox_Fileformat);


        gridLayout->addLayout(verticalLayout_7, 0, 1, 1, 1);

        emgplot = new QCustomPlot(centralWidget);
        emgplot->setObjectName(QString::fromUtf8("emgplot"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(emgplot->sizePolicy().hasHeightForWidth());
        emgplot->setSizePolicy(sizePolicy1);
        edaplot_2 = new QWidget(emgplot);
        edaplot_2->setObjectName(QString::fromUtf8("edaplot_2"));
        edaplot_2->setGeometry(QRect(0, 209, 453, 108));
        accplot_2 = new QWidget(emgplot);
        accplot_2->setObjectName(QString::fromUtf8("accplot_2"));
        accplot_2->setGeometry(QRect(0, 437, 453, 144));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(accplot_2->sizePolicy().hasHeightForWidth());
        accplot_2->setSizePolicy(sizePolicy2);
        eegplot_2 = new QWidget(emgplot);
        eegplot_2->setObjectName(QString::fromUtf8("eegplot_2"));
        eegplot_2->setGeometry(QRect(0, 323, 453, 108));

        gridLayout->addWidget(emgplot, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Checkbox_default = new QCheckBox(groupBox);
        Checkbox_default->setObjectName(QString::fromUtf8("Checkbox_default"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Checkbox_default->sizePolicy().hasHeightForWidth());
        Checkbox_default->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_default);

        Checkbox_emg = new QCheckBox(groupBox);
        Checkbox_emg->setObjectName(QString::fromUtf8("Checkbox_emg"));
        sizePolicy3.setHeightForWidth(Checkbox_emg->sizePolicy().hasHeightForWidth());
        Checkbox_emg->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_emg);

        Checkbox_ecg = new QCheckBox(groupBox);
        Checkbox_ecg->setObjectName(QString::fromUtf8("Checkbox_ecg"));
        sizePolicy3.setHeightForWidth(Checkbox_ecg->sizePolicy().hasHeightForWidth());
        Checkbox_ecg->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_ecg);

        Checkbox_eda = new QCheckBox(groupBox);
        Checkbox_eda->setObjectName(QString::fromUtf8("Checkbox_eda"));
        sizePolicy3.setHeightForWidth(Checkbox_eda->sizePolicy().hasHeightForWidth());
        Checkbox_eda->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_eda);

        Checkbox_eeg = new QCheckBox(groupBox);
        Checkbox_eeg->setObjectName(QString::fromUtf8("Checkbox_eeg"));
        sizePolicy3.setHeightForWidth(Checkbox_eeg->sizePolicy().hasHeightForWidth());
        Checkbox_eeg->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_eeg);

        Checkbox_acc = new QCheckBox(groupBox);
        Checkbox_acc->setObjectName(QString::fromUtf8("Checkbox_acc"));
        sizePolicy3.setHeightForWidth(Checkbox_acc->sizePolicy().hasHeightForWidth());
        Checkbox_acc->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(Checkbox_acc);


        gridLayout->addWidget(groupBox, 4, 1, 2, 1, Qt::AlignRight);

        eegplot = new QCustomPlot(centralWidget);
        eegplot->setObjectName(QString::fromUtf8("eegplot"));

        gridLayout->addWidget(eegplot, 5, 0, 1, 1);

        accplot = new QCustomPlot(centralWidget);
        accplot->setObjectName(QString::fromUtf8("accplot"));
        sizePolicy2.setHeightForWidth(accplot->sizePolicy().hasHeightForWidth());
        accplot->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(accplot, 6, 0, 1, 1);

        edaplot = new QCustomPlot(centralWidget);
        edaplot->setObjectName(QString::fromUtf8("edaplot"));

        gridLayout->addWidget(edaplot, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Start->sizePolicy().hasHeightForWidth());
        Start->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(Start);

        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        sizePolicy4.setHeightForWidth(Stop->sizePolicy().hasHeightForWidth());
        Stop->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(Stop);

        Refresh = new QPushButton(centralWidget);
        Refresh->setObjectName(QString::fromUtf8("Refresh"));
        sizePolicy4.setHeightForWidth(Refresh->sizePolicy().hasHeightForWidth());
        Refresh->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(Refresh);

        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        sizePolicy4.setHeightForWidth(Exit->sizePolicy().hasHeightForWidth());
        Exit->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(Exit);


        gridLayout->addLayout(verticalLayout_3, 6, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3, 0, Qt::AlignHCenter);

        comboBox_Mode = new QComboBox(centralWidget);
        comboBox_Mode->setObjectName(QString::fromUtf8("comboBox_Mode"));

        verticalLayout_6->addWidget(comboBox_Mode);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label, 0, Qt::AlignHCenter);

        comboBox_SampRate = new QComboBox(centralWidget);
        comboBox_SampRate->setObjectName(QString::fromUtf8("comboBox_SampRate"));
        sizePolicy4.setHeightForWidth(comboBox_SampRate->sizePolicy().hasHeightForWidth());
        comboBox_SampRate->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(comboBox_SampRate);


        gridLayout->addLayout(verticalLayout_6, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 952, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BITalino RPi BioSignal Monitor", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "File Format", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Channel Selection", 0, QApplication::UnicodeUTF8));
        Checkbox_default->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        Checkbox_emg->setText(QApplication::translate("MainWindow", "EMG  (A1)", 0, QApplication::UnicodeUTF8));
        Checkbox_ecg->setText(QApplication::translate("MainWindow", "ECG  (A2)", 0, QApplication::UnicodeUTF8));
        Checkbox_eda->setText(QApplication::translate("MainWindow", "EDA  (A3)", 0, QApplication::UnicodeUTF8));
        Checkbox_eeg->setText(QApplication::translate("MainWindow", "EEG  (A4)", 0, QApplication::UnicodeUTF8));
        Checkbox_acc->setText(QApplication::translate("MainWindow", "ACC  (A5)", 0, QApplication::UnicodeUTF8));
        Start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        Stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        Refresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Mode Selection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Sampling Rate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
