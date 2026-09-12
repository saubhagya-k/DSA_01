// Last updated: 12/09/2026, 15:00:10
1class Solution {
2public:
3    int minimumRounds(vector<int>& tasks) {
4
5        int count = 0;
6
7
8
9        unordered_map<int,int>map(tasks.size());
10
11
12        for(int i=0;i<tasks.size();i++){
13            map[tasks[i]]++;
14        }
15
16        int n = map.size();
17
18    for (auto& pair : map) {
19
20        while(pair.second >0){
21
22          if(pair.second == 1){
23            return -1;
24          }
25
26          else if( pair.second == 4){
27            pair.second -=2;
28            count++;
29          }
30
31          else if( pair.second >= 3){
32            pair.second -=3;
33            count++;
34          }
35
36          else if(pair.second == 2){
37            pair.second-=2;
38            count++;
39          }
40          
41        }
42    
43    
44
45   
46}
47
48        return count;
49
50
51        
52    }
53};