#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
#include <QFile>
TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    //resize(500,250);
    loadConfig();
    MyTcpServer::getInstance().listen(QHostAddress(m_strIP),m_usPort);//监听
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::loadConfig()
{
    QFile file(":/server.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray baData = file.readAll();
        QString strData = baData.toStdString().c_str();
        //qDebug() << strData;
        file.close();

        //分割字符串
        strData.replace("\n"," ");
        // qDebug() << strData;

         //切分
         QStringList strList = strData.split(" ");
           /* for(int i=0;i<strList.size();i++)//测试
            {
                qDebug() << "---> " << strList[i];
            }*/
            m_strIP = strList.at(0);
            m_usPort = strList.at(1).toUShort();
            qDebug() << "IP:" << m_strIP << "port:" << m_usPort;
    }
    else
    {
        QMessageBox::critical(this,"open config","open config failed");
    }
}

