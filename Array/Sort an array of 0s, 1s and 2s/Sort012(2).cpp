#include<bits/stdc++.h>
using namespace std;

void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends

void swap(int *a,int *b)
{
    int *temp=a;
    a=b;
    b=temp;
}

void sort012(int arr[], int n)
{
    // coode here 
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
            swap(arr[low++],arr[mid++]);
        else if(arr[mid]==1)
            mid++;
        else
            swap(arr[mid],arr[high--]);
    }
}