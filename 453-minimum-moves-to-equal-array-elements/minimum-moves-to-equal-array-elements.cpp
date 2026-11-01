class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int minel=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minel=min(minel,nums[i]);
        }
        return sum-n*minel;
    }
};