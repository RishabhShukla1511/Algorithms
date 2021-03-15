#include<bits/stdc++.h>
using namespace std;

int ksmallest(int arr[],int k,int n)
{
    priority_queue<int>maxheap;
    for(int i=0;i<k;i++)
        maxheap.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(arr[i]<maxheap.top())
        {
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }
    return maxheap.top();
}

int klargest(int arr[],int k,int n)
{
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int i=0;i<k;i++)
        minheap.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(arr[i]>minheap.top())
        {
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    return minheap.top();
}

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array\n";
    for(int i=0;i<n;i++)    
        cin >> arr[i];
    int k;
    cout << "Enter the value of k\n";
    cin >> k;
    if(k<1 || k>n)
        cout << "Value of k should be in [1," << n << "] range\n";
    else
    {
        cout << k << " largest number: " << klargest(arr,k,n) << '\n';
        cout << k << " smallest number: " << ksmallest(arr,k,n) << '\n';
    }
}