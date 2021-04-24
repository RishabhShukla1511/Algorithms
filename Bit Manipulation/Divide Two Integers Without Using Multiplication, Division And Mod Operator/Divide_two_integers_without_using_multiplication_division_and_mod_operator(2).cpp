#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long divident,divisor;
    cout << "Enter divident\n";
    cin >> divident;
    cout << "Enter divisor\n";
    cin >> divisor;
    int sign=((divident<0)^(divisor<0))?-1:1;
    divident=abs(divident);
    divisor=abs(divisor);
    long long quotient=0,temp=0;
    for(int i=31;i>=0;i--)
    {
        if(temp+(divisor<<i)<=divident)
        {
           temp+=(divisor<<i);
           quotient|=1LL<<i;
        }
    }
    if(sign<0)
        cout << "Quotient: -" << quotient;
    else
        cout << "Quotient: " << quotient;
}