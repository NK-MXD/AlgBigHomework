#ifndef JOBSCHEDULER_H
#define JOBSCHEDULER_H
#include <vector>
#include <algorithm>
#include<QDate>
#include"job.h"
using namespace std;

class JobScheduler
{
public:
    JobScheduler();
    JobScheduler(vector<Job>& joblist);
    void getResultList(vector<QString>&resultList1,vector<QString>&resultList2,vector<QString>&resultList3);
    void AutoSchedule();
    void addJob(Job &job);

private:
    vector<Job> joblist;
    vector<QString> resultList1;
    vector<QString> resultList2;
    vector<QString> resultList3;
};

#endif // JOBSCHEDULER_H
