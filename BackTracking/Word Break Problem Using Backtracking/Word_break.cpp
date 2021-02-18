//Time Complexity - O(N^N)
//Space Complexity - O(N^2)
#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

void validWordBreak(string ans,unordered_set<string>s,string str,int l,int r,vector<vector<string>>&ansvec)
{
    string temp=str.substr(l,r-l+1);
    if(s.find(temp)!=s.end())
    {
        ans[r]='1';
        if(r==str.size()-1)
        {
            vector<string>v;
            string a="";
            for(int i=0;i<ans.size();i++)
            {
                a+=str[i];
                if(ans[i]=='1')
                {
                    v.push_back(a);
                    a="";
                }
            }
            if(a!="")
                v.push_back(a);
            ansvec.push_back(v);
            return;
        }
        for(int i=r+1;i<str.size();i++)
            validWordBreak(ans,s,str,r+1,i,ansvec);
        ans[r]='0';
    }
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        unordered_set<string>s;
        for(int i=0;i<n;i++)
        {
            string a;
            cin >> a;
            s.insert(a);
        }
        string str;
        cin >> str;
        string word="";
        for(int i=0;i<str.size();i++)
            word+="0";
        vector<vector<string>>ansvec;
        for(int i=0;i<str.size();i++)
            validWordBreak(word,s,str,0,i,ansvec);
        if(ansvec.size()==0)
            cout << "Empty\n";
        else
        {
            for(auto v:ansvec)
            {
                cout << "(";
                for(int j=0;j<v.size()-1;j++)
                    cout << v[j] << " ";
                cout << v[v.size()-1]+")";
            }
            cout << '\n';
        }
    }
}