// Last updated: 05/08/2026, 16:53:39
class Solution {
    public: bool Evennumber(int num){
        int digitsCount = 0;

        while(num!=0){
            num = num/10;
            digitsCount++;
        }

        return digitsCount%2 == 0;
    }



 



public:
    int findNumbers(vector<int>& nums) {

        int evenCount = 0;

        for(int i=0;i<nums.size();i++){
            if(Evennumber(nums[i])){
                evenCount++;
            }
        }

        return evenCount;


        
    }
};