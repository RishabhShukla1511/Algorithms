class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map<string,vector<int>>v;
        for(int i=0;i<n;i++)
        {
            int m=wordList[i].length();
            if(wordList[i]!=beginWord)
            {
                for(int j=0;j<m;j++)
                {
                    string str=wordList[i];
                    str[j]='*';
                    v[str].push_back(i);
                }
            }
        }
        n=v.size();
        queue<pair<int,int>>q;
        q.push({-1,1});
        unordered_map<string,int>visited;
        visited[beginWord]=1;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int a=p.first;
            string str;
            if(a==-1)
                str=beginWord;
            else
                str=wordList[a];
            visited[str]=1;
            int m=str.length(),l=p.second;
            if(str==endWord)
                return l;
            for(int i=0;i<m;i++)
            {
                string temp=str;
                temp[i]='*'; 
                for(int j=0;j<v[temp].size();j++)
                {
                    if(visited[wordList[v[temp][j]]]==0)
                    {
                        visited[wordList[v[temp][j]]]=1;
                        q.push({v[temp][j],l+1});
                    }
                }
            }
        }
        return 0;
    }
};