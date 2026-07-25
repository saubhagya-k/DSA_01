class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int,int>map;

        

        int n = numbers.size();

        for(int i=0;i<n;i++){
            if(map.find(target-numbers[i])!=map.end()){

              

                return {map[target-numbers[i]],i+1};
                
            }
            map[numbers[i]] = i+1;
        }

        return {};
        
    }
};