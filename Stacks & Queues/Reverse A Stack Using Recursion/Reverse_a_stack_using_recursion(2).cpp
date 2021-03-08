#include<bits/stdc++.h>
using namespace std;

void reverse(stack<int>&s)
{
    if(s.empty())
        return;
    int val=s.top();
    s.pop();
    reverse(s);
    s.push(val);
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
    reverse(s);
    print(s);
}