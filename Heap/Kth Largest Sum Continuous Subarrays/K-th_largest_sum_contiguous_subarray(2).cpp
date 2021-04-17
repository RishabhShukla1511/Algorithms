#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[],int n,int k)
{
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            pq.push(sum);
        }
    }
    int cnt=0;
    while(!pq.empty())
    {
        if(cnt+1==k)
            return pq.top();
        pq.pop();
        cnt++;
    }
    return INT_MIN;
}

int main()
{
    int n;
    cout << "Enter the length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cout << "Enter the value of K\n";
    cin >> k;
    cout << "Kth largest sum contiguous subarray: " << kthLargestSum(arr,n,k);
}