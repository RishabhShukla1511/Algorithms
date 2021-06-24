class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long ac = 1, ec = 1, ic = 1, oc = 1, uc = 1;
        int mod = 1000000007;
        for (int k = 1; k < n; k++)
        {
            long a = (ec + ic + uc) % mod;
            long e = (ac + ic) % mod;
            long i = (ec + oc) % mod;
            long o = ic % mod;
            long u = (ic + oc) % mod;
            ac = a;
            ec = e;
            ic = i;
            oc = o;
            uc = u;
        }
        long res = (ac + ec + ic + oc + uc) % mod;
        return (int)res;
    }
};