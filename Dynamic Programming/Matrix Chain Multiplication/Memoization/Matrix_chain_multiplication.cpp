#include<bits/stdc++.h>
using namespace std;

int MCMutil(int arr[],int i,int j,vector<vector<int>>&dp)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int temp=INT_MAX;
    for(int k=i;k<j;k++)
        temp=min(temp,MCMutil(arr,i,k,dp)+MCMutil(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
    return dp[i][j]=temp;
}

int MCM(int arr[],int n)
{
    vector<vector<int>>dp(n);
    vector<int>temp(n,-1);
    for(int i=0;i<n;i++)
        dp[i]=temp;
    return MCMutil(arr,1,n-1,dp);
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
    cout << "Minimum number of multiplications required = " << MCM(arr,n);
}
