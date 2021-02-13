#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>vec;
            int maxneg=0,maxpos=0;
            for(int i=0;i<n1;i++)
            {
                if(A[i]>=0 && A[i]>maxpos)
                    maxpos=A[i];
                if(A[i]<0 && abs(A[i])>maxneg)
                    maxneg=abs(A[i]);
            }
            int pos[maxpos+1]={0},neg[maxneg+1]={0};
            for(int i=0;i<n1;i++)
            {
                if(A[i]>=0 && pos[A[i]]==0)
                    pos[A[i]]=1;
                if(A[i]<0 && neg[abs(A[i])]==0)
                    neg[abs(A[i])]=1;
            }
            for(int i=0;i<n2;i++)
            {
                if(B[i]>=0 && B[i]<=maxpos && pos[B[i]]==1)
                    pos[B[i]]=2;
                if(B[i]<0 && abs(B[i])<=maxneg && neg[abs(B[i])]==1)
                    neg[abs(B[i])]=2;
            }
            for(int i=0;i<n3;i++)
            {
                if(C[i]>=0 && C[i]<=maxpos && pos[C[i]]==2)
                    pos[C[i]]=3;
                if(C[i]<0 && abs(C[i])<=maxneg && neg[abs(C[i])]==2)
                    neg[abs(C[i])]=3;
            }
            for(int i=maxneg;i>0;i--)
            {
                if(neg[i]==3)
                    vec.push_back(-i);
            }
            for(int i=0;i<=maxpos;i++)
            {
                if(pos[i]==3)
                    vec.push_back(i);
            }
            return vec;
        }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends