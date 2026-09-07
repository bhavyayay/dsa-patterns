class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mp(26,0);
        for(char c:magazine){
            mp[c-'a']++;
        }
        for(char c:ransomNote){
            if(mp[c-'a']==0){
                return false;
            }
            else{
                mp[c-'a']--;
            }
        }
        return true;
        
    }
};