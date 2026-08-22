class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int x=n;
        while(x!=0){
            int digit=x%10;
            x/=10;
            sum+=digit;
            prod*=digit;

        }
        if(n%(sum+prod)==0){
            return true;
        }
        else return false;
        
    }
    
};