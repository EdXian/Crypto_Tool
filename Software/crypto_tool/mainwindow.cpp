#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->statusbar->showMessage("ready",0);


    this->listAvailablePorts();
    QStringList m_TableHeader;

    ui->DevicetableWidget->setColumnCount(5);
    ui->DevicetableWidget->setRowCount(1);
    ui->DevicetableWidget->verticalHeader()->setVisible(false);
    m_TableHeader<<"Number"<<"Device"<<"program"<<"verify"<<"SN";
    ui->DevicetableWidget->setHorizontalHeaderLabels(m_TableHeader);
    ui->DevicetableWidget->setShowGrid(false);
    ui->DevicetableWidget->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->DevicetableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    rowCount = 0;

    qDebug()<<ui->DevicetableWidget->rowCount() << ui->DevicetableWidget->columnCount();


}


void MainWindow::addDeviceTabieItem(QString SN,QString ProgramState,QString VerifyState,QString DeviceType){

    QTableWidgetItem *item;
    item = new QTableWidgetItem();
    item->setText(QString::number(rowCount+1));
    ui->DevicetableWidget->setRowCount(rowCount+1);
    ui->DevicetableWidget->setItem(rowCount, 0, item);
    item = new QTableWidgetItem();
    item->setText(SN);
    ui->DevicetableWidget->setItem(rowCount, 1, item);

    item = new QTableWidgetItem();
    item->setText(ProgramState);
    ui->DevicetableWidget->setItem(rowCount, 2, item);

    item = new QTableWidgetItem();
    item->setText(VerifyState);
    ui->DevicetableWidget->setItem(rowCount, 3, item);

    item = new QTableWidgetItem();
    item->setText(DeviceType);
    ui->DevicetableWidget->setItem(rowCount, 4, item);
    rowCount++;
}


void MainWindow::updateDeviceTableItem(){

}

void MainWindow::deleteDeviceTableItem(){

}

void MainWindow::listAvailablePorts(){
    QList<QSerialPortInfo> list;
    //QSerialPortInfo
    list = QSerialPortInfo::availablePorts();
    for(int i=0;i<list.size();i++){
        qDebug()<<list[i].portName()<< list[i].manufacturer()<<list[i].description();
        ui->comboBoxSerialPort->addItem(list[i].portName());
    }
}

void MainWindow::readData(){
    const QByteArray data = serial->readAll();
    ui->textEdit->append(data.toStdString().c_str());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonProgram_clicked()
{
    this->addDeviceTabieItem("1234","1234","1234","1234");
}


void MainWindow::on_pushButtonSerialOpen_clicked()
{
    serial = new QSerialPort(this);
    serial->setPortName(ui->comboBoxSerialPort->currentText());

    if(serial->open(QIODevice::ReadWrite)){
        if(serial->isOpen()){
            qDebug()<<"Serial is open";
        }
    }
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}


