#include<bits/stdc++.h>
using namespace std;

vector<string> permute(string a,vector<string>ans)
{
    do{
		ans.push_back(a);
	}while(next_permutation(a.begin(),a.end()));
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
	    ans=permute(a,ans);
	    sort(ans.begin(),ans.end());
	    for(int i=0;i<ans.size();i++)
	        cout << ans[i] << " ";
	    cout << '\n';
	}
	return 0;
}