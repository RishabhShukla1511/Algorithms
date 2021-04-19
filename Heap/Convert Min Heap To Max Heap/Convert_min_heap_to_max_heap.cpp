#include<bits/stdc++.h>
using namespace std;

void print(int minheap[],int n)
{
    cout << "Following is the Max Heap\n";
    for(int i=0;i<n;i++)
        cout << minheap[i] << " ";
}

void heapify(int minheap[],int pos,int n)
{
    int largest=pos;
    if(2*pos+1<n && minheap[2*pos+1]>minheap[pos])
        largest=2*pos+1;
    if(2*pos+2<n && minheap[2*pos+2]>minheap[largest])
        largest=2*pos+2;
    if(largest!=pos)
    {
        swap(minheap[pos],minheap[largest]);
        heapify(minheap,largest,n);
    }
}

void convertMintoMaxHeap(int minheap[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(minheap,i,n);
}

int main()
{
    int n;
    cout << "Enter the size of Min Heap\n";
    cin >> n;
    int minheap[n];
    cout << "Enter the elements of Min Heap\n";
    for(int i=0;i<n;i++)
        cin >> minheap[i];
    convertMintoMaxHeap(minheap,n);
    print(minheap,n);
}