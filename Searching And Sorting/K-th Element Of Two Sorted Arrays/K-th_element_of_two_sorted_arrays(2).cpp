#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int findKelement(int A[],int B[],int N,int M,int k)
{
    int a=0,b=0,posinsortedarr=0;
    while(a!=N && b!=M)
    {
        posinsortedarr++;
        if(A[a]<B[b])
        {
            if(posinsortedarr==k)
                return A[a];
            a++;
        }
        else
        {
            if(posinsortedarr==k)
                return B[b];
            b++;
        }
    }
    while(a!=N)
    {
        posinsortedarr++;
        if(posinsortedarr==k)
            return A[a];
        a++;
    }
    while(b!=M)
    {
        posinsortedarr++;
        if(posinsortedarr==k)
            return B[b];
        b++;
    }
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