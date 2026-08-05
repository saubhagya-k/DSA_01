// Last updated: 05/08/2026, 16:57:52
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int>lele;

        vector<int>haha;

        int size = nums1.size();
        int size2 = nums2.size();

        for(int i=0;i<size;i++){
            lele[nums1[i]]++;
        }

        for(int j=0;j<size2;j++){

            if(lele[nums2[j]]>0){
                haha.push_back(nums2[j]);

                lele[nums2[j]]--;
            }
        }

        return haha;


        


        
    }
};