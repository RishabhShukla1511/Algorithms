#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        queue<char>q;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
            char c;
            cin >> c;
            m[c]++;
            while(!q.empty() && m[q.front()]>1)
                q.pop();
            if(m[c]==1)
                q.push(c);
            if(!q.empty())
                cout << q.front() << " ";
            else
                cout << "-1 ";
        }
        cout << '\n';
    }
}