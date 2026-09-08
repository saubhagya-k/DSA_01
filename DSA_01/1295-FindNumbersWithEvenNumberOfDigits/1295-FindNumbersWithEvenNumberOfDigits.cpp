// Last updated: 08/09/2026, 11:36:40
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