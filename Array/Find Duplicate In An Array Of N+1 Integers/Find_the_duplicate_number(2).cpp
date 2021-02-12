class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int arr[n],val;
        for(int i=0;i<n;i++)
            arr[i]=0;
        for(int i=0;i<n;i++)
            arr[nums[i]]++;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>=2)
            {
                val=i;
                break;
            }
        }
        return val;
    }
};