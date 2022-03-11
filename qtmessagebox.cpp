#include "qtmessagebox.h"
#include <QTimer>
#include <QApplication>

QtMessageBox::QtMessageBox(const QString &title, const QString &message):
    m_title(title),
    m_message(message)
{ }
 
void QtMessageBox::show(const QString &title, const QString &message)
{
    QEventLoop eventLoop;
    auto messageBox = new QtMessageBox(title, message);
    connect(messageBox, SIGNAL(destroyed()), &eventLoop, SLOT(quit()));
    messageBox->readyShow();
    eventLoop.exec();
}
 
void QtMessageBox::readyShow(void)
{
    this->moveToThread(qApp->thread());
    QTimer::singleShot(0, this, SLOT(onShow()));
}
 
void QtMessageBox::onShow(void)
{
    QMessageBox::information(NULL, m_title, m_message);
    this->deleteLater();
}
