class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        else{
            (n-999)+1;
        }
        return max(0,n-999);
    }
};