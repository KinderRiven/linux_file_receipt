#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSplitter>
#include <QDirModel>

#include "sendfilewindow.h"
#include "headfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_btn_exit_clicked();
    void on_btn_login_clicked();

private:
    Ui::MainWindow *ui;
    QPoint mousePos;
    SendFileWindow sendFileWindow;
    QString userName;
};

#endif // MAINWINDOW_H
