#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public: 

    bool issafe(int i,int j,int r,int c)
    {
        if(i>=0 && j>=0 && i<r && j<c)
            return true;
        return false;
    }

    void print(vector<vector<int>>&visited,vector<vector<int>>matrix,int i,int j,int r,int c,vector<int>&ans)
    {
        while(issafe(i,j,r,c) && visited[i][j]!=1)
        {
            ans.push_back(matrix[i][j]);
            visited[i][j]=1;
            j++;
        }
        i++;
        j--;
        while(issafe(i,j,r,c) && visited[i][j]!=1)
        {
            ans.push_back(matrix[i][j]);
            visited[i][j]=1;
            i++;
        }
        i--;
        j--;
        while(issafe(i,j,r,c) && visited[i][j]!=1)
        {
            ans.push_back(matrix[i][j]);
            visited[i][j]=1;
            j--;
        }
        i--;
        j++;
        while(issafe(i,j,r,c) && visited[i][j]!=1)
        {
            ans.push_back(matrix[i][j]);
            visited[i][j]=1;
            i--;
        }
    }

    vector<int> spirallyTraverse(vector<vector<int>>matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        vector<vector<int>>visited;
        for(int i=0;i<r;i++)
        {
            vector<int>v(c);
            for(int j=0;j<c;j++)
                v[j]=0;
            visited.push_back(v);
        }
        int i=0,j=0;
        for(i=0;i<r;i++,j++)
            print(visited,matrix,i,j,r,c,ans);
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends