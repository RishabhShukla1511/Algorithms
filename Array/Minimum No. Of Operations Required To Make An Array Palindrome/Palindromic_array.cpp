#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends

bool isPalindrome(int n)
{
    string a=to_string(n);
    for(int i=0;i<a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-i-1])
            return false;
    }
    return true;
}

/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.
    for(int i=0;i<n;i++)
    {
        if(!isPalindrome(a[i]))
            return 0;
    }
    return 1;
}