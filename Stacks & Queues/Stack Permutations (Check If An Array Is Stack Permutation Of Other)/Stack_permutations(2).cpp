#include<bits/stdc++.h>
using namespace std;

bool isStackPermutataions(int input[],int output[],int n,int m)
{
    stack<int>s;
    int i=0,j=0;
    while(i!=n)
    {
        s.push(input[i]);
        while(!s.empty() && s.top()==output[j])
        {
            j++;
            s.pop();
        }
        i++;
    }
    while(!s.empty() && s.top()==output[j])
    {
        j++;
        s.pop();
    }
    return s.empty();    
}

int main()
{
    int n;
    cout << "Enter the length of input array\n";
    cin >> n;
    int input[n];
    cout << "Enter the input array\n";
    for(int i=0;i<n;i++)
        cin >> input[i];
    int m;
    cout << "Enter the length of output array\n";
    cin >> m;
    int output[m];
    cout << "Enter the output array\n";
    for(int i=0;i<m;i++)
        cin >> output[i];
    if(isStackPermutataions(input,output,n,m))
        cout << "Yes output array is a stack permutation of input array\n";
    else
        cout << "No output array is a stack permutation of input array\n";
}