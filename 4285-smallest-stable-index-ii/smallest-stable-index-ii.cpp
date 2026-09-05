class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minel(n);
        int mini=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            
            mini=min(mini,nums[i]);
            minel[i]=mini;
        }
        int maxel=INT_MIN;
        for(int i=0;i<n;i++){
            maxel=max(maxel,nums[i]);
            if(maxel-minel[i]<=k){
                return i;
            }
        }
        return -1;
        
    }
};