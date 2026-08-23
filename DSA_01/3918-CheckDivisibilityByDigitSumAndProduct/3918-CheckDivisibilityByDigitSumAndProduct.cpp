// Last updated: 23/08/2026, 18:24:51
class Solution {
public:
    bool checkDivisibility(int n) {

        int a = 0;

        int copy = n;

        int sum= 0;
        int mul  = 1;

        while(copy>0){

            a = copy%10;

            copy = copy/10;


            sum+=a;
            mul*=a;



        }

        if(n%(sum+mul)==0){
            return true;
        }


        else{

            return false;



        }

        
        
    }
};