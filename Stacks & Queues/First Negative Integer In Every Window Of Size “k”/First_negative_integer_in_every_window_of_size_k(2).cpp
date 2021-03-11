#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

void firstNeg(int arr[],int n,int k)
{
    queue<int>q;
    int j=0;
    while(j<k)
    {
        if(arr[j]<0)
            q.push(j);
        j++;
    }
    int i=1;
    while(j<=n)
    {
        if(!q.empty() && arr[q.front()]<0)
        {
            cout << arr[q.front()] << " ";
            if(q.front()<i)
                q.pop();
        }
        else
            cout << "0 ";
        if(j==n)
            break;
        if(arr[j]<0)
            q.push(j);
        j++;
        i++;
    }
    cout << '\n';
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int k;
        cin >> k;
        firstNeg(arr,n,k);
    }
    return 0;
}