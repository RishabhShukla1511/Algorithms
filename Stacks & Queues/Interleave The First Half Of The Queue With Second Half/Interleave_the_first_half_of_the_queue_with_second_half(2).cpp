#include<bits/stdc++.h>
using namespace std;

void interleaveTwoHalves(queue<int>&q)
{
    int n=q.size()/2;
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=1;i<=n;i++)
    {
        q.push(q.front());
        q.pop();
    }
    for(int i=1;i<=n;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }
}

void display(queue<int>q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements\n";
    cin >> n;
    if(n%2!=0)
        cout << "Queue size should be even\n";
    queue<int>q;
    cout << "Enter the elements\n";
    while(n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    interleaveTwoHalves(q);
    display(q);
}