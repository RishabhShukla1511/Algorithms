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

void print(stack<int>&s)
{
    if(s.empty())
        return;
    cout << s.top()<< " ";
    s.pop();
    print(s);
}

int main()
{
    stack<int>s;
    insertAtBottom(s,1);
    insertAtBottom(s,2);
    insertAtBottom(s,3);
    insertAtBottom(s,4);
    insertAtBottom(s,5);
    print(s);
}