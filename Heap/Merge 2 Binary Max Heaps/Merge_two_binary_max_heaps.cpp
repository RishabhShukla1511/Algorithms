// Initial Template for C++

// C++ program to merge two max heaps.
#include <bits/stdc++.h>
using namespace std;

void mergeHeaps(int merged[], int a[], int b[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        int merged[m + n];
        mergeHeaps(merged, a, b, n, m);

        for (int i = 0; i < n + m; i++) cout << merged[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

void heapify(int arr[],int pos,int n)
{
    int largest=pos;
    if(2*pos+1<n && arr[2*pos+1]>arr[largest])
        largest=2*pos+1;
    if(2*pos+2<n && arr[2*pos+2]>arr[largest])
        largest=2*pos+2;
    if(largest!=pos)
    {
        swap(arr[pos],arr[largest]);
        heapify(arr,largest,n);
    }    
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) {
    int k=0;
    for(int i=0;i<n;i++)
        merged[k++]=a[i];
    for(int i=0;i<m;i++)
        merged[k++]=b[i];
    for(int i=(n+m)/2-1;i>=0;i--)
        heapify(merged,i,n+m);
}