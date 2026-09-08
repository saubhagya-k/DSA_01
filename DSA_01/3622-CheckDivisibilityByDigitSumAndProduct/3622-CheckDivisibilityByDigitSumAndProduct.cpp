// Last updated: 08/09/2026, 11:31:52
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