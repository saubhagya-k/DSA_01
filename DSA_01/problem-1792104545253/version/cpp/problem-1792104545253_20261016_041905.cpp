// Last updated: 16/10/2026, 04:19:05
1class Solution {
2public:
3    string frequencySort(string s) {
4
5        unordered_map<int,int>map;
6
7        for(char c: s){
8            map[c]++;
9        }
10
11        priority_queue<pair<int,char>>maxHeap;
12
13        for(auto &pair : map){
14            maxHeap.push({pair.second,pair.first});
15        }
16
17        string go = "";
18
19        while(!maxHeap.empty()){
20            auto[freq,ch] = maxHeap.top();
21            maxHeap.pop();
22
23            go.append(freq,ch);
24        }
25
26        return go;
27        
28    }
29};