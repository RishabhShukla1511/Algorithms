#include<bits/stdc++.h>
using namespace std;

struct Process{
    int id,arrival_time,burst_time,turnaround_time,completion_time,waiting_time,rank;
    Process()
    {

    }
    Process(int id,int arrival_time,int burst_time)
    {
        this->id=id;
        this->arrival_time=arrival_time;
        this->burst_time=burst_time;
        this->rank=0;
    }
};

bool cmp1(Process *process1,Process *process2)
{
    if(process1->burst_time!=process2->burst_time)
        return process1->burst_time<process2->burst_time;
    if(process1->arrival_time!=process2->arrival_time)
        return process1->arrival_time<process2->arrival_time;
    return process1->id<process2->id;
}

bool cmp2(Process *process1,Process *process2)
{
    return process1->rank<process2->rank;
}

void display(Process *arr[],int n)
{
    cout<<"Rank\tProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time     Completion time\n"; 
    for(int i=0;i<n;i++)
        cout << arr[i]->rank << "\t\t" << arr[i]->id << "\t\t" << arr[i]->arrival_time << "\t\t" << arr[i]->burst_time << "\t\t" << arr[i]->waiting_time << "\t\t" << arr[i]->turnaround_time << "                    " << arr[i]->completion_time << "\n"; 
}

int main()
{
    cout << "Non Preemptive Shortest Job First Scheduling Algorithm\nAlgorithm:\n1) Sort all processes according to the arrival time.\n2) Then select that process which has minimum arrival time and minimum Burst time.\n3) After completion of process make a pool of process which after till the completion of previous process and select that process among the pool which is having minimum Burst time.\n";
    int n;
    cout << "Enter the number of processes\n";
    cin >> n;
    Process *arr[n];
    int minarrival=-1,pos=-1;
    for(int i=1;i<=n;i++)
    {
        Process *process=new Process();
        cout << "Enter id for process " << i << ": ";
        cin >> process->id;
        cout << "Enter arrival time for process " << i << ": ";
        cin >> process->arrival_time;
        cout << "Enter burst time for process " << i << ": ";
        cin >> process->burst_time;
        arr[i-1]=process;
        if(minarrival==-1 || minarrival>process->arrival_time)
        {
            minarrival=process->arrival_time;
            pos=i-1;
        }
    }
    sort(arr,arr+n,cmp1);
    int end=0,val=2;
    for(int i=0;i<n;i++)
    {
        if(arr[i]->arrival_time==minarrival)
            arr[i]->rank=1;
        else
            arr[i]->rank=val++;
    }
    sort(arr,arr+n,cmp2);
    for(int i=0;i<n;i++)
    {
        end+=arr[i]->burst_time;
        arr[i]->completion_time=end;
        arr[i]->turnaround_time=arr[i]->completion_time-arr[i]->arrival_time;
        arr[i]->waiting_time=arr[i]->turnaround_time-arr[i]->burst_time;
    }
    display(arr,n);
}