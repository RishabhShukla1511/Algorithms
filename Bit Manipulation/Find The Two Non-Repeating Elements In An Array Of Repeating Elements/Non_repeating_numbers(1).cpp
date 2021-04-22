#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorall=nums[0],n=nums.size();
        for(int i=1;i<n;i++)
            xorall^=nums[i];
        int setbitno=xorall&~(xorall-1),x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&setbitno)
                x^=nums[i];
            else
                y^=nums[i];
        }
        vector<int>ans;
        ans.push_back(min(x,y));
        ans.push_back(max(x,y));
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends