#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>v(n*n);
        for(int i=0;i<n*n;i++)
            cin >> v[i];
        sort(v.begin(),v.end());
        print(v);
    }
}