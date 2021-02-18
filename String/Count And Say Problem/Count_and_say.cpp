class Solution {
public:
    
    string say(string s)
    {
        string ans="";
        int cnt=1,n=s.size();
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
                cnt++;
            else
            {
                ans+=to_string(cnt);
                ans+=s[i-1];
                cnt=1;
            }
        }
        cnt=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==s[i-1])
                cnt++;
            else
                break;
        }
        ans+=to_string(cnt);
        ans+=s[n-1];
        return ans;
    }
    
    string countAndSay(int n) {
        string a="1";
        for(int i=2;i<=n;i++)
            a=say(a);
        return a;
    }
};