#ifndef JOB_H
#define JOB_H
#include<QDate>


class Job
{
public:
    Job();
    Job(QString name,QDate endDate,int number);
    QString getSummary()const;
    QDate getDate()const;
    int getNumber()const;
    void changeNumber(int k);

private:
    QString summary;
    QDate endDate;
    int number;
};

bool cmp( const Job a,  const Job b);
#endif // JOB_H
