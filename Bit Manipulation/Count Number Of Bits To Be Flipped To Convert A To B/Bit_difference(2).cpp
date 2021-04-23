//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    string getBinary(int a)
    {
        string ans="";
        while(a>0)
        {
            ans+=to_string(a%2);
            a/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        string f=getBinary(a),s=getBinary(b),temp="";
        if(f.length()<s.length())
            swap(f,s);
        for(int i=1;i<=f.length()-s.length();i++)
            temp+="0";
        temp+=s;
        s=temp;
        int cnt=0;
        for(int i=0;i<f.length();i++)
        {
            if(f[i]!=s[i])
                cnt++;
        }
        return cnt;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends