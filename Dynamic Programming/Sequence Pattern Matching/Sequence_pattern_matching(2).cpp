#include<bits/stdc++.h>
using namespace std;

bool Sequence_pattern_match(string str1,string str2)
{
    int i=0,j=0,n=str1.length(),m=str2.length();
    while(i<n && j<m)
    {
        if(str1[i]==str2[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return i==n;
}

int main()
{
    string str1,str2;
    cout << "Enter the first string\n";
    cin >> str1;
    cout << "Enter the second string\n";
    cin >> str2;
    if(Sequence_pattern_match(str1,str2))
        cout << "Yes, " << str1 << " is a subsequence of " << str2;
    else    
        cout << "No, " << str1 << " is not a subsequence of " << str2;
}