// Last updated: 05/08/2026, 16:54:54
class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }

        if(n == 1){
            return 1;
        }
        int first = 0;
        int second = 1;
        int current = 0;

        for(int i=2;i<=n;i++){
            current = first+second;
            first = second;
            second = current;
        }

        return current;
        
    }
};