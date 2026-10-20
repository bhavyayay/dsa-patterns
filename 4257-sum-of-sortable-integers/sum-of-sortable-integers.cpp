class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                vector<int> a(nums.begin() + i, nums.begin() + i + k);
                vector<int> b(sorted.begin() + i, sorted.begin() + i + k);

                // Check if a is a rotation of b
                vector<int> doubled = b;
                doubled.insert(doubled.end(), b.begin(), b.end());

                if (search(doubled.begin(), doubled.end(),
                           a.begin(), a.end()) == doubled.end()) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};