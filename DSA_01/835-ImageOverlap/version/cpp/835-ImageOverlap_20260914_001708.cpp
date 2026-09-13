// Last updated: 14/09/2026, 00:17:08
1class Solution {
2public:
3
4
5
6int countOverlaps(vector<vector<int>>& A,vector<vector<int>>& B,int& roff, int& coff){
7
8    int n = A.size();
9     int count = 0; 
10    for(int i=0;i<n;i++){
11        for(int j=0;j<n;j++){
12            int B_i = i+roff;
13            int B_j = j+coff;
14
15                       if(B_i < 0 || B_i >= n || B_j < 0 || B_j >= n){ 
16                continue;
17            }
18
19
20            if(A[i][j] == 1 && B[B_i][B_j] == 1){
21                count++;
22            }
23        }
24    }
25    return count;
26
27}
28    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
29
30        int n = A.size();
31
32        int maxoverlap = 0;
33
34        for(int roff = -n+1;roff<n;roff++){
35            for(int coff = -n+1;coff<n;coff++){
36                int count = countOverlaps(A,B,roff,coff);
37
38                maxoverlap = max(maxoverlap,count);
39            }
40        }
41
42
43
44        return maxoverlap;
45        
46    }
47};