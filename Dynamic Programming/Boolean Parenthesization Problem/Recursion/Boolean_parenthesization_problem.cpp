#include <bits/stdc++.h>
using namespace std;

int boolParenthesizationUtil(string expr, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        int t = 0, f = 0;
        if (expr[i] == 'T' || expr[i] == 't')
            t++;
        else
            f++;
        if (isTrue)
            return t;
        return f;
    }
    int ways = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int t1, f1, t2, f2;
        t1 = boolParenthesizationUtil(expr, i, k - 1, true);
        f1 = boolParenthesizationUtil(expr, i, k - 1, false);
        t2 = boolParenthesizationUtil(expr, k + 1, j, true);
        f2 = boolParenthesizationUtil(expr, k + 1, j, false);
        if (expr[k] == '|')
        {
            if (isTrue)
                ways += t1 * f2 + t2 * f1 + t1 * t2;
            else
                ways += f1 * f2;
        }
        else if (expr[k] == '&')
        {
            if (isTrue)
                ways += t1 * t2;
            else
                ways += t1 * f2 + t2 * f1 + f1 * f2;
        }
        else if (expr[k] == '^')
        {
            if (isTrue)
                ways += t1 * f2 + t2 * f1;
            else
                ways += t1 * t2 + f1 * f2;
        }
    }
    return ways;
}

int boolParenthesization(string expr)
{
    int n = expr.length();
    return boolParenthesizationUtil(expr, 0, n - 1, true);
}

int main()
{
    string expr;
    cout << "Enter the boolean exprression\nRepresent AND with &, OR with |, XOR with ^,True with T/t and False with F/f\n";
    cin >> expr;
    int n = expr.length();
    for (int i = 0; i < n; i++)
    {
        if (!(expr[i] != 'T' || expr[i] != 't' || expr[i] != 'F' || expr[i] != 'f' || expr[i] != '&' || expr[i] != '|' || expr[i] != '^'))
        {
            cout << "Invalid exprression\n";
            return 0;
        }
    }
    cout << "No of ways which evaluate " << expr << " to True are " << boolParenthesization(expr);
}