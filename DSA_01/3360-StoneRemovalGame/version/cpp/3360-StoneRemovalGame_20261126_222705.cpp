// Last updated: 26/11/2026, 22:27:05
1class Solution {
2public:
3    bool canAliceWin(int n) {
4
5        int alice  = 10;
6
7        int bob = 9;
8
9
10        while(n>=0){
11            if(alice>0 && alice<=n){
12
13                n = n-alice;
14
15
16            }
17             else{
18                if(alice>n){
19                    return false;
20                    break;
21                }
22               
23            }
24            if(bob>0 && bob<=n){
25                n = n-bob;
26            }
27            else{
28                if(bob>n){
29                    return true;
30                    break;
31                }
32            }
33
34           
35
36            alice = alice -2;
37            bob = bob-2;
38
39            
40
41
42        }
43
44        return true;
45        
46    }
47};