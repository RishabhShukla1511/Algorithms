#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        stack<char>s;
        for(int i=0;i<a.size();i++)
        {
            if(s.size()==0)
                s.push(a[i]);
            else
            {
                if(a[i]==')' && s.top()=='(')
                    s.pop();
                else if(a[i]==']' && s.top()=='[')
                    s.pop();
                else if(a[i]=='}' && s.top()=='{')
                    s.pop();
                else
                    s.push(a[i]);
            }
        }
        if(s.size()==0)
            cout << "balanced\n";
        else
            cout << "not balanced\n";
    }
	return 0;
}