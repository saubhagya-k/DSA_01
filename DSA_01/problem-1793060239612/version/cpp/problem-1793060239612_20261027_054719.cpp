// Last updated: 27/10/2026, 05:47:19
1class Solution {
2public:
3    int calculateScore(int a, int b) {
4
5
6        std::string binaryStr1 = std::bitset<32>(a).to_string();
7        std::string binaryStr2 = std::bitset<32>(b).to_string();
8
9        binaryStr1 = binaryStr1.erase(0,binaryStr1.find_first_not_of('0'));
10        binaryStr2 = binaryStr2.erase(0,binaryStr2.find_first_not_of('0'));
11
12        int n1 = binaryStr1.length();
13        int n2 = binaryStr2.length();
14
15        int count1 = 0;
16        int count2 = 0;
17
18        for( char c1 :binaryStr1){
19            if(c1 == '1'){
20
21                count1++;
22                
23            }
24        }
25
26        for(char c2 :binaryStr2){
27            if(c2 == '1'){
28
29                count2++;
30                
31            }
32        }
33
34
35        if(count1>=count2){
36            return count1*count2;
37        }
38        else{
39            return count2/count1;
40        }
41
42        
43        
44        
45    }
46};