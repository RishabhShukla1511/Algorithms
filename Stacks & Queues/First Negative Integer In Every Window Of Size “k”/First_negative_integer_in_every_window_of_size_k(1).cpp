#include<bits/stdc++.h>
using namespace std;

int firstNeg(queue<int>&nums,queue<int>&negs)
{
    int val=nums.front(),ans=0;
    nums.pop();
    if(val<0)
    {
        ans=negs.front();
        negs.pop();
    }
    else
    {
        if(!negs.empty())
            ans=negs.front();
    }
    return ans;
}

int main()
{
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
        queue<int>nums,negs;
        for(int i=0;i<k;i++)
        {
            nums.push(arr[i]);
            if(arr[i]<0)
                negs.push(arr[i]);
        }
        cout << firstNeg(nums,negs) << " ";
        for(int i=k;i<n;i++)
        {
            if(arr[i]<0)
                negs.push(arr[i]);
            nums.push(arr[i]);
            cout << firstNeg(nums,negs) << " ";
        }
        cout << '\n';
    }
    return 0;
}