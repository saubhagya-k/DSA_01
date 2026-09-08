// Last updated: 08/09/2026, 13:03:21
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int n = people.size();

        int i = 0;
        int j = n-1;

      int   boatCount = 0;
     

        while(i<=j){

            if(people[i]+people[j]<=limit){
                boatCount++;
                i++;
                j--;

               

            }
            else if(people[j]<=limit){
                boatCount++;
                j--;
            }


        }

        return boatCount;
        
    }
};