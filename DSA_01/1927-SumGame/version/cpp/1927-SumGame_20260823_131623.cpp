// Last updated: 23/08/2026, 13:16:23
1class Solution {
2public:
3    bool sumGame(string num) {
4
5        int n = num.size();
6
7        // int count_blanks = 0;
8
9        // for(int i=0;i<n;i++){
10        //     if(nums[i]=="?"){
11
12        //         count_blanks++;
13                
14        //     }
15        // }
16
17        // if(count_blanks%2 !=0){
18        //     return true;
19        // }
20
21        int lc =0;
22        int lb =0;
23        int rc =0;
24        int rb =0;
25
26        for(int i=0;i<n/2;i++){
27            if(num[i] !='?'){
28                lc+= num[i]-'0';
29            }
30            else{
31                lb++;
32            }
33        }
34
35          for(int i=n/2;i<n;i++){
36            if(num[i] !='?'){
37                rc+= num[i]-'0';
38            }
39            else{
40                rb++;
41            }
42        }
43
44        if(lb+rb == 0){
45            return lc!=rc;
46        }
47
48        if((lb+rb)%2 ==1){
49
50            return true;
51
52        }
53
54        int mini = min(lb,rb);
55
56        lb-=mini;
57        rb-=mini;
58        if(lb>0){
59            if(lc>rc){
60                return true;
61            }
62            if(9*(lb/2) == rc-lc){
63                return false;
64            }
65            else{
66                return true;
67            }
68        }
69        else{
70            if(rc>lc){
71                return true;
72            }
73            if(9*(rb/2) == lc-rc){
74                return false;
75            }
76            else{
77                return true;
78            }
79        }
80
81    
82        
83    }
84};