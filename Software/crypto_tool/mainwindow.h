#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSerialPortInfo"
#include "qserialport.h"
#include <stdint.h>
#include <QIODevice>
#include <mavlink.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort* serial;
    void emitDeviceTableChange();
signals:
    void signalTablechange(void);
private slots:
    void on_pushButtonProgram_clicked();

    void on_pushButtonSerialOpen_clicked();
    void onDeviceTableChangeRequest();
private:
    Ui::MainWindow *ui;
    void readData();
    void addDeviceTabieItem(QString SN,QString ProgramState,QString VerifyState,QString DeviceType);
    void updateDeviceTableItem();
    void deleteDeviceTableItem();
    void updateLcdNumber();
    void listAvailablePorts();
    int rowCount;
    bool isSync;
    uint16_t passcount;
    void sendProgramCmd();
    void setSyncCmd();
    mavlink_device_sn_t device_sn;
    mavlink_program_ack_t program_ack;
    mavlink_verify_ack_t verify_ack;
};
#endif // MAINWINDOW_H
