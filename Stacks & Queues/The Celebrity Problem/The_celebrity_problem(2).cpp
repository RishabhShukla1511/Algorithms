#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    int m=0,i,j,ans;
    for(i=0;i<n;i++)
    {
        int k=0;
        for(j=0;j<n;j++)
        {
            if(M[i][j]==1)
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {
            m++;
            ans=i;
        }
    }
    if(m==1)
        return ans;
    return -1;
}