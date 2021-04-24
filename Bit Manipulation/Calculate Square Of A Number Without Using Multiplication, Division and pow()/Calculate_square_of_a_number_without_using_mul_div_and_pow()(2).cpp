#include<bits/stdc++.h>
using namespace std;

int square(int n)
{
    if(n==0)
        return 0;
    int x=n>>1;
    if(n&1)
        return (square(x)<<2)+(x<<2)+1;
    return (square(x)<<2);
}

int main()
{
    long long base;
    cout << "Enter the base value\n";
    cin >> base;
    cout << base << "^2 = " << square(base) << "\n";
}