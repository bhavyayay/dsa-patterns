class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_count;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_in_window;

            for (int j = i; j < i + k; j++) {
                unique_in_window.insert(nums[j]);
            }

            for (int num : unique_in_window) {
                subarray_count[num]++;
            }
        }

        int largest = -1;

        for (auto pair : subarray_count) {
            int num = pair.first;
            int count = pair.second;

            if (count == 1) {
                largest = max(largest, num);
            }
        }

        return largest;
    }
};