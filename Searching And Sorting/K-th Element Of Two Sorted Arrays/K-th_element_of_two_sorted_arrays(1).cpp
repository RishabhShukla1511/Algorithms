#include<bits/stdc++.h>
using namespace std;
int main()
{
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
        int a=0,b=0,posinsortedarr=0;
        while(a!=N && b!=M)
        {
            posinsortedarr++;
            if(A[a]<B[b])
            {
                if(posinsortedarr==k)
                {
                    cout << A[a] << '\n';
                    break;
                }
                a++;
            }
            else
            {
                if(posinsortedarr==k)
                {
                    cout << B[b] << '\n';
                    break;
                }
                b++;
            }
        }
        while(a!=N)
        {
            posinsortedarr++;
            if(posinsortedarr==k)
            {
                cout << A[a] << '\n';
                break;
            }
            a++;
        }
        while(b!=M)
        {
            posinsortedarr++;
            if(posinsortedarr==k)
            {
                cout << B[b] << '\n';
                break;
            }
            b++;
        }
    }
}