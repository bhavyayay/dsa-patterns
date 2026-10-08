class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                cnt--;
            }if(cnt!=0){
                ans.push_back(s[i]);
            }
            if(s[i]=='('){
                cnt++;
            }
        }
        return ans;

        
    }
};