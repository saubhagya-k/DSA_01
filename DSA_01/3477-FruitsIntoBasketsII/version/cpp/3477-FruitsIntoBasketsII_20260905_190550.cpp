// Last updated: 05/09/2026, 19:05:50
1class Solution {
2public:
3    int numOfUnplacedFruits(vector<int>& fruit, vector<int>& basket) {
4
5        int n = fruit.size();
6
7        int unplaced = 0;
8
9
10        for(int i=0;i<n;i++){
11
12            bool placed = false;
13
14            for(int j=0;j<n;j++){
15
16                if(fruit[i]<=basket[j]){
17                    placed = true;
18                    basket[j] = -1;
19
20                    break;
21                }
22
23            }
24
25            if(!placed){
26                unplaced++;
27            }
28        }
29
30        return unplaced;
31        
32    }
33};