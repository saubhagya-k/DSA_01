// Last updated: 08/09/2026, 11:39:24
class Solution {
public:
    int brokenCalc(int startValue, int target) {

        if(startValue == target){
            return 0;
        }

        if(startValue>target){
            return startValue-target;
        }

        if(target%2==0){
            return 1+ brokenCalc(startValue,target/2);
        }


        return 1+brokenCalc(startValue,target+1);




        
    }
};