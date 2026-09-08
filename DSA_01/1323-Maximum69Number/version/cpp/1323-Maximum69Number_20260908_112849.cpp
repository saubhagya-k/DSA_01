// Last updated: 08/09/2026, 11:28:49
1class Solution {
2public:
3    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
4
5        int n = capacity.size();
6
7        int full = 0;
8
9
10        vector<int>diff(n,0);
11
12
13        
14
15       
16
17        for(int i=0;i<n;i++){
18
19            diff[i] = capacity[i]-rocks[i];
20
21            
22            
23        }
24
25        sort(diff.begin(),diff.end());
26
27         for(int i=0;i<n;i++){
28
29            if(additionalRocks>=diff[i]){
30                additionalRocks-=diff[i];
31                full++;
32            }
33            else{
34                break;
35            }
36
37
38        }
39
40
41        return full;
42
43
44        
45    }
46};