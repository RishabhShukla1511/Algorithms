#include<bits/stdc++.h>
using namespace std;

string containsReduntantParenthesis(string expr)
{
    int n=expr.length();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        if(expr[i]!=')')
            s.push(expr[i]);
        else
        {
            if(s.top()=='(')
                return "Yes\n";
            int cnt=0;
            while(!s.empty())
            {
                if(s.top()=='(')
                    break;
                s.pop();
                if(s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')
                    cnt=1;
            }
            s.pop();
            if(cnt==0)
                return "Yes\n";
        }
    }
    return "No\n";
}

int main()
{
    string expr;
    cin >> expr;
    cout << containsReduntantParenthesis(expr);
}