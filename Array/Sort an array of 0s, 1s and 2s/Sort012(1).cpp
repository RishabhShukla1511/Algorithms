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


void sort012(int a[], int n)
{
    // coode here 
    int z=0,o=0,t=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            z++;
        else if(a[i]==1)
            o++;
        else
            t++;
    }
    int pos=0;
    while(z--)
    {
        a[pos]=0;
        pos++;
    }
    while(o--)
    {
        a[pos]=1;
        pos++;
    }
    while(t--)
    {
        a[pos]=2;
        pos++;
    }
}