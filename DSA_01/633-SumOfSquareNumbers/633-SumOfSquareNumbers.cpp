// Last updated: 05/08/2026, 16:56:19
class Solution {
public:
    bool judgeSquareSum(int c) {

        int n = round(sqrt(c));

        long long j=n;

        long long i=0;

        long long ans = 0;


        while(i<=j){

            ans = (i * i) + (j * j);

            if(ans == c){
                return true;
            }
            else if(ans>c){

                j--;

            }
            else{
                i++;
            }
            
            

        }
        return false;
        
    }
};