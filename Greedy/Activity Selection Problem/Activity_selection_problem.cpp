#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends

bool cmp(pair<int,int>activity1,pair<int,int>activity2)
{
    return activity1.second<activity2.second;
}

int maxMeetings(int start[], int end[], int n) {
    // Your code here
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(start[i],end[i]));
    sort(v.begin(),v.end(),cmp);
    int cnt=1,e=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>e)
        {
            e=v[i].second;
            cnt++;
        }
    }
    return cnt;
}
