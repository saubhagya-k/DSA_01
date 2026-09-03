// Last updated: 03/09/2026, 06:08:37
1class Solution {
2public:
3    int brokenCalc(int startValue, int target) {
4
5        if(startValue == target){
6            return 0;
7        }
8
9        if(startValue>target){
10            return startValue-target;
11        }
12
13        if(target%2==0){
14            return 1+ brokenCalc(startValue,target/2);
15        }
16
17
18        return 1+brokenCalc(startValue,target+1);
19
20
21
22
23        
24    }
25};