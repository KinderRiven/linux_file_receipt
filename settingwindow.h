#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "headfile.h"

namespace Ui {
class settingWindow;
}

class settingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = 0);
    ~settingWindow();
    void myShow();
    QString server_ip, server_port, client_port;

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::settingWindow *ui;
    QPoint mousePos;
};

#endif // SETTINGWINDOW_H
