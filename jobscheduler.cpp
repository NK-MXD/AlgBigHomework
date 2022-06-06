#include "jobscheduler.h"
#include<algorithm>

JobScheduler::JobScheduler()
{
}

JobScheduler::JobScheduler(vector<Job>& joblist)
{
    this->joblist=joblist;
}

void JobScheduler::getResultList(vector<QString>&resultList1,
                                 vector<QString>&resultList2,vector<QString>&resultList3){
    resultList1=this->resultList1;
    resultList2=this->resultList2;
    resultList3=this->resultList3;
}
void JobScheduler::JobScheduler::AutoSchedule(){
    sort(joblist.begin(),joblist.end(),cmp);
    while (joblist.size() > 0)
    {
        resultList1.push_back(joblist[0].getSummary()); joblist[0].changeNumber(-1);
        if (joblist.size() > 1) { resultList2.push_back(joblist[1].getSummary()); joblist[1].changeNumber(-1); }
        if (joblist.size() > 2) { resultList3.push_back(joblist[2].getSummary()); joblist[2].changeNumber(-1); }

        if (joblist.size() > 2)
        {
            if (joblist[2].getNumber() == 0)joblist.erase(joblist.begin() + 2);
        }
        if (joblist.size() > 1)
        {
            if (joblist[1].getNumber() == 0)joblist.erase(joblist.begin() + 1);
        }
        if (joblist[0].getNumber() == 0)
            joblist.erase(joblist.begin());
    }
}

void JobScheduler::addJob(Job &job){
    joblist.push_back(job);
}
