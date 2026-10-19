class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt=0;
        for(int &num:nums){
            if(num<target){
                cnt++;
            }
        }
        vector<int>res;
        for(int &num:nums){
            if(num==target){
                res.push_back(cnt);
                cnt++;
            }
        }
        return res;

       
    }
};