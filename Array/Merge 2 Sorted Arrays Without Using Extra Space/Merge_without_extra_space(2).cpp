#include<bits/stdc++.h>
using namespace std;

int arr1[10000000];
int arr2[10000000];

int getgap(int gap)
{
    if(gap<=1)
        return 0;
    return gap/2+gap%2;
}

void merge(int n,int m)
{
    int i,j,gap=n+m;
    for(gap=getgap(gap);gap>0;gap=getgap(gap))
    {
        for(i=0;i+gap<n;i++)
        {
            if(arr1[i]>arr1[i+gap])
                swap(arr1[i],arr1[i+gap]);
        }
        for(j=gap>n?gap-n:0;j<m && i<n;i++,j++)
        {
            if(arr1[i]>arr2[j])
                swap(arr1[i],arr2[j]);
        }
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
            {
                if(arr2[j]>arr2[j+gap])
                    swap(arr2[j],arr2[j+gap]);
            }
        }
    }
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m;
	    cin >> n >> m;
	    for(int i=0;i<n;i++)
	        cin >> arr1[i];
	    for(int i=0;i<m;i++)
	        cin >> arr2[i];
	    merge(n,m);
	    for(int i=0;i<n;i++)
	        cout << arr1[i] << " ";
	    for(int i=0;i<m;i++)
	        cout << arr2[i] << " ";
	    cout << '\n';
	}
	return 0;
}