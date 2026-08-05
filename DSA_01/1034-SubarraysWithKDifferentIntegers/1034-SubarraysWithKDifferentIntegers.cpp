// Last updated: 05/08/2026, 16:54:42
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int start = 0, count = 0;

        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            
            if (freq[nums[end]] == 1)
                k--;

            while (k < 0) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                    k++;
                start++;
            }

            count += end - start + 1;
        }

        return count;
    }
};
