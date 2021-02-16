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
    set<int>s;
    for(int i=0;i<N;i++)
        s.insert(arr[i]);
    int len=1,cnt=1,prev;
    auto it=s.begin();
    prev=*it;
    it++;
    while(it!=s.end())
    {
        if(*it-prev==1)
            cnt++;
        else
            cnt=1;
        len=max(len,cnt);
        prev=*it;
        it++;
    }
    return len;
}