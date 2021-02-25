#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
  public:
  
    void isSum(vector<int>A,int currsum,int reqsum,vector<int>&v,int pos,vector<vector<int>>&ans)
    {
        int n=A.size();
        for(int i=pos;i<n;i++)
        {
            if(currsum+A[i]>reqsum)
                return;
            v.push_back(A[i]);
            if(currsum+A[i]==reqsum)
            {
                ans.push_back(v);
                v.pop_back();
                return;
            }
            isSum(A,currsum+A[i],reqsum,v,i,ans);
            v.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>s(A.begin(),A.end());
        A.assign(s.begin(),s.end());
        int n=A.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(A[i]>B)
                break;
            vector<int>v;
            v.push_back(A[i]);
            if(A[i]==B)
            {
                ans.push_back(v);
                break;
            }
            isSum(A,A[i],B,v,i,ans);
            v.pop_back();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends