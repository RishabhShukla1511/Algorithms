// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    
    int eval(int a,int b,char c)
    {
        if(c=='+')
            return b+a;
        else if(c=='-')
            return b-a;
        else if(c=='*')
            return b*a;
        else if(c=='/')
            return b/a;
    }
    
    // The main function that returns value of a given postfix expression
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>s;
        int n=S.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(S[i]))
                s.push(S[i]-'0');
            else
            {
                int a=s.top(),b;
                s.pop();
                b=s.top();
                s.pop();
                s.push(eval(a,b,S[i]));
            }
        }
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends