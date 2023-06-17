#ifndef SHAREFILE_H
#define SHAREFILE_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QButtonGroup>
#include<QScrollArea>
#include <QCheckBox>
#include <QListWidget>

class ShareFile : public QWidget
{
    Q_OBJECT
public:
    explicit ShareFile(QWidget *parent = nullptr);

    static ShareFile &getInstance();

    void test();

    void updateFriend(QListWidget *pFriendList);


signals:
public slots:
    void cancelSelect();
    void selectAll();

    void okShare();
    void cancelShare();


private:
    QPushButton *m_pSelectAllPB;
    QPushButton *m_pCancelSelectAllPB;

    QPushButton *m_pOkPB;
    QPushButton *m_pCancelPB;

    QScrollArea *m_pSA;
    QWidget *m_pFriendW;
    QVBoxLayout *m_pFriendWVBL;

    QButtonGroup *m_pButtonGroup;
};

#endif // SHAREFILE_H
