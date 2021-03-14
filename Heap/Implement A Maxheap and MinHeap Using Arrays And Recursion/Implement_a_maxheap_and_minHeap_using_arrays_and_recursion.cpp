#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}

int min(int a,int b)
{
    if(a<=b)
        return a;
    return b;
}

void swap(int *a,int *b)
{
    int *c=a;
    a=b;
    b=c;
}

void maxHeapify(int arr[],int pos,int n)
{
    int l=2*pos+1,r=2*pos+2,largest=pos;
    if(l<n && arr[pos]<arr[l])
        largest=l;
    if(r<n && arr[largest]<arr[r])
        largest=r;
    if(largest!=pos)
    {
        swap(arr[pos],arr[largest]);
        maxHeapify(arr,largest,n);
    }
}

void minHeapify(int arr[],int pos,int n)
{
    int l=2*pos+1,r=2*pos+2,smallest=pos;
    if(l<n && arr[pos]>arr[l])
        smallest=l;
    if(r<n && arr[smallest]>arr[r])
        smallest=r;
    if(smallest!=pos)
    {
        swap(arr[pos],arr[smallest]);
        minHeapify(arr,smallest,n);
    }
}

void createMaxHeap(int arr[],int n)
{
    int pos=n/2-1;
    for(int i=pos;i>=0;i--)
        maxHeapify(arr,i,n);
}

void createMinHeap(int arr[],int n)
{
    int pos=n/2-1;
    for(int i=pos;i>=0;i--)
        minHeapify(arr,i,n);
}

void print(int arr[],int n,int k)
{
    if(k==1)
    {
        cout << "Max Heap:\n";
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << '\n';
    }
    else
    {
        cout << "Min Heap:\n";
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    int maxHeap[n],minHeap[n];
    cout << "Enter the array\n";
    for(int i=0;i<n;i++)
    {
        cin >> maxHeap[i];
        minHeap[i]=maxHeap[i];
    }
    createMaxHeap(maxHeap,n);
    print(maxHeap,n,1);
    createMinHeap(minHeap,n);
    print(minHeap,n,2);
}