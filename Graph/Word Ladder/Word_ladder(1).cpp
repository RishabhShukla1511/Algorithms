class Solution {
public:
    
    int cmp(string a,string b)
    {
        int cnt=0,n=a.length(),m=b.length();
        if(n!=m)
            return 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                cnt++;
            if(cnt>1)
               return 0;
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i]==beginWord)
            {
                wordList.erase(wordList.begin()+i);
                break;
            }
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string str=q.front().first;
            int cnt=q.front().second;
            if(str==endWord)
                   return cnt;
            q.pop();
            for(int i=0;i<wordList.size();i++)
            {
                if(cmp(str,wordList[i])==1)
                {
                    q.push({wordList[i],cnt+1});
                    wordList.erase(wordList.begin()+i);
                    i--;
                }
            }
        }
        return 0;
    }
};