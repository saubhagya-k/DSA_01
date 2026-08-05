// Last updated: 05/08/2026, 17:02:20
class Solution {
public:
    int mySqrt(int x) {

        if(x<2) return x;

        int left = 1,right = x/2;

       


        while(left<=right){

            long  mid = left + (right-left)/2;
            long sqrt = mid*mid;

            if(sqrt == x){
                return mid;
            }
            else if( sqrt<x){
                left = mid+1;
            }
            else{
                right = mid-1;
            }



            

        }

        return right;

       
        
    }
};