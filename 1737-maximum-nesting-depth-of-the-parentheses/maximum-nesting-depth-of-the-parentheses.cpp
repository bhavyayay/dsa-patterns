class Solution {
public:
    int maxDepth(string s) {
        int openbrac=0;
        int result=0;

        for(auto &ch:s){
            if(ch=='('){
                openbrac++;

            }else if(ch==')'){
                openbrac--;
            }
            
            result=max(result,openbrac);
        
        }
        return result;

        
    }
};