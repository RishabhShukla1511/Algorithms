class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>s;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            int a=s.size();
            s.insert(nums[i]);
            if(s.size()==a)
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};