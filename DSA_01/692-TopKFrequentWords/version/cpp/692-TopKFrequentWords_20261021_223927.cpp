// Last updated: 21/10/2026, 22:39:27
1class Solution {
2public:
3    vector<string> topKFrequent(vector<string>& words, int k) {
4
5        unordered_map<string,int>map;
6
7        vector<string>final;
8
9        for(const string& word: words){
10            map[word]++;
11        }
12
13       
14
15        vector<pair<string,int>>freqvec(map.begin(),map.end());
16
17        sort(freqvec.begin(),freqvec.end(), [](const pair<string,int>&a, const pair<string,int>&b){
18            if(a.second == b.second){
19                return a.first<b.first;
20            }
21
22            return a.second>b.second;
23        });
24
25      
26         
27        for(int i = 0; i < k; i++) {
28            final.push_back(freqvec[i].first);
29        }
30
31        return final;
32
33        
34    }
35};