#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int findKelement(int A[],int B[],int N,int M,int k)
{
    if(N>M)
        return findKelement(B,A,M,N,k);
    if(N==0)
        return B[k-1];
    if(k==1)
        return min(A[0],B[0]);
    int i=min(N,k/2),j=min(M,k/2);
    if(A[i-1]<B[j-1])
        return findKelement(A+i,B,N-i,M,k-i);
    else
        return findKelement(A,B+j,N,M-j,k-j);
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
        cout << findKelement(A,B,N,M,k) << '\n';
    }
}