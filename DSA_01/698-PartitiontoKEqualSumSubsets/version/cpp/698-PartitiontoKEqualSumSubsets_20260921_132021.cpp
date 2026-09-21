// Last updated: 21/09/2026, 13:20:21
1class Solution {
2public:
3    int distMoney(int money, int children) {
4
5        int perfect = 0;
6
7        int left_over_money = 0;
8
9        int remaining_children = 0;
10
11        if(money<children){
12            return -1;
13        }
14
15        money = money-children;
16
17        perfect = money/7;
18
19
20        left_over_money = money%7;
21
22        remaining_children = children-perfect;
23
24        if(perfect>=children){
25
26        if(perfect==children && left_over_money==0){
27            return children;
28        }
29
30        return children-1;
31
32        }
33        if(remaining_children == 1 && left_over_money==3){
34            return --perfect;
35        }
36
37
38
39
40        return perfect;
41
42
43
44
45        
46        
47    }
48};