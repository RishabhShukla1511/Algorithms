#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long base;
    cout << "Enter the base value\n";
    cin >> base;
    long long val=base;
    for(int i=1;i<base;i++)
        val+=base;
    cout << base << "^2 = " << val << "\n";
}