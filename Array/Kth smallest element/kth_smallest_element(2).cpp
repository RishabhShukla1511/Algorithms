#include<stdio.h>
#define fastIO() do{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}while(0);
using namespace std; 
int main() 
{ 
    fastIO();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        scanf("%d",&k);
        sort(arr,arr+n);
        printf("%d\n",arr[k-1]);
    }
}
