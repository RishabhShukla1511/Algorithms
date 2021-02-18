class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(),min=200;
        if(n==0)
            return "";
        for(int i=0;i<n;i++)
        {
            if(strs[i].size()<min)
                min=strs[i].size();
        }
        string ans="";
        for(int i=0;i<min;i++)
        {
            int k=0;
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=strs[0][i])
                {
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};