#ifndef SENDFILEWINDOW_H
#define SENDFILEWINDOW_H


#include <QMainWindow>
#include <QtGui>
#include <QSplitter>
#include <QDirModel>
#include "headfile.h"
#include "crecvserver.h"
#include "csendclient.h"
#include "messagebox.h"
#include "settingwindow.h"

namespace Ui {
class SendFileWindow;
}

class SendFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SendFileWindow(QWidget *parent = 0);
    void setFileData(const QString &path, const QString &name);
    void killPorc(int pid);
    ~SendFileWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::SendFileWindow *ui;
    QString fileName;
    QString filePath;
    QPoint mousePos;
    messageBox box;
    settingWindow setting;
    bool DEBUG;
    pid_t childPid;

};

#endif // SENDFILEWINDOW_H
