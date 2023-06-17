#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>
#include<QList>
#include"mytcpsocket.h"
class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();
    static MyTcpServer &getInstance();
    void incomingConnection(qintptr socketDescriptor);
    void resend(const char * pername,PDU *pdu);//转发给客户端


    //定义一个槽函数进行关联
public slots:
    void deleteSocket(MyTcpSocket *mysocket);


private:
    QList<MyTcpSocket*>m_tcpSocketList;
};

#endif // MYTCPSERVER_H
