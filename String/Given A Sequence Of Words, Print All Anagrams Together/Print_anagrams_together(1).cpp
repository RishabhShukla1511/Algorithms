//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends





//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    int n=string_list.size();
    map<map<char,int>,vector<string>>m;
    for(int i=0;i<n;i++)
    {
        map<char,int>temp;
        for(int j=0;j<string_list[i].size();j++)
            temp[string_list[i][j]]++;
        m[temp].push_back(string_list[i]);
    }
    vector<vector<string>>ans;
    for(auto it:m)
    {
        vector<string>v;
        for(int i=0;i<it.second.size();i++)
            v.push_back(it.second[i]);
        ans.push_back(v);
    }
    return ans;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends