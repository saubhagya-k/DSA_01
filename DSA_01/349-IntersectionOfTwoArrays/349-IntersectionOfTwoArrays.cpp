// Last updated: 05/08/2026, 16:57:55
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


   int size = nums1.size();
   int size2 = nums2.size();

        unordered_set<int>main;
        vector<int>fil;

        for(int i=0; i<size;i++){
            main.insert(nums1[i]);
        }

        for(int i=0;i<size2;i++){
            if(main.find(nums2[i]) != main.end()){

                fil.push_back(nums2[i]);


                main.erase(nums2[i]);

            }
        }



        return fil;


        
    }

    
};