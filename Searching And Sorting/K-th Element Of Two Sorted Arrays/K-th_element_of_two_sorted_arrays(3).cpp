#include<bits/stdc++.h>
using  namespace std;

int findKelement(int arr1[],int m,int arr2[],int n,int k)
{
    if(k>m+n || k<1)    
        return -1;
    if(m>n)
        return findKelement(arr2,n,arr1,m,k);
    if(m==0)
        return arr2[k-1];
    if(k==1)
        return min(arr1[0],arr2[0]);
    int i=min(m,k/2),j=min(n,k/2);
    if(arr1[i-1]>arr2[j-1])
        return findKelement(arr1,m,arr2+j,n-j,k-j);
    else
        return findKelement(arr1+i,m-i,arr2,n,k-i);
}

int main()
{
    fastIO();
    int Tests;
    cin >> Tests;
    while(Tests--)
    {
        int N,M,k;
        cin >> N >> M >> k;
        int A[N],B[M];
        for(int i=0;i<N;i++)
            cin >> A[i];
        for(int i=0;i<M;i++)
            cin >> B[i];
        cout << findKelement(A,N,B,M,k) << '\n';
    }
}