#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        float f=log2(N);
        int a=int(f);
        if(f!=a)
            return -1;
        return a+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends