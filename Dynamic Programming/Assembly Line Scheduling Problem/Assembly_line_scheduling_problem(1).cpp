#include <bits/stdc++.h>
using namespace std;

int minTime(vector<vector<int>> a, vector<vector<int>> t, int e[2], int x[2])
{
    int n = a[0].size();
    a[0][n - 1] += x[0];
    a[1][n - 1] += x[1];
    a[0][0] += e[0];
    a[1][0] += e[1];
    for (int i = n - 2; i >= 0; i--)
    {
        a[0][i] += min(a[0][i + 1], a[1][i + 1] + t[0][i + 1]);
        a[1][i] += min(a[0][i + 1] + t[1][i + 1], a[1][i + 1]);
    }
    return min(a[0][0], a[1][0]);
}

int main()
{
    int n;
    cout << "Enter the number of stations\n";
    cin >> n;
    vector<int> temp(n);
    vector<vector<int>> a;
    for (int i = 0; i < 2; i++)
    {
        a.push_back(temp);
        cout << "Enter the time at stations of assembly line " << i + 1 << '\n';
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    vector<vector<int>> t;
    for (int i = 0; i < 2; i++)
    {
        t.push_back(temp);
        if (i == 0)
            cout << "Enter the time to move from stations of assembly line 1 to assembly line 2\n";
        else
            cout << "Enter the time to move from stations of assembly line 2 to assembly line 1\n";
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    }
    int e[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the time to enter assembly line " << i + 1 << '\n';
        cin >> e[i];
    }
    int x[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the time to exit assembly line " << i + 1 << '\n';
        cin >> x[i];
    }
    cout << "Minimum time to build car chassis " << minTime(a, t, e, x);
}