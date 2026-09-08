// Last updated: 08/09/2026, 11:32:12
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruit, vector<int>& basket) {

        int n = fruit.size();

        int unplaced = 0;


        for(int i=0;i<n;i++){

            bool placed = false;

            for(int j=0;j<n;j++){

                if(fruit[i]<=basket[j]){
                    placed = true;
                    basket[j] = -1;

                    break;
                }

            }

            if(!placed){
                unplaced++;
            }
        }

        return unplaced;
        
    }
};