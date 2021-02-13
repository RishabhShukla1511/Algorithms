#include<bits/stdc++.h>
using namespace std;

int find(int h,int a,int cnt,char c)
{
    if(h<=0 || a<=0)
        return cnt-1;
    if(c!='a')
        return find(h+3,a+2,cnt+1,'a');
    else if(h-5>0 && a-10>0)
            return find(h-5,a-10,cnt+1,'w');
    return find(h-20,a+5,cnt+1,'f');
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int h,a,cnt=0;
        cin >> h >> a;
        cout << find(h,a,cnt,'q') << '\n';
    }
}