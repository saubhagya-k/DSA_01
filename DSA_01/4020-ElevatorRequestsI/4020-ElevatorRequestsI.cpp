// Last updated: 08/09/2026, 11:31:03
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int a = requests.size();

        int b = 0;

        int total = 0;

        for(int i=0;i<a;i++){
          total = total+abs(requests[i]-b);
            b = requests[i];
            
        }

        return total;

        
        
    }
};