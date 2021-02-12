#include<bits/stdc++.h>
using namespace std;

int maxProd(int arr[],int n)
{
    int maxneg=0,prod=1,zerocnt=0,negcnt=0,poscnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            prod*=arr[i];
            poscnt++;
        }
        else if(arr[i]<0)
        {
            prod*=arr[i];
            if(maxneg==0)
                maxneg=arr[i];
            else
                maxneg=max(maxneg,arr[i]);
            negcnt++;
        }
        else
            zerocnt++;
    }
    if(zerocnt==n)
        return 0;
    if(negcnt%2!=0)
    {
        if(negcnt==1)
        {
            if(n==1 || zerocnt==n-1)
                return 0;
        }
        return prod/maxneg;
    }
    return prod;
}

int main()
{
    int n;
    cout << "Enter the length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the number of array\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Maximum subset product is " << maxProd(arr,n);
}