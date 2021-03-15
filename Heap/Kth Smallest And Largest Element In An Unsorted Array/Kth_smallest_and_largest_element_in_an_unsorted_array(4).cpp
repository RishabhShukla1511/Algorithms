#include<bits/stdc++.h>
using namespace std;

int minPartition(int arr[],int l,int r)
{
    int pivot=arr[r],j=l;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[r]);
    return j;
}

int maxPartition(int arr[],int l,int r)
{
    int pivot=arr[r],j=l;
    for(int i=l;i<r;i++)
    {
        if(arr[i]>=pivot)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[r]);
    return j;
}

int ksmallest(int arr[],int l,int r,int k,int n)
{
    if(k>0 && k<=r-l+1)
    {
        int index=minPartition(arr,l,r);
        if(index-l==k-1)
            return arr[index];
        else if(index-l<k-1)
            return ksmallest(arr,index+1,r,k+l-index-1,n);
        return ksmallest(arr,l,index-1,k,n);
    }
    return INT_MIN;
}

int klargest(int arr[],int l,int r,int k,int n)
{
    if(k>0 && k<=r-l+1)
    {
        int index=maxPartition(arr,l,r);
        if(index-l==k-1)
            return arr[index];
        else if(index-l<k-1)
            return klargest(arr,index+1,r,k+l-index-1,n);
        return klargest(arr,l,index-1,k,n);
    }
    return INT_MAX;
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
    if(k<0 || k>n)
        cout << "Value of k should be in [1," << k << "] range\n";
    else
    {
        cout << k << " largest number: " << klargest(arr,0,n-1,k,n) << '\n';
        cout << k << " smallest number: " << ksmallest(arr,0,n-1,k,n) << '\n';
    }
}