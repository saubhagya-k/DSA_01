// Last updated: 08/09/2026, 11:36:30
class Solution {
public:
    int maximum69Number (int num) {

        int a = 0;

        int maxi = INT_MIN;

        int i = 0;

        int temp = num;


        while(num!=0){

            a = num%10;
            

            if(a == 6 ){

               maxi = max(maxi,i);

            }

            num = num/10;
            i++;

        }

        int b = temp+(3*pow(10,maxi));

        return b;


        
    }
};