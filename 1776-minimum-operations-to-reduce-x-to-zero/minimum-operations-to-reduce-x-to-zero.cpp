class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x){
            return -1;

        }
        int restsum=sum-x;
        sum=0;
        int longest=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.count(sum-restsum)){
                longest=max(longest,i-mp[sum-restsum]);
            }
        }
        return longest==INT_MIN?-1:n-longest;
        
    }
};