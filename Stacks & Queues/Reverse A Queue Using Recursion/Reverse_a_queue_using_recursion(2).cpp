//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends

void reverse(queue<int>&q)
{
    if(q.empty())
        return;
    int val=q.front();
    q.pop();
    reverse(q);
    q.push(val);
}

//function Template for C++

queue<int> rev(queue<int> q)
{
    // add code here.
    reverse(q);
    return q;
}