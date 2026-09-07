class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, string& s, vector<int>& dp) {
        if(i < 0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        long long ans = 2LL * solve(i - 1, s, dp);

        int prev = i - 1;

        while(prev >= 0 && s[prev] != s[i])
            prev--;

        if(prev >= 0)
            ans -= solve(prev - 1, s, dp);

        return dp[i] = (ans + MOD) % MOD;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return (solve(n - 1, s, dp) - 1 + MOD) % MOD;
    }
};