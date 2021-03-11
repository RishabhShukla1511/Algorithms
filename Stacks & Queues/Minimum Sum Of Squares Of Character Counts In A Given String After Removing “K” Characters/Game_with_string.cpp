//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int freq[26]={0};
        for(int i=0;i<s.size();i++)
            freq[s[i]-'a']++;
        priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
                pq.push(freq[i]);
        }
        while(k!=0)
        {
            int val=pq.top();
            pq.pop();
            if(val-1!=0)
                pq.push(val-1);
            k--;
        }
        int sum=0;
        while(!pq.empty())
        {
            sum+=(pq.top()*pq.top());
            pq.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends