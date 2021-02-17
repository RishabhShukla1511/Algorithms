class Solution {
public:
    
    static bool compare(const vector<int>& v, int target)
    {
        return v.back() < target;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        vector<vector<int>>::iterator it = lower_bound(matrix.begin(), matrix.end(), target, compare);
        return it != matrix.end() && binary_search(it->begin(), it->end(), target);
    }
};