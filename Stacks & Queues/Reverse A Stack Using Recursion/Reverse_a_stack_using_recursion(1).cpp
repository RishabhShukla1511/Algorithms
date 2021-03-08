#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s,int val)
{
    if(s.empty())
        s.push(val);
    else
    {
        int a=s.top();
        s.pop();
        insertAtBottom(s,val);
        s.push(a);
    }
}

void reverseInsertBottom(stack<int>&s,int cnt)
{
    if(cnt==s.size())
        return;
    int a=s.top();
    s.pop();
    insertAtBottom(s,a);
    reverseInsertBottom(s,cnt+1);
}

void print(stack<int>&s)
{
    if(s.empty())
        return;
    cout << s.top() << " ";
    s.pop();
    print(s);
}

int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseInsertBottom(s,0);
    print(s);
}