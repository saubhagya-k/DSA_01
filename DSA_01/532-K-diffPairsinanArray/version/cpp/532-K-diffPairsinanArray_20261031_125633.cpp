// Last updated: 31/10/2026, 12:56:33
1class Solution {
2public:
3    int findPairs(vector<int>& nums, int k) {
4
5        unordered_map<int,int>map;
6
7        int count = 0;
8
9        for(int x : nums){
10            map[x]++;
11        }
12
13        int n = nums.size();
14
15        for(auto pair: map){
16            int key = pair.first;
17            int freq = pair.second;
18
19
20            if(k>0){
21                if(map.find(key+k)!=map.end()){
22                    count++;
23                }
24            }
25            else{  //k==0
26
27            if(freq>1){
28                count++;
29            }
30
31
32            }
33
34        }
35
36        return count;
37
38
39        
40    }
41};