#include<bits/stdc++.h>
using namespace std;

string rearrangeChars()
{
    string a;
    cin >> a;
    int arr[26]={0},n=a.size(),maxfreq=0;
    for(int i=0;i<n;i++)
    {
        int pos=int(a[i]-'a');
        arr[pos]++;
        maxfreq=max(maxfreq,arr[pos]);
    }
    if((n%2!=0 && maxfreq<=(n+1)/2) || (n%2==0 && maxfreq<=n/2))
        return "1\n";
    return "0\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        cout << rearrangeChars();
}