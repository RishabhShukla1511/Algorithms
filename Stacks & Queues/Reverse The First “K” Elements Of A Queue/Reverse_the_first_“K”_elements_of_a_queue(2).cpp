
#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends

void reverse(queue<int>&q,int cnt,int k)
{
    if(cnt==k)
        return;
    int val=q.front();
    q.pop();
    reverse(q,cnt+1,k);
    q.push(val);
}

//User function Template for C++

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    reverse(q,0,k);
    int n=q.size()-k;
    while(n--)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}