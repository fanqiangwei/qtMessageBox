#ifndef   QTMESSAGEBOX_H
#define QTMESSAGEBOX_H
#include <QMessageBox>
#include <QEventLoop>
 
class QtMessageBox: public QObject
{
    Q_OBJECT
 
private:
    const QString m_title;
    const QString m_message;
 
public:
    QtMessageBox(const QString &title, const QString &message);
 
    static void show(const QString &title, const QString &message);
 
private:
    void readyShow(void);
 
private slots:
    void onShow(void);
};


#endif