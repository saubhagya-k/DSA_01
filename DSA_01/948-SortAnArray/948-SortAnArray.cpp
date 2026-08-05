// Last updated: 05/08/2026, 16:55:05
class Solution {
public:

vector<int>temp;

void mergSort(vector<int>& nums,int left,int right){
    if(left >=right) return;

    int mid = left+(right-left)/2;

    mergSort(nums,left,mid);
    mergSort(nums,mid+1,right);
    
    int i=left;
    int j= mid+1;
    int k = left;

    while(i<=mid && j<=right){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }

    while(i<=mid){
        temp[k++] = nums[i++];
    }

    while(j<=right){
        temp[k++] = nums[j++];
    }

    for(int index = left;index<= right;index++){
        nums[index] = temp[index];
    }



}




    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        temp.resize(n);


        mergSort(nums,0,n-1);

        return nums;


        
    }
};