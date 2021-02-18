// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral

int getVal(char c)
{
    if(c=='I')  return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50;
    else if(c=='C') return 100;
    else if(c=='D') return 500;
    else if(c=='M') return 1000;
}

int romanToDecimal(string &str) {
    // code here
    int ans=0,n=str.size();
    for(int i=0;i<n;i++)
    {
        if(i+1<n)
        {
            if(getVal(str[i])>=getVal(str[i+1]))
                ans+=getVal(str[i]);
            else
            {
                ans+=getVal(str[i+1])-getVal(str[i]);
                i++;
            }
        }
        else
            ans+=getVal(str[i]);
    }
    return ans;
}