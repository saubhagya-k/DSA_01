// Last updated: 07/08/2026, 00:22:03
class Solution {
public:
    int smallestNumber(int n, int t) {

       while(true){
        if(final(n,t)){

            return n;

        }
        n++;
       }
      
    }

    int final(int n,int t){

        long long product =1;

        while(n>0){
            int a = n%10;

            product *=a;
            n = n/10;


        }

        
        

        return (product%t==0);



    }
};