#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

void printTanksandTaps()
{
    int n,p;
    cin >> n >> p;
    pair<int,int> arr[n+1];
    for(int i=0;i<=n;i++)
        arr[i]={-1,-1};
    bool visited[n+1]={0},incoming[n+1]={0};
    for(int i=0;i<p;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        arr[a]={b,d};
        incoming[b]=1;
    }
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && arr[i].first!=-1 && !incoming[i])
        {
            int start=i,end=i,mind=arr[i].second,j=arr[i].first;
            visited[i]=1;
            while(arr[j].first!=-1)
            {
                mind=min(mind,arr[j].second);
                visited[j]=1;
                j=arr[j].first;
            }
            end=j;
            v.push_back(start);
            v.push_back(end);
            v.push_back(mind);
        }
    }
    n=v.size();
    cout << n/3 << '\n';
    for(int i=0;i<n;i+=3)
        cout << v[i] << " " << v[i+1] << " " << v[i+2] << '\n';
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
        printTanksandTaps();
}