class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=0;
        int prev=0,next=1;
        while(next<n)
        {
            if(intervals[prev][1]>=intervals[next][1] || (intervals[prev][1]>=intervals[next][0] && intervals[prev][1]<=intervals[next][1]))
            {
                intervals[prev][1]=max(intervals[prev][1],intervals[next][1]);
                intervals[prev][0]=min(intervals[prev][0],intervals[next][0]);
                arr[next]=1;
                next++;
            }
            else
            {
                prev=next;
                next++;
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                ans.push_back(intervals[i]);   
        }
        return ans;
    }
};