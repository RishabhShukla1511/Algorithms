//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends








//User function template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector<pair<int,int>>v;
    vector<int>taken(n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]-k>=0)
            v.push_back({arr[i]-k,i});
        v.push_back({arr[i]+k,i});
    }
    sort(v.begin(),v.end());
    int left=0,right=0,current_elements=0;
    while(right<v.size() && current_elements<n)
    {
        if(taken[v[right].second]==0)
            current_elements++;
        taken[v[right].second]++;
        right++;
    }
    int ans=v[right-1].first-v[left].first;
    while(right<v.size())
    {
        if(taken[v[left].second]==1)
        {
            current_elements--;
        }
        taken[v[left].second]--;
        left++;
        while(right<v.size() && current_elements<n)
        {
            if(taken[v[right].second]==0)
                current_elements++;
            taken[v[right].second]++;
            right++;
        }
        if(current_elements==n)
            ans=min(ans,v[right-1].first-v[left].first);
        else
            break;
    }
    return ans;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends