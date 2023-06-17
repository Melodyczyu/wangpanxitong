#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QTcpSocket>
#include "protocol.h"
#include "opewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();//加载配置
    static TcpClient &getInstance();
    //返回一个值
    QTcpSocket &getTcpSocket();
    QString loginName();
    QString curPath();
    void setCurPath(QString strCurPath);

    //连接服务器
public slots:
    void showConnect();
    void recvMsg();
private slots:
    //void on_send_pd_clicked();

    void on_login_pb_clicked();

    void on_regist_pb_clicked();

    void on_cancel_pb_clicked();

private:
    Ui::TcpClient *ui;
    QString m_strIP;//IP
    quint16 m_usPort;//端口
    QTcpSocket m_tcpSocket;//连接服务器，和服务器数据交互
    QString m_strLoginName;//登录的用户名

    QString m_strCurPath;//当前文件夹路径
    QFile m_file;
};
#endif // TCPCLIENT_H
