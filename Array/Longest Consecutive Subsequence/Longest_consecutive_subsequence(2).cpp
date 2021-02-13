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
    int len=1,cnt=1,curr;
    auto it1=s.begin(),it2=s.begin();
    while(s.size())
    {
        it1=s.begin();
        it2=it1;
        curr=*it1;
        while(it2!=s.end())
        {
            it2=s.find(curr+1);
            if(it2!=s.end())
            {
                cnt++;
                curr=*it2;
                s.erase(it2);
            }
            else
                break;
        }
        it2=it1;
        curr=*it1;
        while(it2!=s.end())
        {
            it2=s.find(curr-1);
            if(it2!=s.end())
            {
                cnt++;
                curr=*it2;
                s.erase(it2);
            }
            else
                break;
        }
        s.erase(it1);
        len=max(len,cnt);
        cnt=1;
        it1++;
    }
    return len;
}