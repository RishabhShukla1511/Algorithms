#include<bits/stdc++.h>
using namespace std;

struct Meet{
    int start,finish,pos;
    Meet(int start,int finish,int pos)
    {
        this->start=start;
        this->finish=finish;
        this->pos=pos;
    }
};

bool cmp(Meet *meet1,Meet *meet2)
{
    return meet1->finish < meet2->finish;
}

vector<int> maxMeetings(int s[],int f[],int n)
{
    vector<Meet*>meets;
    for(int i=0;i<n;i++)
    {
        Meet *meet=new Meet(s[i],f[i],i+1);
        meets.push_back(meet);
    }
    sort(meets.begin(),meets.end(),cmp);
    int end=meets[0]->finish;
    vector<int>maxmeets;
    maxmeets.push_back(meets[0]->pos);
    for(int i=1;i<n;i++)
    {
        if(meets[i]->start>=end)
        {
            maxmeets.push_back(meets[i]->pos);
            end=meets[i]->finish;
        }
    }
    return maxmeets;
}

int main()
{
    int n;
    cout << "Enter the number of meetings\n";
    cin >> n;
    int s[n],f[n];
    cout << "Enter the start timings\n";
    for(int i=0;i<n;i++)
        cin >> s[i];
    cout << "Enter the finish timings\n";
    for(int i=0;i<n;i++)
        cin >> f[i];
    vector<int>maxmeets=maxMeetings(s,f,n);
    n=maxmeets.size();
    cout << "Following are the meets possible to maximize the possible number\n";
    for(int i=0;i<n;i++)
        cout << maxmeets[i] << " ";
}