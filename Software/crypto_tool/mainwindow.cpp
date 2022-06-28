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

    ui->lcdNumber_totalchips->display(0);
    ui->lcdNumber_failchips->display(0);
    ui->lcdNumber_passchips->display(0);

    QPalette palette;
    palette = ui->lcdNumber_totalchips->palette();
    QColor color(255, 0, 0);
//    # foreground color
//    palette.setColor(palette.WindowText, QtGui.QColor(85, 85, 255))
//    # background color
    palette.setColor( palette.Light, color);
    palette.setColor( palette.Dark, color);
//    # "light" border
//    palette.setColor(palette.Light, QtGui.QColor(255, 0, 0))
//    # "dark" border
//    palette.setColor(palette.Dark, QtGui.QColor(0, 255, 0))


   ui->lcdNumber_totalchips->setPalette(palette);
   ui->lcdNumber_failchips->setPalette(palette);
   ui->lcdNumber_passchips->setPalette(palette);
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
    mavlink_message_t rmsg;
    mavlink_status_t status;
    QByteArray data = serial->readAll();
    mavlink_sync_t sync_cmd;

    uint8_t parse_state;
    //ui->textEdit->append(QString::number(data.length()));
    //serial->clear(QSerialPort::AllDirections);
    //ui->textEdit->append(data.toStdString().c_str());

    //serial->write(data);




    for(int i=0;i<data.length();i++){
        parse_state = mavlink_parse_char(MAVLINK_COMM_0, (uint8_t)data[i], &rmsg, &status);

    }

        if(parse_state) {
            switch (rmsg.msgid) {
                case MAVLINK_MSG_ID_Sync:


                    //mavlink_msg_sync_decode(&rmsg,&sync_cmd);
                    ui->textEdit->append(QString("Device is detected"));
                    this->isSync = true;

                    //board is detected
                    break;
                case MAVLINK_MSG_ID_Program_ack :
                    ui->textEdit->append(QString("Device is programming... "));

                    mavlink_msg_program_ack_decode(&rmsg,&program_ack);

                    if(program_ack.status&(1<<0)){
                        ui->textEdit->append(QString("config zone is locked"));
                    }

                    if(program_ack.status&(1<<1)){
                        ui->textEdit->append(QString("data zone is locked"));
                    }
                    if(program_ack.status&(1<<2)){
                        ui->textEdit->append(QString("write config slot is ok"));
                    }
                    if(program_ack.status&(1<<3)){
                        ui->textEdit->append(QString("write key slot is ok"));
                    }
                    break;
                case MAVLINK_MSG_ID_verify_ack :
                    mavlink_msg_verify_ack_decode(&rmsg,&verify_ack);
                    //do something
                    if(verify_ack.status == 0x55){
                        ui->textEdit->append(QString("verify pass"));
                        //emit the signal to handle
                    }else{
                        ui->textEdit->append(QString("verify fail"));
                    }

                    break;
                case MAVLINK_MSG_ID_device_sn:
                    mavlink_msg_device_sn_decode(&rmsg,&device_sn);
                    QByteArray arr;
                    for(int i=0;i<9;i++){
                        arr.push_back(device_sn.sn[i]);
                    }
                    ui->textEdit->append(QString(arr.toHex()));
                    //ui->textEdit->append(QString("Device id is ..."));
                break;

            }
        }





    // parse_state = mavlink_parse_char(MAVLINK_COMM_0, (uint8_t)value[i], &rmsg, &status);




}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonProgram_clicked()
{
    //serial->write("Hello");
    this->sendProgramCmd();
    this->addDeviceTabieItem("1234","1234","1234","1234");
    ui->statusbar->showMessage("Busy",300);
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
//    serial->flush();
//    while(serial->waitForReadyRead(100));
//    {
//        serial->clear(QSerialPort::AllDirections);
//    }
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
   // this->setSyncCmd();


}
void MainWindow::setSyncCmd(){
    mavlink_message_t msg;
    mavlink_status_t status;
    mavlink_sync_t sync;
    uint8_t len;
    uint8_t rdata[200];
    sync.status=1;
    mavlink_msg_sync_encode(0,0,&msg,&sync);
    len = mavlink_msg_to_send_buffer(rdata, &msg);
    serial->write((const char *)rdata,len);
}
void MainWindow::sendProgramCmd(){
    mavlink_message_t msg;
    mavlink_status_t status;
    mavlink_program_t program;
    uint8_t len;
    uint8_t rdata[200];
    QByteArray tdata;
    mavlink_msg_program_encode(0,0,&msg,&program);
    len = mavlink_msg_to_send_buffer(rdata, &msg);
    for (int i=0 ; i<len;i++){
        tdata.push_back(rdata[i]);
    }
    serial->write(tdata);
}

