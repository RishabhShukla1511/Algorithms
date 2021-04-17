#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long minCost(long long arr[], long long n) {
    // Your code here
    long long sum=0;
    priority_queue<long long,vector<long long>,greater<long long>>q(arr,arr+n);
    while(q.size()!=1)
    {
        long long a=q.top();
        q.pop();
        long long b=q.top();
        q.pop();
        q.push(a+b);
        sum+=a+b;
    }
    return sum;
}