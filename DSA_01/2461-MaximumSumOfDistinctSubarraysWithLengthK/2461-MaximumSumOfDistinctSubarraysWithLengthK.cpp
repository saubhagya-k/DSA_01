// Last updated: 08/09/2026, 11:33:35
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>freq;

        long long maxSum = 0;

        long long sum = 0;
        int n = nums.size();

        for(int i=0;i<k;i++){
            sum +=nums[i];

            freq[nums[i]]++;
            
        }

        if(freq.size() == k){
            maxSum = sum;
        }


        for(int i=k;i<n;i++){
            int incomming = nums[i];

            sum += incomming;
            freq[incomming]++;


            int outgoing = nums[i-k];

            sum -= outgoing;
            freq[outgoing]--;

            if(freq[outgoing] == 0){
                freq.erase(outgoing);
            }


            


            if(freq.size() == k){
                maxSum = max(maxSum,sum);
            }
        }

        return maxSum;


        
    }
};