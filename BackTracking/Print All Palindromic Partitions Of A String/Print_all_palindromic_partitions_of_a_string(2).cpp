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

void palindromeParts(string str,vector<string>&pal)
{
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        string temp="";
        for(int j=i;j<n;j++)
        {
            temp+=str[j];
            if(isPalindrome(temp))
                pal.push_back(temp);
        }
    }
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    vector<string>pal;
    int n=str.length();
    palindromeParts(str,pal);
    if(pal.size()==0)
        cout << "There are No Palindrome partitions for " << str;
    else
    {
        for(auto str:pal)
            cout << str << " ";
    }
}