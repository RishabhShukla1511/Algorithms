#include<bits/stdc++.h>
using namespace std;

int difference(vector<int>v,string temp)
{
    int sum1=0,sum2=0,n=v.size();
    for(int i=0;i<n;i++)
    {
        if(temp[i]=='1')
            sum1+=v[i];
        else
            sum2+=v[i];
    }
    return abs(sum1-sum2);
}

int count(string temp)
{
    int cnt=0,n=temp.length();
    for(int i=0;i<n;i++)
    {
        if(temp[i]=='1')
            cnt++;
    }
    return cnt;
}

void tugofWar(int pos,vector<int>v,string temp,int &diff,string &ans)
{
    int n=v.size();
    int val=count(temp);
    if(n%2==0 && val==n/2)
    {
        int d=difference(v,temp);
        if(d<diff)
        {
            diff=d;
            ans=temp;
        }
    }
    else if(n%2!=0 && (val==(n+1)/2 || val==(n-1)/2))
    {
        int d=difference(v,temp);
        if(d<diff)
        {
            diff=d;
            ans=temp;
        }
    }
    if(pos>=n)
        return;
    temp[pos]='0';
    tugofWar(pos+1,v,temp,diff,ans);
    temp[pos]='1';
    tugofWar(pos+1,v,temp,diff,ans);
}

void print(vector<int>v,string temp,int diff)
{
    int n=v.size();
    vector<int>v1,v2;
    for(int i=0;i<n;i++)
    {
        if(temp[i]=='1')
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    cout << "Minimum possible difference is : " << diff << '\n';
    cout << "Set 1: {";
    for(int i=0;i<v1.size()-1;i++)
        cout << v1[i] << ", ";
    cout << v1[v1.size()-1] << "}\n";
    cout << "Set 2: {";
    for(int i=0;i<v2.size()-1;i++)
        cout << v2[i] << ", ";
    cout << v2[v2.size()-1] << "}";
}

int main()
{
    int n;
    cout << "Enter the size of set\n";
    cin >> n;
    vector<int>v;
    string temp;
    cout << "Enter the values in set\n";
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
        temp+="0";
    }
    string ans=temp;
    int diff=INT_MAX;
    tugofWar(0,v,temp,diff,ans);
    print(v,ans,diff);
}