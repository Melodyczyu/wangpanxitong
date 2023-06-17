#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
#include<QSqlDatabase>//连接数据库
#include<QSqlQuery>//查询数据库
#include<QStringList>

class OpeDB : public QObject
{
    Q_OBJECT
public:
    explicit OpeDB(QObject *parent = nullptr);
    //定义单例
    static OpeDB& getInstance();
    //初始化数据库函数
    void init();
    ~OpeDB();

    bool handleRegist(const char *name,const char *pwd);//注册
    bool handleLogin(const char *name,const char *pwd);//登录
    void handleOffline(const char *name);//处理注销操作
    QStringList handleAllOnline();//处理全部在线用户
    int handleSearchUsr(const char *name);
    int handleAddFriend(const char *pername,const char *name);
    void handleAgreeAddFriend(const char *pername, const char *name);
    QStringList handleFlushFriend(const char *name);
    bool handleDelFriend(const char *name, const char *friendName);


signals:
public slots:

private:
    //定义数据库成员
    QSqlDatabase m_db;

};

#endif // OPEDB_H
