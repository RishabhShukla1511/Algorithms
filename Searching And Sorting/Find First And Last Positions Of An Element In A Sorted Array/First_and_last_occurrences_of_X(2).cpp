#include<bits/stdc++.h>
using namespace std;

int findFirstoccur(int arr[],int x,int l,int h)
{
    int mid=(l+h)/2;
    while(l<h)
    {
        if(arr[mid]<x)
            return findFirstoccur(arr,x,mid+1,h);
        else if(arr[mid]>x)
            return findFirstoccur(arr,x,l,mid-1);
        else
            return findFirstoccur(arr,x,l,mid);
    }
    if(arr[l]==x)
        return l;
    return -1;
}

int findLastoccur(int arr[],int x,int l,int h)
{
    int mid=(l+h)/2+1;
    while(l<h)
    {
        if(arr[mid]<x)
            return findLastoccur(arr,x,mid+1,h);
        else if(arr[mid]>x)
            return findLastoccur(arr,x,l,mid-1);
        else
            return findLastoccur(arr,x,mid,h);
    }
    return h;
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
        pos1=findFirstoccur(arr,x,0,n-1);
        if(pos1!=-1)
        {
            pos2=findLastoccur(arr,x,0,n-1);
            cout << pos1 << " " << pos2 << '\n';
        }
        else
            cout << "-1\n";
    }
}