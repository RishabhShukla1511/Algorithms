//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
        //code here//Position this line where user code will be pasted.
        if(a>b)
        {
            if(b>c)
                return b;
            else if(c>a)
                return a;
            return c;
        }
        else
        {
            if(c<a)
                return a;
            else if(c<b)
                return c;
            return b;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends