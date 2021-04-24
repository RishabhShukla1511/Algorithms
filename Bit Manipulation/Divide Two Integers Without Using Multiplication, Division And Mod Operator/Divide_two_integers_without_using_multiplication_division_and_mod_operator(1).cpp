#include<bits/stdc++.h>
using namespace std;

int main()
{
    int divident,divisor;
    cout << "Enter divident\n";
    cin >> divident;
    cout << "Enter divisor\n";
    cin >> divisor;
    divident=abs(divident);
    divisor=abs(divisor);
    int sign=((divident<0)^(divisor<0))?-1:1,quotient=0;
    while(divident>=divisor)
    {
        divident-=divisor;
        quotient++;
    }
    if(sign<0)
        cout << "Quotient: -" << quotient;
    else
        cout << "Quotient: " << quotient;
}