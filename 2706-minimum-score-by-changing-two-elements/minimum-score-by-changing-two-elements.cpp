class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        //sort
        sort(begin(nums), end(nums));

        return min({
            nums[n-3] - nums[0], // do sabse bade hatao
            nums[n-1] - nums[2], // do sabse chhote hatao
            nums[n-2] - nums[1]  // ek bada + ek chhota hatao
        });
    }
};