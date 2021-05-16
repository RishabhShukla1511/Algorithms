//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    cpp_int nthCatalan(cpp_int arr[],int n) 
    {
        //code here
        if(arr[n]!=-1)
            return arr[n];
        cpp_int num=0;
        for(int i=0;i<n;i++)
            num+=nthCatalan(arr,i)*nthCatalan(arr,n-i-1);
        arr[n]=num;
        return num;
    }
    
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        cpp_int arr[n+1];
        arr[0]=1;
        arr[1]=1;
        for(int i=2;i<=n;i++)
            arr[i]=-1;
        return nthCatalan(arr,n);
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends