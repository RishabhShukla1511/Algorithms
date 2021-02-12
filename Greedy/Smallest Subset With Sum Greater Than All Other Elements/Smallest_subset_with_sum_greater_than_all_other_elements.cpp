#include<bits/stdc++.h>
using namespace std;

void findSubset(int arr[],int n)
{
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int currsum=0;
    for(int i=n-1;i>=0;i--)
    {
        cout << arr[i] << " ";
        currsum+=arr[i];
        if(currsum>sum-currsum)
            break;
    }
}

int main()
{
    int n;
    cout << "Enter the length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " non-negative numbers\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Subset having sum greater than sum of all other elements \n";
    findSubset(arr,n);
}