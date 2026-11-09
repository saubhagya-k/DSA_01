// Last updated: 09/11/2026, 22:53:04
1class Solution {
2public:
3    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
4        vector<int> count(k, 0);
5        set<int> free;
6        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
7
8        // All servers are free at the beginning.
9
10        for (int i = 0; i < k; ++i) {
11            free.insert(i);
12        }
13        
14        for (int i = 0; i < arrival.size(); ++i) {
15            int start = arrival[i];
16            // Move free servers from 'busy' to 'free'.
17            while (!busy.empty() && busy.top().first <= start) {
18                auto [_, serverId] = busy.top();
19                busy.pop();
20                free.insert(serverId);
21            }
22
23            // If we have free servers, use binary search to find the 
24            // target server.
25            if (!free.empty()) {
26                auto ptr = free.lower_bound(i % k);
27                if (ptr == free.end()) {
28                    ptr = free.begin();
29                }
30                int busyId = *ptr;
31                free.erase(busyId);
32                busy.push(make_pair(start + load[i], busyId));
33                count[busyId]++;
34            }
35        }
36
37        // Find the servers that have the maximum workload.
38        vector<int> answer;
39        auto maxJob = *max_element(count.begin(), count.end());
40        for (int i = 0; i < k; ++i) {
41            if (count[i] == maxJob) {
42                answer.push_back(i);
43            }
44        }
45        
46        return answer;
47    }
48};