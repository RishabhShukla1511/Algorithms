#include<bits/stdc++.h>
using namespace std;

int count(string str)
{
    stack<char>st;
    for(int i=0;i<str.size();i++)
    {
        if(!st.empty() && st.top()=='{' && str[i]=='}')
            st.pop();
        else
            st.push(str[i]);
    }
    int open=0,close=0;
    while(!st.empty())
    {
        if(st.top()=='{')
            open++;
        else
            close++;
        st.pop();
    }
    if((open+close)%2)
        return -1;
    else if(open%2==0 && close%2==0)
        return (open+close)/2;
    else
        return (open+1)/2+(close+1)/2;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        cout << count(a) << '\n';
    }
}