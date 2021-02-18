#include<bits/stdc++.h>
using namespace std;

vector<string> permute(string a,int l,int r,vector<string>ans)
{
    if(l==r)
        ans.push_back(a);
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);
            ans=permute(a,l+1,r,ans);
            swap(a[l],a[i]);
        }
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    vector<string>ans;
	    string a;
	    cin >> a;
	    int n=a.size();
	    ans=permute(a,0,n-1,ans);
	    sort(ans.begin(),ans.end());
	    for(int i=0;i<ans.size();i++)
	        cout << ans[i] << " ";
	    cout << '\n';
	}
	return 0;
}