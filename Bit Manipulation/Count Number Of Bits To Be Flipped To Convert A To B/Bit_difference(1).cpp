//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int countSetbits(int a)
    {
        int cnt=0;
        while(a>0)
        {
            if(a%2)
                cnt++;
            a/=2;
        }
        return cnt;
    }
    
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int axorb=a^b;
        return countSetbits(axorb);
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