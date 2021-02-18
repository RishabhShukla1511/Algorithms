#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) 
{
    int n=nums.size(),k=0;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1])
        {
            k=1;
            break;
        }
    }
    if(k==1)
    {
        int a=-1,b=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                a=i;
                break;
            }
        }
        for(int i=a+1;i<n;i++)
        {
            if(nums[i]>nums[a])
            {
                if(b==-1)
                    b=i;
                else if(nums[i]<nums[b])
                    b=i;
            }
        }
        swap(nums[a],nums[b]);
        sort(nums.begin()+a+1,nums.end());
    }
    else
        reverse(nums.begin(),nums.end());
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        nextPermutation(v);
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
        cout << '\n';
    }
}