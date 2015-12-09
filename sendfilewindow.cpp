#include "sendfilewindow.h"
#include "ui_sendfilewindow.h"

SendFileWindow::SendFileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SendFileWindow)
{
    ui->setupUi(this);

    DEBUG = true;

    childPid = 0;

    setWindowOpacity(0.9f);

    setWindowFlags(Qt::FramelessWindowHint);

    if(BUTTON_STYLE){
        ui->pushButton_2->setFlat(true);
        ui->pushButton_3->setFlat(true);
        ui->pushButton_4->setFlat(true);
        ui->pushButton_5->setFlat(true);
        ui->pushButton_6->setFlat(true);
    }

    /*
     *  Move to screen mid
     */

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    move(QPoint((screenRect.width() - width() )/ 2,
                (screenRect.height() - height())/ 2));

    QFileSystemModel *model = new QFileSystemModel;

    model->setRootPath("/");

    ui->treeView->header()->hide();
    ui->treeView->setModel(model);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

}

SendFileWindow::~SendFileWindow()
{
    delete ui;
}

void SendFileWindow::mousePressEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        mousePos = event->pos();
        //printf("Mouse Press at(%d %d)\n", mousePos.x(), mousePos.y());
    }
}

void SendFileWindow::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons() == Qt::LeftButton){
        QPoint nowPos = event->pos();
        int x = nowPos.x() - mousePos.x();
        int y = nowPos.y() - mousePos.y();
        //printf("Mouse Move at(%d %d)\n", x, y);
        move(QPoint(pos().x() + x, pos().y() + y));
    }
}

void SendFileWindow::setFileData(const QString &path, const QString &name){

    QFileInfo fileInfo(path);

    ui->textEdit->clear();
    if(!fileInfo.exists()){
        ui->textEdit->append("File does not exist");
        return;
    }
    else if(fileInfo.isFile()){
        char buffer[BUFFER_SIZE];
        QString tmp;
        //name
        tmp = "[File Name] " + name;
        ui->textEdit->append(tmp);

        //path
        tmp = "[File Path] " + path;
        ui->textEdit->append(tmp);

        //size
        sprintf(buffer, "[File Size] %d byte", (int)fileInfo.size());
        tmp = QString(buffer);
        ui->textEdit->append(tmp);

        //QDataTime
        QString fileTime = fileInfo.created().toString("yyyy/MM/dd h:m:s");
        tmp = "\n[Created] " + fileTime;
        ui->textEdit->append(tmp);

        fileTime = fileInfo.lastRead().toString("yyyy/MM/dd h:m:s");
        tmp = "[Last Read] " + fileTime;
        ui->textEdit->append(tmp);

        fileTime = fileInfo.lastModified().toString("yyyy/MM/dd h:m:s");
        tmp = "[Last Modified] " + fileTime;
        ui->textEdit->append(tmp);

        //Readable
        tmp = "\n[Readable] ";
        if(fileInfo.isReadable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
        //Writeable
        tmp = "[Writeable] ";
        if(fileInfo.isWritable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
        //Executable
        tmp = "[Executable] ";
        if(fileInfo.isExecutable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
    }
    else if(fileInfo.isDir()){
        ui->textEdit->append("[" + name + "]" + QString(" is a Dir!"));

        QString tmp;
        //QDataTime
        QString fileTime = fileInfo.created().toString("yyyy/MM/dd h:m:s");
        tmp = "\n[Created] " + fileTime;
        ui->textEdit->append(tmp);

        fileTime = fileInfo.lastRead().toString("yyyy/MM/dd h:m:s");
        tmp = "[Last Read] " + fileTime;
        ui->textEdit->append(tmp);

        fileTime = fileInfo.lastModified().toString("yyyy/MM/dd h:m:s");
        tmp = "[Last Modified] " + fileTime;
        ui->textEdit->append(tmp);

        //Readable
        tmp = "\n[Readable] ";
        if(fileInfo.isReadable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
        //Writeable
        tmp = "[Writeable] ";
        if(fileInfo.isWritable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
        //Executable
        tmp = "[Executable] ";
        if(fileInfo.isExecutable()){
            tmp += "YES";
        }
        else
            tmp += "NO";
        ui->textEdit->append(tmp);
    }
}

/*
 * Get FilePath from treeView
 */
void SendFileWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    //printf("%d\n", index.row());

    QModelIndex _index = index;
    QString name = _index.data().toString();
    QString path = _index.data().toString();
    QString tmp;

    while(1){

        if(name == "/")
            break;

        tmp = _index.parent().data().toString();
        if(tmp != "/")
            path = tmp + "/" + path;
        else{
            path = tmp + path;
            break;
        }
        _index = _index.parent();
    }

    ui->filePath->setText(path);

    filePath = path;
    fileName = name;
    setFileData(path, name);
}

void SendFileWindow::on_pushButton_2_clicked(){

    filePath = ui->filePath->text();
    fileName = "";

    int Size = filePath.size();
    for(int i = Size - 1; i >= 0; i--){
        if(filePath[i] == '/')
            break;
        else
            fileName = filePath[i] + fileName;
    }
    setFileData(filePath, fileName);
}


void SendFileWindow::killPorc(int pid){

    char buffer[1024];
    sprintf(buffer, "kill %d", pid);
    system(buffer);
}

/*
 *  Exit
 */
void SendFileWindow::on_pushButton_4_clicked(){

    if(childPid == 0)
        exit(0);
    else{
        killPorc(childPid);
        sleep(1);
        exit(0);
    }
}

/*
 * Send File
 */
void SendFileWindow::on_pushButton_3_clicked(){

    QFileInfo fileInfo(filePath);

    if(fileInfo.exists()){

        //buiid process
        pid_t pid = fork();

        if(pid == 0){

            char tmp_name[2048];
            strcpy(tmp_name, filePath.toStdString().c_str());

            char tmp_ip[2048];
            strcpy(tmp_ip, setting.server_ip.toStdString().c_str());

            int tmp_port = setting.server_port.toInt();

            if(DEBUG){
                printf("%s %s %d\n",tmp_ip, tmp_name, tmp_port);
            }

            csendClient client(tmp_ip, tmp_name, tmp_port);

            //OK
            if(client.startRun()){
                if(DEBUG)
                    printf("Client Well!\n");
                exit(0);
            }
            //ERROR
            else{
                if(DEBUG)
                    printf("Client Error\n");
                exit(-1);
            }

        }
        else{

            ui->pushButton_3->setEnabled(false);
            int status = 0;
            wait(&status);
            ui->pushButton_3->setEnabled(true);

            if(status == 0)
                box.myShow(QString("Send Successful"), 1);
            else
                box.myShow(QString("Send Error!"), 1);

        }
    }
    else{

    }
}

/*
 *  Show Setting Window
 */
void SendFileWindow::on_pushButton_5_clicked(){
    setting.myShow();
}
/*
 * Start Receive
 */
void SendFileWindow::on_pushButton_6_clicked(){

    if(childPid == 0){

        pid_t pid = fork();
        if(pid == 0){

            int tmp_port = setting.client_port.toInt();
            crecvServer server(tmp_port);
            server.start();
            exit(0);

        }
        else{
            box.myShow(QString("Server Start"), 1);
            childPid = pid;
        }
    }
    else{
        box.myShow(QString("Server Close"), 1);
        killPorc(childPid);
        childPid = 0;
    }
}
