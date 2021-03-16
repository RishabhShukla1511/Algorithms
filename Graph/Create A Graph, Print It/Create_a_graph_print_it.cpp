#include<bits/stdc++.h>
using namespace std;

void print(vector<int>Graph[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto val:Graph[i])
            cout << val << " ";
        cout << '\n';
    }
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices - start from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<int>Graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        int s,d;
        cout << "Enter the source and destination vertex for " << i << " edge\n";
        cin >> s >> d;
        if(s<0 || s>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            break;
        }
        Graph[s].push_back(d);
    }
    if(k==0)
    {
        print(Graph,V);
    }
}