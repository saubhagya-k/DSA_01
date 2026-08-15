// Last updated: 15/08/2026, 20:19:13
1class Solution {
2public:
3    int elevatorRequests(int n, vector<int>& requests) {
4
5        int a = requests.size();
6
7        int b = 0;
8
9        int total = 0;
10
11        for(int i=0;i<a;i++){
12          total = total+abs(requests[i]-b);
13            b = requests[i];
14            
15        }
16
17        return total;
18
19        
20        
21    }
22};