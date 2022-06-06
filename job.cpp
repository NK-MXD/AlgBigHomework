#include "job.h"

Job::Job()
{

}

Job::Job(QString name,QDate endDate,int number)
{
    this->summary=name;
    this->endDate=endDate;
    this->number=number;
}

QString Job::getSummary()const{
    return this->summary;
}
QDate Job::getDate()const{
    return this->endDate;
}
int Job::getNumber()const{
    return this->number;
}

void Job::changeNumber(int k){
    this->number=this->number+k;
}


bool cmp( const Job a,  const Job b)
{
    QDate adate = a.getDate();
    QDate bdate = b.getDate();
    int days = adate.daysTo(bdate);
    //return a.i > b.i; // 降序
    return days>0; // 升序
}
