#include<bits/stdc++.h>
using namespace std;

int areMirror(vector<stack<int>>&tree1,vector<queue<int>>&tree2,int n)
{
    for(int i=1;i<=n;i++)
    {
        while(!tree1[i].empty() && !tree2[i].empty())
        {
            if(tree1[i].top()!=tree2[i].front())
                return 0;
            tree1[i].pop();
            tree2[i].pop();
        }
        if(!tree1[i].empty() || !tree2[i].empty())
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,e;
        cin >> n >> e;
        vector<stack<int>>tree1(n+1);
        vector<queue<int>>tree2(n+1);
        for(int i=1;i<=e;i++)
        {
            int a,b;
            cin >> a >> b;
            tree1[a].push(b);
        }
        for(int i=1;i<=e;i++)
        {
            int a,b;
            cin >> a >> b;
            tree2[a].push(b);
        }
        cout << areMirror(tree1,tree2,n) << '\n';
    }
}