#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q)
{
    if(q.empty())
        return;
    int val=q.front();
    q.pop();
    reverse(q);
    q.push(val);
}

void interleaveTwoHalves(queue<int>&q)
{
    int cnt=0,n=q.size();
    stack<int>f,s;
    while(cnt!=n/2)
    {
        f.push(q.front());
        q.pop();
        cnt++;
    }
    while(cnt!=n)
    {
        s.push(q.front());
        q.pop();
        cnt++;
    }
    while(!f.empty())
    {
        q.push(s.top());
        q.push(f.top());
        s.pop();
        f.pop();
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
    reverse(q);
    display(q);
}