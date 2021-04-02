#include<bits/stdc++.h>
using namespace std;

bool solutionExists(int n,int m,int d,vector<pair<int,int>>&v)
{
    map<pair<int,int>,int>ma;
    ma[{0,0}]=1;
    queue<pair<int,int>>q;
    q.push({0,0});
    while(!q.empty())
    {
        int nn=q.size();
        for(int i=1;i<=nn;i++)
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            v.push_back({x,y});
            if((x==d && y==0) || (x==0 && y==d))
                return true;
            if(ma[{0,y}]==0)
            {
                ma[{0,y}]=1;
                q.push({0,y});
            }
            if(ma[{x,0}]==0)
            {
                ma[{x,0}]=1;
                q.push({x,0});
            }
            if(x-(m-y)>=0 && ma[{x-(m-y),m}]==0)
            {
                ma[{x-(m-y),m}]=1;
                q.push({x-(m-y),m});
            }
            if(y-(n-x)>=0 && ma[{n,y-(n-x)}]==0)
            {
                ma[{n,y-(n-x)}]=1;
                q.push({n,y-(n-x)});
            }
            if(ma[{n,y}]==0)
            {
                ma[{n,y}]=1;
                q.push({n,y});
            }
            if(ma[{x,m}]==0)
            {
                ma[{x,m}]=1;
                q.push({x,m});
            }
            if(x+y<=m && ma[{0,x+y}]==0)
            {
                ma[{0,x+y}]=1;
                q.push({0,x+y});
            }
            if(x+y<=n && ma[{x+y,0}]==0)
            {
                ma[{x+y,0}]=1;
                q.push({x+y,0});
            }
        }
    }
    return false;
}

void print(vector<pair<int,int>>v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        cout << v[i].first << " " << v[i].second << '\n';
}

int main()
{
    int n,m,d;
    cout << "Enter the capacity of first jug\n";
    cin >> n;
    cout << "Enter the capacity of second jug\n";
    cin >> m;
    cout << "Enter the amount of water required\n";
    cin >> d;
    vector<pair<int,int>>v;
    if(solutionExists(n,m,d,v))
    {
        cout << "Yes\n";
        print(v);
    }
    else
        cout << "No solution exists\n";
}