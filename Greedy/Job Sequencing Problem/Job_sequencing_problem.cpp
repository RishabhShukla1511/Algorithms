#include<bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int deadline,profit;
    Job(char id,int deadline,int profit)
    {
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};

bool cmp(Job *job1,Job *job2)
{
    if(job1->profit!=job2->profit)
        return job1->profit>job2->profit;
    return job1->deadline<job2->deadline;
}

int jobSequencing(Job *arr[],int n,int maxdead,vector<pair<int,char>>&jobseq)
{
    sort(arr,arr+n,cmp);
    int slot[maxdead+1]={0},profit=0;
    slot[arr[0]->deadline]=1;
    profit+=arr[0]->profit;
    jobseq.push_back({arr[0]->deadline,arr[0]->id});
    for(int i=1;i<n;i++)
    {
        int k=0;
        for(int j=arr[i]->deadline;j>=1;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                jobseq.push_back({j,arr[i]->id});
                profit+=arr[i]->profit;
                break;
            }
        }
    }
    return profit;
}

int main()
{
    int n;
    cout << "Enter the number of processes\n";
    cin >> n;
    Job* arr[n];
    cout << "Enter the process's id, deadline and profit\n";
    int maxdead=0;
    for(int i=0;i<n;i++)
    {
        char id;
        int deadline,profit;
        cin >> id >> deadline >> profit;
        Job *job=new Job(id,deadline,profit);
        arr[i]=job;
        maxdead=max(maxdead,deadline);
    }
    vector<pair<int,char>>jobseq;
    cout << "Maximum profit possible by sequencing of theses jobs is " << jobSequencing(arr,n,maxdead,jobseq) << '\n';
    sort(jobseq.begin(),jobseq.end());
    cout << "The sequence of jobs is for maximum profit is\n";
    for(auto it:jobseq)
        cout << it.second << " ";
}