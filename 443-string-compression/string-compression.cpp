class Solution {
public:
    int compress(vector<char>& chars) {
        int k=0;
        int i=0;
        while(i<chars.size()){
            int j=i;
            while(j<chars.size() && chars[j]==chars[i]){
                j++;

            }
            chars[k++]=chars[i];
            int count=j-i;
            if(count>1){
                string s=to_string(count);
                for(char c:s){
                    chars[k++]=c;
                }
            }
            i=j;
        }
        return k;
        
    }
};