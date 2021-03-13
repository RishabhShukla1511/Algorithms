// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string S) {
        // code here
        int n=S.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='(')
                s.push(i);
            else
            {
                if(!s.empty() && S[s.top()]=='(')
                {
                    S[i]='1';
                    S[s.top()]='1';
                    s.pop();
                }
            }
        }
        int ans=0,curr=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]!='1')
                curr=0;
            else
                curr++;
            ans=max(ans,curr);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends