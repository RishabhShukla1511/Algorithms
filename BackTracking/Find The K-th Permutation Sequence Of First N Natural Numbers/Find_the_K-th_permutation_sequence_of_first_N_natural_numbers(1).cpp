#include<bits/stdc++.h>
using namespace std;

string permute(string str,int l,int r,int k)
{
    if(l==r)
    {
        if(k==0)
            return str;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(str[l],str[i]);
            return permute(str,l+1,r,--k);
            swap(str[l],str[i]);
        }
    }
    return ans;
}

int main()
{
    cout << "Enter N and K\n";
    int N,k;
    cin >> N,k;
    string str="";
    for(int i=1;i<=N;i++)
        str+=to_string(i);
    cout << k << "th permutation of first " << N << " natural numbers is " << permute(str,0,n-1,,k);
}