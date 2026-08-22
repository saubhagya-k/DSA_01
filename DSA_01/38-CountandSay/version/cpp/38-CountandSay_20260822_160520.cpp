// Last updated: 22/08/2026, 16:05:20
1class Solution {
2public:
3    string countAndSay(int n) {
4
5        if(n==1){
6            return "1";
7        }
8
9        string say = countAndSay(n-1);
10
11        string result = "";
12
13        for(int i=0;i<say.length();i++){
14
15            char ch = say[i];
16
17            int count = 1;
18
19            while(i<say.length()-1 && say[i] == say[i+1] ){
20                count++;
21                i++;
22            }
23
24
25            result += to_string(count)+string(1,ch);
26
27
28
29
30
31        }
32
33        return result;
34        
35    }
36};