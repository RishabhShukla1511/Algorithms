#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int pageFaults(int pageseq[],int n,int capacity)
{
    vector<int>v;
    unordered_set<int>s;
    int faults=1,si=1;
    v.push_back(pageseq[0]);
    s.insert(pageseq[0]);
    for(int i=1;i<n;i++)
    {
        auto it=s.find(pageseq[i]);
        if(it!=s.end())
        {
            if(pageseq[i]!=v[si-1])
            {
                int j;
                for(j=0;j<si;j++)
                {
                    if(v[j]==pageseq[i])
                        break;
                }
                v.erase(v.begin()+j);
                v.push_back(pageseq[i]);
                s.erase(it);
                s.insert(pageseq[i]);
            }
        }
        else
        {
            if(si<capacity)
            {
                v.push_back(pageseq[i]);
                si++;
                s.insert(pageseq[i]);
                faults++;
            }
            else
            {
                it=s.find(v[0]);
                s.erase(it);
                s.insert(pageseq[i]);
                faults++;
                for(int j=1;j<si;j++)
                    v[j-1]=v[j];
                if(v.size()<capacity)
                {
                    v.push_back(pageseq[i]);
                    si++;
                }
                else
                    v[capacity-1]=pageseq[i];
            }
        }
    }
    return faults;
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int pageseq[n];
        for(int i=0;i<n;i++)
            cin >> pageseq[i];
        int capacity;
        cin >> capacity;
        cout << pageFaults(pageseq,n,capacity) << '\n';
    }
}