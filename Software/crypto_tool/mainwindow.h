#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSerialPortInfo"
#include "qserialport.h"
#include <stdint.h>
#include <QIODevice>
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
private slots:
    void on_pushButtonProgram_clicked();

    void on_pushButtonSerialOpen_clicked();

private:
    Ui::MainWindow *ui;
    void readData();
    void addDeviceTabieItem(QString SN,QString ProgramState,QString VerifyState,QString DeviceType);
    void updateDeviceTableItem();
    void deleteDeviceTableItem();
    void listAvailablePorts();
    int rowCount;
};
#endif // MAINWINDOW_H
