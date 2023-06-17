#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>
#include"protocol.h"
namespace Ui {
class PrivateChat;
}

class PrivateChat : public QWidget
{
    Q_OBJECT

public:
    explicit PrivateChat(QWidget *parent = nullptr);
    ~PrivateChat();
//单例形式
    static PrivateChat &getInstance();
   void setChatName(QString strName);//设置聊天对象
   void updateMsg(const PDU *pdu);

private slots:
    void on_sendMsg_pb_clicked();

private:
    Ui::PrivateChat *ui;
    QString m_strChatName;//保存聊天对象名字
    QString m_strLoginName;
};

#endif // PRIVATECHAT_H
