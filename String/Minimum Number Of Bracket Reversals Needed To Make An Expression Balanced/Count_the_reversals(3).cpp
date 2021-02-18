#include<bits/stdc++.h>
using namespace std;

int countReversals(string str)
{
    if(str.size()%2)
        return -1;
    float open=0,close=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='{')
            open++;
        else
        {
            if(open>0)
                open--;
            else
                close++;
        }
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