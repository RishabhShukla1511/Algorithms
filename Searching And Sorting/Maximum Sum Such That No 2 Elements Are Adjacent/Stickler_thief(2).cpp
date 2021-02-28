#include<bits/stdc++.h>
using namespace std;

int maxSteal(int arr[],int n)
{
    if(n==0)
        return 0;
    int value1=arr[0];
    if(n==1)
        return value1;
    int value2=max(arr[0],arr[1]);
    if(n==2)
        return value2;
    int max_val;
    for(int i=2;i<n;i++)
    {
        max_val=max(value1+arr[i],value2);
        value1=value2;
        value2=max_val;
    }
    return max_val;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        cout << maxSteal(arr,n) << '\n';
    }
}