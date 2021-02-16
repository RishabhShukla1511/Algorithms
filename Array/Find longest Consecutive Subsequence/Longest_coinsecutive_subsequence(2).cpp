#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
    unordered_set<int>s;
    for(int i=0;i<N;i++)
        s.insert(arr[i]);
    int len=1;
    for(int i=0;i<N;i++)
    {
        int cnt=1,curr=arr[i];
        auto it=s.find(curr-1);
        if(it==s.end())
        {
            it=s.begin();
            while(it!=s.end())
            {
                curr++;
                it=s.find(curr);
                if(it!=s.end())
                    cnt++;
                else
                    break;
            }
            len=max(len,cnt);
            cnt=1;
        }
    }
    return len;
}