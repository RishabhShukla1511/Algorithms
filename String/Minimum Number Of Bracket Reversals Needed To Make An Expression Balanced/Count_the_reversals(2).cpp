#include<bits/stdc++.h>
using namespace std;

int countReversals(string str)
{
    if(str.size()%2!=0)
        return -1;
    stack<char>st;
    for(int i=0;i<str.size();i++)
    {
        if(!st.empty() && st.top()=='{' && str[i]=='}')
            st.pop();
        else
            st.push(str[i]);
    }
    float open=0,close=0;
    while(!st.empty())
    {
        if(st.top()=='{')
            open++;
        else
            close++;
        st.pop();
    }
    return ceil(open/2)+ceil(close/2);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        cout << countReversals(a) << '\n';
    }
}