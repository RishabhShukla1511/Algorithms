class Solution {
public:
    string reorganizeString(string S) {
        int maxfreq=0,n=S.length();
        if(n==1)
            return S;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
            m[S[i]]++;
            maxfreq=max(maxfreq,m[S[i]]);
        }   
        if(maxfreq>ceil(n/2.0))
            return "";
        priority_queue<pair<int,char>>pq;
        for(auto it:m)
            pq.push({it.second,it.first});
        string ans=S;
        for(int i=0;i<n;i++)
            ans[i]='1';
        while(!pq.empty())
        {
            char c=pq.top().second;
            int cnt=pq.top().first;
            pq.pop();
            int i=0;
            while(cnt>0 && i<n)
            {
                if(ans[i]=='1' && (i==0 || ans[i-1]!=c))
                {
                    ans[i]=c;
                    cnt--;
                }
                i++;
            }
            if(cnt!=0)
            {
                int k;
                for(k=n-1;k>=0;k--)
                {
                    if(ans[k]=='1')
                        break;
                }
                ans[k]=ans[0];
                ans[0]=c;
                cnt--;
            }
            if(cnt!=0)
                return "";
        }
        return ans;
    }
};