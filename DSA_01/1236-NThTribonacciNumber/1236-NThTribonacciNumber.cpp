// Last updated: 05/08/2026, 16:53:56
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n==2){
            return 1;
        }

        int first = 0;
        int second = 1;
        int third =  1;
        int current = 0;

        for(int i = 3;i<=n;i++){
            current = first+second+third;
            first = second;
            second = third;
            third = current;
        }

        return current;
        
        
    }
};