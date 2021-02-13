class Solution {
public:
    void nextPermutation(vector<int>& nums) {
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
            for(int i=n-1;i>=0;i--)
            {
                for(int j=i-1;j>a && j>=0;j--)
                {
                    if(nums[j]<nums[i])
                    {
                        a=j;
                        b=i;
                        break;
                    }
                }
            }
            swap(nums[a],nums[b]);
            sort(nums.begin()+a+1,nums.end());
        }
        else
            reverse(nums.begin(),nums.end());
    }
};