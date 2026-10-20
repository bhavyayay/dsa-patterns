class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = 0; i < n && ok; i += k) {
                vector<int> a(nums.begin() + i, nums.begin() + i + k);
                vector<int> b(s.begin() + i, s.begin() + i + k);

                bool found = false;
                for (int j = 0; j < k; j++) {
                    bool same = true;

                    for (int t = 0; t < k; t++) {
                        if (a[t] != b[(j + t) % k]) {
                            same = false;
                            break;
                        }
                    }

                    if (same) {
                        found = true;
                        break;
                    }
                }

                if (!found) ok = false;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};