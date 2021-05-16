#include<bits/stdc++.h>
using namespace std;

int permCoeff(int n,int k,vector<vector<int>>&p)
{
    if(k>n)
        return 0;
    if(p[n][k]!=-1)
        return p[n][k];
    p[n][k]=permCoeff(n-1,k,p)+k*permCoeff(n-1,k-1,p);
    return p[n][k];
}

int main()
{
    int n,k;
    cout << "Enter the value of N\n";
    cin >> n;
    cout << "Enter the value of K\n";
    cin >> k;
    vector<vector<int>>p;
    vector<int>temp(k+1,-1);
    for(int i=0;i<=n;i++)
        p.push_back(temp);
    for(int i=0;i<=k;i++)
        p[0][i]=0;
    for(int i=0;i<=n;i++)
        p[i][0]=1;
    cout << n << "P" << k << "=" << permCoeff(n,k,p); 
}