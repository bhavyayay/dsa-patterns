class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto add = [&](int val) {
            if (lo.empty() || val <= *lo.rbegin()) {
                lo.insert(val);
                sumLo += val;
            } else {
                hi.insert(val);
                sumHi += val;
            }

            if (lo.size() > hi.size() + 1) {
                int v = *lo.rbegin();
                lo.erase(lo.find(v));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            else if (lo.size() < hi.size()) {
                int v = *hi.begin();
                hi.erase(hi.find(v));
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto remove = [&](int val) {
            auto it = lo.find(val);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= val;
            } else {
                it = hi.find(val);
                hi.erase(it);
                sumHi -= val;
            }

            if (lo.size() > hi.size() + 1) {
                int v = *lo.rbegin();
                lo.erase(lo.find(v));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            else if (lo.size() < hi.size()) {
                int v = *hi.begin();
                hi.erase(hi.find(v));
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto getCost = [&]() -> long long {
            long long med = *lo.rbegin();

            return med * lo.size() - sumLo
                 + sumHi - med * hi.size();
        };

        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == INF) continue;

                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

                if (j < k && i + x <= n) {
                    dp[i + x][j + 1] = min(
                        dp[i + x][j + 1],
                        dp[i][j] + cost[i]
                    );
                }
            }
        }

        long long ans = INF;

        for (int i = 0; i <= n; i++) {
            ans = min(ans, dp[i][k]);
        }

        return ans;
    }
};