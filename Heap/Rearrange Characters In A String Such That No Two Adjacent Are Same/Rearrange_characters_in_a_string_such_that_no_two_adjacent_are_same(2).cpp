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
        string ans="";
        char prev='#';
        int freq=-1;
        while(!pq.empty())
        {
            char curr=pq.top().second;
            int f=pq.top().first;
            pq.pop();
            ans+=curr;
            f--;
            if(freq>0)
                pq.push({freq,prev});
            prev=curr;
            freq=f;
        }
        if(ans.length()!=n)
            return "";
        return ans;
    }
};