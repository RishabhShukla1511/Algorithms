class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int a=-1,b=-1;
        for(int i=n-1;i>=0;i--)
        {
            int k=0;
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
        if(a==-1 && b==-1)
            reverse(nums.begin(),nums.end());
        else
        {
            swap(nums[a],nums[b]);
            sort(nums.begin()+a+1,nums.end());
        }
    }
};