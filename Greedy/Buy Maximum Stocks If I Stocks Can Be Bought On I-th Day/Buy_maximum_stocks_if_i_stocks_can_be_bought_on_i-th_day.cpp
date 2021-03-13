#include<bits/stdc++.h>
using namespace std;

int maxstocks(int arr[],int n,int k)
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
        v.push_back({arr[i],i+1});
    sort(v.begin(),v.end());
    int tot=0;
    for(int i=0;i<n;i++)
    {
        int cost=v[i].first*v[i].second;
        if(cost<=k)
        {
            tot+=v[i].second;
            k-=cost;
        }
        else
        {
            tot+=k/v[i].first;
            k-=v[i].first*(k/v[i].first);
        }
    }
    return tot;
}

int main()
{
    int n,k;
    cout << "Enter the number of days\n";
    cin >> n;
    cout << "Enter the amount of money customer has\n";
    cin >> k;
    int arr[n];
    cout << "Enter the prices of stack in " << n << " days\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Maximum stocks possible - " << maxstocks(arr,n,k) << '\n';
}