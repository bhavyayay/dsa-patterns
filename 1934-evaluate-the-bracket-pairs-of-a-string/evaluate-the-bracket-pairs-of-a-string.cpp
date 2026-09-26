class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        unordered_map<string,string>mp;
        for(auto &vec:knowledge){
           mp[vec[0]]=vec[1];
        }
        bool bracopen=false;
        string result="";
        string temp="";
        int i=0;
        while(i<n){
            if(s[i]=='('){
                bracopen=true;
            }
            else if(s[i]==')'){
                result+= mp.count(temp) ? mp[temp] : "?";
                bracopen=false;
                temp="";

            }
            else if(bracopen){
                temp.push_back(s[i]);
            }
            else {
                result.push_back(s[i]);
            }
            i++;

        }
        return result;
    }
};