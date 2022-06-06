#include "autoaddevent.h"
#include "ui_autoaddevent.h"
#include <QMessageBox>

AutoAddEvent::AutoAddEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoAddEvent)
{
    ui->setupUi(this);
    ui->endDateEdit->setDate(QDate::currentDate());
    QValidator *validator = new QIntValidator(0,1000,this);
    ui->spanTimeEdit->setValidator(validator);
}

AutoAddEvent::~AutoAddEvent()
{
    delete ui;
}
void AutoAddEvent::getNewAutoEventParams(QString& summary, QDate& endDate, int& spanTime)
{
    summary = ui->summaryLineEdit->text();
    endDate   = ui->endDateEdit->date();
    spanTime=ui->spanTimeEdit->text().toInt();
}

void AutoAddEvent::accept()
{
    if(ui->summaryLineEdit->text().isEmpty()||ui->spanTimeEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Warning"), tr("field is empty"));
        return;
    }
    int spanTime=ui->spanTimeEdit->text().toInt();
    QDate endDate = ui->endDateEdit->date();
    QDate today=QDate::currentDate();
    int days = today.daysTo(endDate)-1;
    if(days*3<spanTime)
    {
        QMessageBox::warning(this, tr("Warning"), tr("你的规划不太合理，请考虑是否修改"));
    }
    QDialog::accept();
}
