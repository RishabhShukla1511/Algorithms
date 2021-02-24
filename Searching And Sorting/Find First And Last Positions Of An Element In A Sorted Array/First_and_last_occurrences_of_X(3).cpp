#include<bits/stdc++.h>
using namespace std;

int findFirstoccur(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}

int findLastoccur(int arr[],int n,int x)
{
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==x)
            return i;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int pos1=-1,pos2=-1;
        pos1=findFirstoccur(arr,n,x);
        if(pos1!=-1)
        {
            pos2=findLastoccur(arr,n,x);
            cout << pos1 << " " << pos2 << '\n';
        }
        else
            cout << "-1\n";
    }
}