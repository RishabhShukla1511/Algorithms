#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(Item a,Item b)
{
    return (a.value/(double)a.weight)>(b.value/(double)b.weight);
}

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr,arr+n,cmp);
    int w=0;
    double val=0;
    for(int i=0;i<n;i++)
    {
        if(w+arr[i].weight<=W)
        {
            val+=arr[i].value;
            w+=arr[i].weight;
        }
        else
        {
            val+=(W-w)*(arr[i].value/(double)arr[i].weight);
            break;
        }
    }
    return val; 
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends