#include<bits/stdc++.h>
using namespace std;

int pour(int fromcap,int tocap,int d)
{
    int from=fromcap,to=0,steps=1;
    while(from!=d || to!=d)
    {
        int amo=min(from,tocap-to);
        from-=amo;
        to+=amo;
        steps++;
        if(from==d || to==d)
            return steps;
        if(from==0)
        {
            from=fromcap;
            steps++;
        }
        if(to==tocap)
        {
            steps++;
            to=0;
        }
    }
    return steps;
}

int minSteps(int n,int m,int d)
{
    if(m>n)
        swap(m,n);
    if(d>n && d%__gcd(n,m)!=0)
        return -1;
    return min(pour(n,m,d),pour(m,n,d));
}

int main()
{
    int n,m,d;
    cout << "Enter the capacity of first jug\n";
    cin >> n;
    cout << "Enter the capacity of second jug\n";
    cin >> m;
    cout << "Enter the amount of water required\n";
    cin >> d;
    vector<pair<int,int>>v;
    cout << "Minimum number of steps required: " << minSteps(n,m,d);
}