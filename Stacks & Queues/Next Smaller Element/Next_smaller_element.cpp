#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int arr[],int n)
{
    vector<int>ans(n);
    fill(ans.begin(),ans.end(),-1);
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            int pos=s.top();
            ans[pos]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

void print(vector<int>ans)
{
    cout << "Next smaller element for every element is:\n";
    int n=ans.size();
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    return;
}

int main()
{
    int n;
    cout << "Enter the number of elements\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int>ans=nextSmallerElement(arr,n);
    print(ans);
}