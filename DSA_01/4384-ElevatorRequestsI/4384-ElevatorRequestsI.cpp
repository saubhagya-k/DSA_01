// Last updated: 23/08/2026, 18:24:32
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