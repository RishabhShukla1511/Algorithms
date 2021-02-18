class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size(),min=200;
        if(n==0)
            return "";
        for(int i=0;i<n;i++)
        {
            if(strs[i].size()<min)
                min=strs[i].size();
        }
        int i=0;
        for(i=0;i<min;i++)
        {
            int k=0;
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=strs[0][i])
                {
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;
        }
        i--;
        if(i<0)
            return "";
        else
            return strs[0].substr(0,i+1);
    }
};