#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
 *  Login Window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txt_pwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    setWindowFlags(Qt::FramelessWindowHint);

    setWindowOpacity(0.9f);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    move(QPoint((screenRect.width() - width() )/ 2,
                (screenRect.height() - height())/ 2));

    if(BUTTON_STYLE){
        ui->btn_login->setFlat(true);
        ui->btn_exit->setFlat(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        mousePos = event->pos();
        //printf("Mouse Press at(%d %d)\n", mousePos.x(), mousePos.y());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        QPoint nowPos = event->pos();
        int x = nowPos.x() - mousePos.x();
        int y = nowPos.y() - mousePos.y();
        //printf("Mouse Move at(%d %d)\n", x, y);
        move(QPoint(pos().x() + x, pos().y() + y));
    }
}

void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}

void MainWindow::on_btn_login_clicked()
{
    this->hide();
    sendFileWindow.show();
}
