class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)
            return false;
        else if(matrix[0].size()<=0)
            return false;
        int m=matrix[0].size(),i=0,k=0;
        for(i=0;i<n;i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][m-1])
            {
                k=1;
                break;
            }
        }
        if(k && binary_search(matrix[i].begin(),matrix[i].end(),target))
                return true;
        return false;
    }
};