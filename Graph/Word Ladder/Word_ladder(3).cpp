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
        queue<int>qStart,qEnd;
        qStart.push(-1);
        unordered_map<string,int>visitedStart,visitedEnd;
        visitedStart[beginWord]=1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(wordList[i]==endWord)
            {
                qEnd.push(-1); 
                visitedEnd[endWord]=1;
            }
        }
        while(!qStart.empty() && !qEnd.empty())
        {
            int a=qStart.front();
            qStart.pop();
            string str;
            if(a==-1)
                str=beginWord;
            else
                str=wordList[a];
            int m=str.length(),l=visitedStart[str];
            if(visitedEnd[str]>0)
                return visitedStart[str]+visitedEnd[str]-1;
            for(int i=0;i<m;i++)
            {
                string temp=str;
                temp[i]='*'; 
                for(int j=0;j<v[temp].size();j++)
                {
                    if(visitedStart[wordList[v[temp][j]]]==0)
                    {
                        visitedStart[wordList[v[temp][j]]]=l+1;
                        qStart.push(v[temp][j]);
                    }
                }
            }
            a=qEnd.front();
            qEnd.pop();
            if(a==-1)
                str=endWord;
            else
                str=wordList[a];
            m=str.length(),l=visitedEnd[str];
            if(visitedStart[str]>0)
                return visitedStart[str]+visitedEnd[str]-1;
            for(int i=0;i<m;i++)
            {
                string temp=str;
                temp[i]='*'; 
                for(int j=0;j<v[temp].size();j++)
                {
                    if(visitedEnd[wordList[v[temp][j]]]==0)
                    {
                        visitedEnd[wordList[v[temp][j]]]=l+1;
                        qEnd.push(v[temp][j]);
                    }
                }
            }
        }
        return 0;
    }
};