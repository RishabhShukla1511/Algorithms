#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(pq.size()<k)
                pq.push(sum);
            else
            {
                if(pq.top()<sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    if(pq.size()==k)
        return pq.top();
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