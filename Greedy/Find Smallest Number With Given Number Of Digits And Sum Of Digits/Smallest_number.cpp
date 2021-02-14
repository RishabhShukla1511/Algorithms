#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends





class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(D*9<S)
            return "-1";
        string num="";
        int sum=0;
        for(int i=1;i<=D;i++)
        {
            int j=0;
            if(i==1)
                j=1;
            for(;j<=9;j++)
            {
                if(sum+j+9*(D-i)>=S)
                    break;    
            }
            sum+=j;
            num+=to_string(j);
        }
        return num;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends