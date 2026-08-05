// Last updated: 05/08/2026, 16:58:20
class Solution {
public:
    bool isUgly(int n) {

        if(n<=0) return false;

        if(n==1) return true;

        int factors[] = {2,3,5};

        for(int f :factors){
            while(n%f==0){
                n/=f;
            }
        }

        return n==1;
        
    }
};