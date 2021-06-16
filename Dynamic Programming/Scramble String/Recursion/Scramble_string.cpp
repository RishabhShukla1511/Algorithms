#include <bits/stdc++.h>
using namespace std;

bool isScrambled(string str1, string str2)
{
    string key = str1 + " " + str2;
    if (str1.length() != str2.length())
        return false;
    if (str1 == str2)
        return true;
    int cnt[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        cnt[str1[i] - 'a']++;
        cnt[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            return false;
    }
    int n = str1.length();
    for (int k = 1; k < n; k++)
    {
        if (isScrambled(str1.substr(0, k), str2.substr(0, k)) && isScrambled(str1.substr(k), str2.substr(k)))
            return true;
        if (isScrambled(str1.substr(0, k), str2.substr(n - k)) && isScrambled(str1.substr(k), str2.substr(0, n - k)))
            return true;
    }
    return false;
}

int main()
{
    string str1, str2;
    cout << "Enter the original string\n";
    cin >> str1;
    cout << "Enter the second string\n";
    cin >> str2;
    if (isScrambled(str1, str2))
        cout << "Yes, " << str2 << " is a scrambled string of " << str1;
    else
        cout << "No, " << str2 << " is not a scrambled string of " << str1;
}