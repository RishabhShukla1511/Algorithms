#include<bits/stdc++.h>
using namespace std;

void print(stack<pair<int,int>>&s)
{
    if(s.empty())
        return;
    pair<int,int>a=s.top();
    s.pop();
    print(s);
    cout << a.first << " " << a.second << '\n';
    return;
}

void mergeIntervals(vector<pair<int,int>>v)
{
    sort(v.begin(),v.end());
    int n=v.size();
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
            s.push(v[i]);
        else
        {
            pair<int,int>si=v[i],fi=s.top();
            if(si.first<=fi.second)
            {
                s.pop();
                if(si.second<=fi.second)
                    s.push({fi.first,fi.second});
                else
                    s.push({fi.first,si.second});
            }
            else
                s.push(si);
        }
    }
    cout << "Merged Intervals:\n";
    print(s);
    return;
}

int main()
{
    int n;
    cout << "Enter number of intervals\n";
    cin >> n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cout << "Enter the " << i+1 << " interval\n";
        cin >> a >> b;
        v.push_back({min(a,b),max(a,b)});
    }
    mergeIntervals(v);
    return 0;
}