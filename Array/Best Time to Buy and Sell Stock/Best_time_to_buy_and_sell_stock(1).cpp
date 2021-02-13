class Solution {
public:
    int maxProfit(vector<int>& v) {
        int min=INT_MAX,diff=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<min)
                min=v[i];
            if(v[i]-min>diff)
                diff=v[i]-min;
        }
        return diff;
    }
};