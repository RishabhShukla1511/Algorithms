#include<bits/stdc++.h>
using namespace std;

void remAdjDuplicates(string &s,int pos)
{
    if(pos<s.size())
    {
        if(s[pos]==s[pos-1])
        {
            s.erase(s.begin()+pos);
            remAdjDuplicates(s,pos);
        }
        else
            remAdjDuplicates(s,pos+1);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        remAdjDuplicates(s,1);
        cout << s << '\n';
    }
}