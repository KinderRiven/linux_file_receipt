#include "settingwindow.h"
#include "ui_settingwindow.h"

settingWindow::settingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingWindow)
{
    ui->setupUi(this);

    server_ip = "127.0.0.1";
    server_port = "2048";
    client_port = "2048";

    if(BUTTON_STYLE){
        ui->btn_cancel->setFlat(true);
        ui->btn_save->setFlat(true);
    }

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

settingWindow::~settingWindow()
{
    delete ui;
}

void settingWindow::myShow(){

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    move(QPoint((screenRect.width() - width() )/ 2,
                (screenRect.height() - height())/ 2));

    ui->txt_ip->setText(server_ip);
    ui->txt_port->setText(client_port);
    ui->txt_port2->setText(server_port);

    show();
}

void settingWindow::mousePressEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        mousePos = event->pos();
        //printf("Mouse Press at(%d %d)\n", mousePos.x(), mousePos.y());
    }
}

void settingWindow::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        QPoint nowPos = event->pos();
        int x = nowPos.x() - mousePos.x();
        int y = nowPos.y() - mousePos.y();
        //printf("Mouse Move at(%d %d)\n", x, y);
        move(QPoint(pos().x() + x, pos().y() + y));
    }
}

void settingWindow::on_btn_save_clicked(){

    server_ip = ui->txt_ip->text();
    client_port = ui->txt_port->text();
    server_port = ui->txt_port2->text();
    hide();
}

void settingWindow::on_btn_cancel_clicked(){

    hide();
}
