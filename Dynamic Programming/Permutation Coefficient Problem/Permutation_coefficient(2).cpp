#include<bits/stdc++.h>
using namespace std;

int permCoeff(int n,int k)
{
    if(k>n || n==0)
        return 0;
    if(k==0)
        return 1;
    int val=1;
    for(int i=n-k+1;i<=n;i++)
        val*=i;
    return val;
}

int main()
{
    int n,k;
    cout << "Enter the value of N\n";
    cin >> n;
    cout << "Enter the value of K\n";
    cin >> k;
    cout << n << "P" << k << "=" << permCoeff(n,k); 
}