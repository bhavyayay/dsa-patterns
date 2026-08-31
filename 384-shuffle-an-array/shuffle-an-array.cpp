class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> result = original;

        for (int i = 0; i < result.size(); i++) {
            int j = i + rand() % (result.size() - i);

            swap(result[i], result[j]);
        }

        return result;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */