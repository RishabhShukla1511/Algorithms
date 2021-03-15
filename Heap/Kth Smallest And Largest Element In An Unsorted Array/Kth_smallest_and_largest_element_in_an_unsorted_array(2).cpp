#include<bits/stdc++.h>
using namespace std;

int ksmallest(int arr[],int k,int n)
{
    return arr[k-1];
}

int klargest(int arr[],int k,int n)
{
    return arr[n-k];
}

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array\n";
    for(int i=0;i<n;i++)    
        cin >> arr[i];
    int k;
    cout << "Enter the value of k\n";
    cin >> k;
    if(k<1 || k>n)
        cout << "Value of k should be in [1," << n << "] range\n";
    else
    {
        sort(arr,arr+n);
        cout << k << " largest number: " << klargest(arr,k,n) << '\n';
        cout << k << " smallest number: " << ksmallest(arr,k,n) << '\n';
    }
}