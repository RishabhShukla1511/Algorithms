class Solution {
public:
    int maxProfit(vector<int>& v) {
        int min=INT_MAX,max=INT_MIN,diff=0,maxp=-1,minp=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<min)
            {
                min=v[i];
                minp=i;
            }
            if(v[i]-min>diff)
                diff=v[i]-min;
        }
        return diff;
    }
};