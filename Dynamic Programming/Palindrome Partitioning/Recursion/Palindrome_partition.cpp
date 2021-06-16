#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int n=str.length();
    for(int i=0;i<=n/2;i++)
    {
        if(str[i]!=str[n-i-1])
            return false;
    }
    return true;
}

int palindrome_partitionUtil(string str,int i,int j)
{
    if(i>=j)
        return 0;
    string substring = str.substr(i,j-i+1);
    if(isPalindrome(substring))
        return 0;
    int temp=j-i+1;
    for(int k=i;k<j;k++)
        temp=min(temp,palindrome_partitionUtil(str,i,k)+palindrome_partitionUtil(str,k+1,j)+1);
    return temp;
}

int palindrome_partition(string str)
{
    int n=str.length();
    return palindrome_partitionUtil(str,0,n-1);
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    cout << "Minimum splits for Palindrome Partition are " << palindrome_partition(str);
}