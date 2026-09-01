class Solution {
public:

    void backtrack(int index,
                   vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Don't take nums[index]
        backtrack(index + 1,
                  nums,
                  current,
                  ans);

        // Take nums[index]
        current.push_back(nums[index]);

        backtrack(index + 1,
                  nums,
                  current,
                  ans);

        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        backtrack(0, nums, current, ans);

        return ans;
    }
};