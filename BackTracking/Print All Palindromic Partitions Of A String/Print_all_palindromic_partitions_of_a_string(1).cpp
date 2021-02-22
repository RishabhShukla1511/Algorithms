#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int n=str.size();
    for(int i=0;i<n/2;i++)
    {
        if(str[i]!=str[n-i-1])
            return false;
    }
    return true;
}

void palindromeParts(string str,int st,int en,set<pair<pair<int,int>,string>>&s)
{
    int n=str.length();
    string temp=str.substr(st,en-st+1);
    if(isPalindrome(temp))
        s.insert({{st,en},temp});
    for(int i=en+1;i<n;i++)
        palindromeParts(str,st,i,s);
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    set<pair<pair<int,int>,string>>s;
    int n=str.length();
    for(int i=0;i<n;i++)
        palindromeParts(str,i,i,s);
    if(s.size()==0)
        cout << "There are No Palindrome partitions for " << str;
    else
    {
        for(auto str:s)
            cout << str.second << " ";
    }
}