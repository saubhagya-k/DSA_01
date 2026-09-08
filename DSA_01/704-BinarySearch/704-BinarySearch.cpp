// Last updated: 08/09/2026, 13:52:14
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int min=0;
    int max=nums.size()-1;
    

    while(min <=max){

        int mid=min+(max-min)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid]<target){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }

    return -1;
        
    }
};