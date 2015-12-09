#include "messagebox.h"
#include "ui_messagebox.h"

messageBox::messageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageBox)
{
    ui->setupUi(this);

    if(BUTTON_STYLE)
        ui->btn_ok->setFlat(true);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

messageBox::~messageBox()
{
    delete ui;
}

void messageBox::myShow(QString qstr, int type){

    ui->lab_message->setText(qstr);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    move(QPoint((screenRect.width() - width() )/ 2,
                (screenRect.height() - height())/ 2));

    if(type == 0)
        ui->btn_ok->hide();
    else if(type == 1)
        ui->btn_ok->show();

    show();
}

void messageBox::on_btn_ok_clicked(){
    hide();
}
