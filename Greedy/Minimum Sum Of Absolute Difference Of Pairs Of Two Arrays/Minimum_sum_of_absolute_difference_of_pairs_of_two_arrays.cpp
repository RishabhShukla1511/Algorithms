#include<bits/stdc++.h>
using namespace std;

int minSumofadjPairs(int a[],int b[],int n)
{
    sort(a,a+n);
    sort(b,b+n);
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=abs(a[i]-b[i]);
    return sum;
}

int main()
{
    int n;
    cout << "Enter the length\n";
    cin >> n;
    int a[n];
    cout << "Enter the first array\n";
    for(int i=0;i<n;i++)
        cin >> a[i];
    int b[n];
    cout << "Enter the second array\n";
    for(int i=0;i<n;i++)
        cin >> b[i];
    cout << "Minimum sum of absolute difference of pairs is " << minSumofadjPairs(a,b,n);
}