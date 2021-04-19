//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    string findSum(string a,string b)
    {
        if(a.size()<b.size())
            swap(a,b);
        int n=a.length(),m=b.length();
        reverse(b.begin(),b.end());
        for(int i=1;i<=n-m;i++)
            b+="0";
        reverse(b.begin(),b.end());
        string ans="";
        int carry=0;
        for(int i=n-1;i>=0;i--)
        {
            int sum=(a[i]-'0')+(b[i]-'0')+carry;
            carry=sum/10;
            ans.push_back(sum%10+'0');
        }
        if(carry!=0)
            ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string a="",b="";
        for(int i=0;i<n;i+=2)
        {
            if(arr[i]!=0)
                a+=to_string(arr[i]);
        }
        for(int i=1;i<n;i+=2)
        {
            if(arr[i]!=0)
                b+=to_string(arr[i]);
        }
        return findSum(a,b);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends