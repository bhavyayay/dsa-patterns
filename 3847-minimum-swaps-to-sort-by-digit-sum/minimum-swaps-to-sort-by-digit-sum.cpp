class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            if (digitSum(a) != digitSum(b))
                return digitSum(a) < digitSum(b);
            return a < b;
        });

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]] = i;

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i]) continue;

            int j = pos[sorted[i]];

            swap(nums[i], nums[j]);
            pos[nums[j]] = j;
            pos[nums[i]] = i;

            swaps++;
        }

        return swaps;
    }
};