// Last updated: 23/08/2026, 18:25:43
class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        // int count_blanks = 0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]=="?"){

        //         count_blanks++;
                
        //     }
        // }

        // if(count_blanks%2 !=0){
        //     return true;
        // }

        int lc =0;
        int lb =0;
        int rc =0;
        int rb =0;

        for(int i=0;i<n/2;i++){
            if(num[i] !='?'){
                lc+= num[i]-'0';
            }
            else{
                lb++;
            }
        }

          for(int i=n/2;i<n;i++){
            if(num[i] !='?'){
                rc+= num[i]-'0';
            }
            else{
                rb++;
            }
        }

        if(lb+rb == 0){
            return lc!=rc;
        }

        if((lb+rb)%2 ==1){

            return true;

        }

        int mini = min(lb,rb);

        lb-=mini;
        rb-=mini;
        if(lb>0){
            if(lc>rc){
                return true;
            }
            if(9*(lb/2) == rc-lc){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            if(rc>lc){
                return true;
            }
            if(9*(rb/2) == lc-rc){
                return false;
            }
            else{
                return true;
            }
        }

    
        
    }
};