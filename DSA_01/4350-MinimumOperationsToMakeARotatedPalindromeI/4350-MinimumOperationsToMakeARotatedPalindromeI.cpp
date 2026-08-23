// Last updated: 23/08/2026, 18:24:33
class Solution {
public:
    int minOperations(string s) {

        string dorivexalu = s;

        int n = dorivexalu.length();

        int min_total_ops = 1e9;

        string doubled = dorivexalu+dorivexalu;

        for(int rot = 0;rot<n;rot++){
            int inc = 0;
            int left = rot;
            int right = rot + n-1;

            while(left<right){
                char c1 = doubled[left];
                char c2 = doubled[right];

                if(c1 != c2){
                    int diff = abs(c1-c2);

                    inc += min(diff,26-diff);
                }
                left++;
                right--;
            }
            min_total_ops = min(min_total_ops,rot+inc);
        }
        return min_total_ops;
        
        
    }
};