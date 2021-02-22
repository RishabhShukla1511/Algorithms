using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<string,int>m;
        for(int i=0;i<n;i++)
        {
            string a;
            cin >> a;
            sort(a.begin(),a.end());
            m[a]++;
        }
        vector<int>ans;
        for(auto it:m)
            ans.push_back(it.second);
        m.clear();
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
}