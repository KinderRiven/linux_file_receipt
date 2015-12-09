#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include "headfile.h"

namespace Ui {
class messageBox;
}

class messageBox : public QWidget
{
    Q_OBJECT

public:
    explicit messageBox(QWidget *parent = 0);
    ~messageBox();
    void myShow(QString qstr, int type);

private slots:
    void on_btn_ok_clicked();

private:
    Ui::messageBox *ui;
};

#endif // MESSAGEBOX_H
