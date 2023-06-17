#include "online.h"
#include "ui_online.h"
#include<QDebug>
#include"tcpclient.h"
Online::Online(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Online)
{
    ui->setupUi(this);
}

Online::~Online()
{
    delete ui;
}

void Online::showUsr(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    uint uiSize = pdu->uiMsgLen/32;
    char caTmp[32];//定义一个临时数组
    for(uint i=0;i<uiSize;i++)
    {
        memcpy((char*)caTmp,pdu->caMsg+i*32,32);
        ui->online_lw->addItem(caTmp);
    }
}

void Online::on_addFirend_pb_clicked()
{
 QListWidgetItem *pItem = ui->online_lw->currentItem();
 QString strPerUsrName = pItem->text();
 QString strLoginName = TcpClient::getInstance().loginName();
  PDU *pdu = mkPDU(0);
  pdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_REQUEST;
  memcpy(pdu->caData,strPerUsrName.toStdString().c_str(),strPerUsrName.size());//添加谁
  memcpy(pdu->caData+32,strLoginName.toStdString().c_str(),strLoginName.size());//who i am
  TcpClient::getInstance().getTcpSocket().write((char*)pdu,pdu->uiPDULen);//消息发送出去
  free(pdu);
  pdu = NULL;
}
