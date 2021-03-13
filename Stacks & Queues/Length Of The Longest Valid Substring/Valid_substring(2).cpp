// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int maxlength=0,open=0,close=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                maxlength=max(maxlength,2*open);
            else if(close>open)
                open=close=0;
        }
        open=0,close=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                maxlength=max(maxlength,2*close);
            else if(open>close)
                open=close=0;
        }
        return maxlength;
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