/**
 * \author          Twaha Bakari Kabika
 * \Supervisor      Prof. Dr. Boris R. Bracio
 * \Institution     Anhalt University of Applied Sciences, Kothen, Germany.
 * \version          1.0
 * \date             March  2018
 * \Environment      LINUX - Raspbian jessie
 * \Addition Library Qtcustom Plot Version 2.o
                     BITalino C++ API
 *
 * This Program is Submitted in fulfillment for the requirement
   for the Degree of Master of Science in Biomedical Engineering.
 * This Programm is capable of connecting and collecting data from Five Analog Inputs
   (EMG, ECG, EDA,EEG and ACC) Sensors of a BITalino (r)evolution Board.
 * This Program also offer four Selection: File format, Mode, Channel and Sampling Rate selection
 * Also this program saves all the measured data to a file called ECDMA
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qprocess.h"
#include "bitalino.h"
#include "QMessageBox"
#include "QApplication"
#include "QtCore"
#include "QMessageBox"
#include "qcustomplot.h"

using namespace std;

// Variable Initilization and file decralation
FILE  *allsignalfile;
int SampTime = 0;
double EMGmv  = 0;
double ECGmv  = 0;
double EDAus  = 0;
double EEGuv  = 0;
double ACCg   = 0;
bool BtnStop = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //Set Default selection  on channel select option as a Default option
    ui->Checkbox_default->setChecked(true);

//Sampling Rate Combo Box Setting
    ui->comboBox_Fileformat->addItem("csv");
    ui->comboBox_Fileformat->addItem("txt");
    ui->comboBox_Fileformat->addItem("hdf5");

//Sampling Rate Combo Box Setting
    ui->comboBox_SampRate->addItem("1000 Hz");
    ui->comboBox_SampRate->addItem("100 Hz");
    ui->comboBox_SampRate->addItem("10 Hz");

//Mode Selection  Combo Box Setting
    ui->comboBox_Mode->addItem("Recording");
    ui->comboBox_Mode->addItem("Simulation");

 // EMG Graph Setup
    ui->emgplot->addGraph();
    ui->emgplot->graph(0)->setPen(QPen(QColor(40, 110, 255)));  // blue line
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
   // timeTicker->setTimeFormat("%h:%m:%s");
    timeTicker->setTimeFormat("%s");
    ui->emgplot->xAxis->setTicker(timeTicker);
    ui->emgplot->axisRect()->setupFullAxesBox();
    ui->emgplot->xAxis->setLabel("Time(s)");
    ui->emgplot->yAxis->setLabel("EMG - mVolt");
    ui->emgplot->yAxis->setRange(-1.7, 1.7);

// ECG Graph Setup
    ui->ecgplot->addGraph();
    ui->ecgplot->graph(0)->setPen(QPen(QColor(40, 110, 255))); // blue line
    timeTicker->setTimeFormat("%s");
    ui->ecgplot->xAxis->setTicker(timeTicker);
    ui->ecgplot->axisRect()->setupFullAxesBox();
    ui->ecgplot->xAxis->setLabel("Time(s)");
    ui->ecgplot->yAxis->setLabel("ECG - mVolt");
    ui->ecgplot->yAxis->setRange(-1.5, 1.5);

// EDA Graph Setup
    ui->edaplot->addGraph();
    ui->edaplot->graph(0)->setPen(QPen(QColor(40, 110, 255))); // blue line
    timeTicker->setTimeFormat("%s");
    ui->edaplot->xAxis->setTicker(timeTicker);
    ui->edaplot->axisRect()->setupFullAxesBox();
    ui->edaplot->xAxis->setLabel("Time(s)");
    ui->edaplot->yAxis->setLabel("EDA - uSiemens");
    ui->edaplot->yAxis->setRange(0, 14);

// EEG Graph Setup
    ui->eegplot->addGraph();
    ui->eegplot->graph(0)->setPen(QPen(QColor(40, 110, 255))); // blue line
    timeTicker->setTimeFormat("%s");
    ui->eegplot->xAxis->setTicker(timeTicker);
    ui->eegplot->axisRect()->setupFullAxesBox();
    ui->eegplot->xAxis->setLabel("Time(s)");
    ui->eegplot->yAxis->setLabel("EEG - uVolt");
    ui->eegplot->yAxis->setRange(-41.25, 41.25);

//ACC Graph Setup
    ui->accplot->addGraph();
    ui->accplot->graph(0)->setPen(QPen(QColor(40, 110, 255))); // blue line
    timeTicker->setTimeFormat("%s");
    ui->accplot->xAxis->setTicker(timeTicker);
    ui->accplot->axisRect()->setupFullAxesBox();
    ui->accplot->xAxis->setLabel("Time(s)");
    ui->accplot->yAxis->setLabel("ACC - gs");
    ui->accplot->yAxis->setRange(-3,3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
      try
           {
                //connection to BITalino BOard, the commends will connect and request the version of the Board
                ui->statusBar->showMessage("Connecting to device...");
                BITalino dev("/dev/serial0");
                std::string ver = dev.version();
                printf("BITalino version: %s\n", ver.c_str());
                ui->statusBar->showMessage("Device is Connected");
                BITalino::Vint chans;                               //Channel Initiliazation
                      chans.push_back(0);
                      chans.push_back(1);
                      chans.push_back(2);
                      chans.push_back(3);
                      chans.push_back(4);
                // Sampling Rate selection and Mode selection
                if((ui->comboBox_SampRate->currentText()== "1000 Hz")&&(ui->comboBox_Mode->currentText()=="Recording")){
                      dev.start(1000, chans,false);
                         }
                else if ((ui->comboBox_SampRate->currentText()== "1000 Hz")&&(ui->comboBox_Mode->currentText()=="Simulation")){
                      dev.start(1000, chans,true);
                             }
                else if ((ui->comboBox_SampRate->currentText()== "100 Hz")&&(ui->comboBox_Mode->currentText() == "Recording")){
                      dev.start(100, chans,false);
                             }
                else if ((ui->comboBox_SampRate->currentText()== "100 Hz")&&(ui->comboBox_Mode->currentText() == "Simulation")){
                      dev.start(100, chans,true);
                             }
                else if ((ui->comboBox_SampRate->currentText()== "10 Hz")&&(ui->comboBox_Mode->currentText() == "Recording")){
                      dev.start(100, chans,false);
                             }
                else{
                      dev.start(10, chans,true);
                             }
                BITalino::VFrame frames(100);
                // File format selection
                if(ui->comboBox_Fileformat->currentText()== "csv"){
                    allsignalfile = fopen("ECDMA.csv","w");
                    }
                else if (ui->comboBox_Fileformat->currentText()== "txt"){
                    allsignalfile = fopen("ECDMA.txt","w");
                    }
                else{
                     allsignalfile = fopen("ECDMA.hdf5","w");
                }
                fprintf(allsignalfile,"\t \t \t \t EMG, ECG, EDA EEG and ACC Recorded Data \n\n");
                fprintf(allsignalfile,"\t No.Sample    \t EMG (mV)  \t \t  ECG (mV)  \t  \t EDA (uS)  \t \t  EEG (uV)     \t \t  ACC (g)\n\n");

                do{
                   // beginning of data acquisiton
                        dev.read(frames);
                        const BITalino::Frame &f = frames[0];
                   // Implementation of data format equation
                        EMGmv =	((f.analog[0]*0.0032)-1.65);
                        ECGmv = ((f.analog[1]*0.0322)-16.5)/11;
                        EDAus = f.analog[2] * 0.0244;
                        EEGuv =	((f.analog[3]*0.0805)-41.25);
                        ACCg =	(f.analog[4] - 156)/52;
              //saving data to the file
                fprintf(allsignalfile," \t %d   \t\t %.4f    \t \t %.4f   \t\t %.4f   \t\t %.4f    \t\t %.4f \n",SampTime,EMGmv,ECGmv,EDAus,EEGuv,ACCg);
             // Beginning of plotting and channel selection
                if (ui->Checkbox_default->isChecked()){
                        ui->emgplot->graph(0)->addData(SampTime, EMGmv);
                        ui->emgplot->graph(0)->rescaleValueAxis(true);
                        ui->emgplot->xAxis->setRange(SampTime, 2000, Qt::AlignRight);
                        ui->emgplot->replot();

                        ui->ecgplot->graph(0)->addData(SampTime,ECGmv );
                        ui->ecgplot->graph(0)->rescaleValueAxis(true);
                        ui->ecgplot->xAxis->setRange(SampTime, 400, Qt::AlignRight);
                        ui->ecgplot->replot();

                        ui->edaplot->graph(0)->addData(SampTime,  EDAus);
                        ui->edaplot->graph(0)->rescaleValueAxis(true);
                        ui->edaplot->xAxis->setRange(SampTime, 400, Qt::AlignRight);
                        ui->edaplot->replot();

                        ui->eegplot->graph(0)->addData(SampTime,  EEGuv);
                        ui->eegplot->graph(0)->rescaleValueAxis(true);
                        ui->eegplot->xAxis->setRange(SampTime, 300, Qt::AlignRight);
                        ui->eegplot->replot();

                        ui->accplot->graph(0)->addData(SampTime,  ACCg);
                        ui->accplot->graph(0)->rescaleValueAxis(true);
                        ui->accplot->xAxis->setRange(SampTime, 200, Qt::AlignRight);
                        ui->accplot->replot();
                            }
                if (ui->Checkbox_emg->isChecked()){
                        ui->emgplot->graph(0)->addData(SampTime,  EMGmv);
                        ui->emgplot->graph(0)->rescaleValueAxis(true);
                        ui->emgplot->xAxis->setRange(SampTime, 2000, Qt::AlignRight);
                        ui->emgplot->replot();
                             }
                if (ui->Checkbox_ecg->isChecked()){
                        ui->ecgplot->graph(0)->addData(SampTime, ECGmv);
                        ui->ecgplot->graph(0)->rescaleValueAxis(true);
                        ui->ecgplot->xAxis->setRange(SampTime, 400, Qt::AlignRight);
                        ui->ecgplot->replot();
                             }
                if (ui->Checkbox_eda->isChecked()){
                        ui->edaplot->graph(0)->addData(SampTime,  EDAus);
                       // ui->edaplot->graph(0)->rescaleValueAxis(true);
                        ui->edaplot->xAxis->setRange(SampTime, 400, Qt::AlignRight);
                        ui->edaplot->replot();
                             }
                if (ui->Checkbox_eeg->isChecked()){
                        ui->eegplot->graph(0)->addData(SampTime,  EEGuv);
                        ui->eegplot->graph(0)->rescaleValueAxis(true);
                        ui->eegplot->xAxis->setRange(SampTime, 300, Qt::AlignRight);
                        ui->eegplot->replot();
                             }
                if (ui->Checkbox_acc->isChecked()){
                        ui->accplot->graph(0)->addData(SampTime,  ACCg);
                        ui->accplot->graph(0)->rescaleValueAxis(true);
                        ui->accplot->xAxis->setRange(SampTime, 200, Qt::AlignRight);
                        ui->accplot->replot();
                             }
                SampTime = SampTime+1;

                qApp -> processEvents();  // the function to check the process or status of the other function

                    }while (BtnStop==false);
                fclose(allsignalfile);   // File close
                dev.stop();             // stop the acqusition
                BtnStop=false;
                 }
       catch(BITalino::Exception &e){
             printf("BITalino exception: %s\n", e.getDescription());
             ui->statusBar->showMessage("Computer lost communication with the device...",2000);
          }
       }

void MainWindow::on_Refresh_clicked(){
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);

}

void MainWindow::on_Exit_clicked(){
    QMessageBox :: StandardButton reply = QMessageBox::question(this,"Exit","Do You Want To Exit?",QMessageBox::Yes|QMessageBox::No);
    if(reply ==QMessageBox::Yes ) {
        QApplication::quit();
    } else{
        ui->statusBar->showMessage("Exit Cancelled",1000);
    }
}

void MainWindow::on_Stop_clicked()
{
    BtnStop = true;
    ui->statusBar->showMessage("Device is not Connected. Press Start Button to Connect");

}

