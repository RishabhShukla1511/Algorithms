//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
        //code here//Position this line where user code will be pasted.
        int x=a-b,y=b-c,z=a-c;
        if(x*y>0)
            return b;
        else if(x*z>0)
            return c;
        return a;
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