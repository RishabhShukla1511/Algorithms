#include<bits/stdc++.h>
using namespace std;

bool isSafe(string a,int i,int j)
{
    if(i>=0 && i<a.size() && j>=0 && j<a.size())
        return true;
    return false;
}
 
string find(string a,int i,int j)
{
    if(isSafe(a,i,j))
    {
        if(a[i]==a[j])
        {
            i--;
            j++;
            return find(a,i,j);
        }
        else
            return a.substr(i+1,j-i-1);
    }
    else if(i>=0 && j>=a.size())
        return a.substr(i+1,j-i);
    else if(i<0 && j<a.size())
        return a.substr(i+1,j-i-1);
    else
        return a.substr(i+1,j-i-1);
}

string longPal(string a,int pos)
{
    string s="";
    s+=a[pos];
    if(pos+1<a.size() && a[pos]==a[pos+1])
        s=find(a,pos,pos+1);
    if(pos-1>=0 && pos+1<a.size() && a[pos-1]==a[pos+1])
    {
        string t=find(a,pos,pos);
        if(t.size()>s.size())
            s=t;
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,ans;
        cin >> a;
        ans=a[0];
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            string temp=longPal(a,i);
            if(temp.size()>ans.size())
                ans=temp;
        }
        cout << ans << '\n';
    }
}