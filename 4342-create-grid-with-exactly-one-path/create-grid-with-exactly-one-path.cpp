class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string top(n,'.');
        string rem=string(n-1,'#')+'.';
        vector<string>res;
        res.push_back(top);
        for(int i=1;i<m;i++){
            res.push_back(rem);
        }
        return res;
    }
};