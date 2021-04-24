#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    
	    void allPossibleperms(string s,string bin,vector<string>&ans,string take,int pos)
	    {
	        if(pos==bin.length())
	        {
	            ans.push_back(take);
	            return;
	        }
	        bin[pos]='0';
	        allPossibleperms(s,bin,ans,take,pos+1);
	        bin[pos]='1';
	        allPossibleperms(s,bin,ans,take+s[pos],pos+1);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string bin="",take="";
		    for(int i=1;i<=s.length();i++)
		        bin+="0";
		    vector<string>ans;
		    allPossibleperms(s,bin,ans,take,0);
		    sort(ans.begin(),ans.end());
		    ans.erase(ans.begin());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends