#ifndef AUTOADDEVENT_H
#define AUTOADDEVENT_H

#include <QDialog>
#include <QDate>
#include <QTime>


namespace Ui {
class AutoAddEvent;
}
/**
 * @brief The AutoAddEvent class：自动添加任务的UI窗口界面
 */
class AutoAddEvent : public QDialog
{
    Q_OBJECT

public:
    explicit AutoAddEvent(QWidget *parent = nullptr);
    ~AutoAddEvent();
    void getNewAutoEventParams(QString& summary, QDate& endDate, int& spanTime);//传递界面参数

    void accept();//验证传入参数是否合理
private:
    Ui::AutoAddEvent *ui;
};

#endif // AUTOADDEVENT_H
