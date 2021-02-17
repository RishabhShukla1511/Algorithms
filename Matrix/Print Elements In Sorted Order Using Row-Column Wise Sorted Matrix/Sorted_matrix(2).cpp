#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void youngify(vector<vector<int>>&v,int i,int j)
{
    int down=INF,right=INF,n=v.size();
    
    if(i+1<n)
        down=v[i+1][j];
    if(j+1<n)
        right=v[i][j+1];
    
    if(down==INF && right==INF)
        return;
        
    if(down<right)
    {
        v[i][j]=down;
        v[i+1][j]=INF;
        youngify(v,i+1,j);
    }
    else
    {
        v[i][j]=right;
        v[i][j+1]=INF;
        youngify(v,i,j+1);
    }
}

int exmin(vector<vector<int>>&v)
{
    int ret=v[0][0];
    v[0][0]=INF;
    youngify(v,0,0);
    return ret;
}

void print(vector<vector<int>>&v)
{
    int n=v.size();
    for(int i=0;i<n*n;i++)
        cout << exmin(v) << " ";
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            vector<int>a;
            for(int j=0;j<n;j++)
            {
                int k;
                cin >> k;
                a.push_back(k);
            }
            v.push_back(a);
        }
        print(v);
    }
}