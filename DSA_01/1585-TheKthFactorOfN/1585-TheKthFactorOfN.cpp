// Last updated: 01/09/2026, 16:19:43
class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int>final;

        for(int i=1;i<=n;i++){

            if(n%i==0){
                final.push_back(i);
            }


        }
        if(final.size()<k){
            return -1;
        }

        int a = final[k-1];

        return a;
    
        
    }
};