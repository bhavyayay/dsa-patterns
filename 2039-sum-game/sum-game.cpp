class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftknownsum=0;
        int rightknownsum=0;
        int leftQn=0;
        int rightQn=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftQn++;

                }
                else{
                    rightQn++;
                }
            }
            else{
                if(i<n/2){
                    leftknownsum+=num[i]-'0';

                }
                else{
                    rightknownsum+=num[i]-'0';
                }

            }
        }
        int totalQn=leftQn+rightQn;
        if(totalQn%2==1){
            return true;
        }
        int left=2*leftknownsum+9*leftQn;
        int right=2*rightknownsum+9*rightQn;
        if(left==right){
            return false;
        }
        return true;
    }
};