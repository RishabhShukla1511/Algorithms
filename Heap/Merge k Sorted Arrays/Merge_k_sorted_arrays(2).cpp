#include<bits/stdc++.h>

#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

void merge(vector<int>&v,vector<int>t)
{
    vector<int>ans;
    int f=0,s=0,pos=0;
    while(f!=v.size() && s!=t.size())
    {
        if(v[f]<=t[s])
        {
            ans.push_back(v[f]);
            f++;
        }
        else
        {
            ans.push_back(t[s]);
            s++;
        }
    }
    while(f!=v.size())
    {
        ans.push_back(v[f]);
        f++;
    }
    while(s!=t.size())
    {
        ans.push_back(t[s]);
        s++;
    }
    v=ans;
}


int *mergeKArrays(int arr[][N], int k)
{
//code here
    vector<int>v;
    for(int i=0;i<k;i++)
        v.push_back(arr[0][i]);
    int pos=1;
    while(pos<k)
    {
        vector<int>t;
        for(int i=0;i<k;i++)
            t.push_back(arr[pos][i]);
        merge(v,t);
        pos++;
    }
    int *output = new int[v.size()];
    for(int i=0;i<v.size();i++)
        output[i]=v[i];
    return output;
}
