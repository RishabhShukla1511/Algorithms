class Solution
{
public:
    unordered_map<string, bool> m;

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
        if (m.find(key) != m.end())
            return m[key];
        int n = str1.length();
        for (int k = 1; k < n; k++)
        {
            if (isScrambled(str1.substr(0, k), str2.substr(0, k)) && isScrambled(str1.substr(k), str2.substr(k)))
                return m[key] = true;
            if (isScrambled(str1.substr(0, k), str2.substr(n - k)) && isScrambled(str1.substr(k), str2.substr(0, n - k)))
                return m[key] = true;
        }
        return m[key] = false;
    }

    bool isScramble(string s1, string s2)
    {
        m.clear();
        return isScrambled(s1, s2);
    }
};