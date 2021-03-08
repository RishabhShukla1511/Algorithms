#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c=='-')
        return 1;
    else if(c=='+')
        return 2;
    else if(c=='/')
        return 3;
    else if(c=='*')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='[' || c==']')
        return 6;
    else if(c=='{' || c=='}')
        return 7;
    else if(c=='(' || c==')')
        return 8;
}

string infixToPostfix(string expr)
{
    string postfix="";
    int n=expr.size();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        if(isupper(expr[i]))
            postfix+=expr[i];  
        else if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
            s.push(expr[i]);
        else if(expr[i]==')')
        {
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(expr[i]=='}')
        {
            while(s.top()!='{')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(expr[i]==']')
        {
            while(s.top()!='[')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && precedence(s.top())<precedence(expr[i]))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(expr[i]);
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

double evaluateVal(double a,double b,char op)
{
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else if(op=='/')
        return a/b;
    else if(op=='^')
        return pow(a,b);
}

double evaluate(string expr)
{
    string postfix=infixToPostfix(expr);
    stack<double>s;
    int n=postfix.size();
    for(int i=0;i<n;i++)
    {
        if(isupper(postfix[i]))
        {
            cout << "Enter the value of " << postfix[i] << ": ";
            double val;
            cin >> val;
            s.push(val);
        }
        else
        {
            double a=s.top();
            s.pop();
            double b=s.top();
            s.pop();
            s.push(evaluateVal(a,b,postfix[i]));
        }
    }
    return s.top();
}

int main()
{
    string expr;
    cout << "Enter the expression\n";
    cin >> expr;
    cout << "Value of evaluated expression: " << evaluate(expr);
}