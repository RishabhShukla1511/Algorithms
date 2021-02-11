#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,n,m;
    cout << "Enter the number of days to survive\n";
    cin >> s;
    cout << "Enter the maximum unit of food to buy each day\n";
    cin >> n;
    cout << "Enter the unit of food to survive each day\n";
    cin >> m;
    if(m>n || ((m*7>n*6) && s>6))
        cout << "No\n";
    else
    {
        int days=(m*s)/n;
        if((m*s)%n)
            days++;
        cout << "Yes " << days << '\n';
    }
}
