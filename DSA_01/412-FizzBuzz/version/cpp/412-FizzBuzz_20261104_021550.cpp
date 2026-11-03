// Last updated: 04/11/2026, 02:15:50
1class Solution {
2public:
3    vector<string> fizzBuzz(int n) {
4
5
6        vector<string>final;
7
8        for(int i=1;i<=n;i++){
9
10            if(i%3==0 && i%5==0){
11                final.push_back("FizzBuzz");
12            }
13            else if(i%3==0 && i%5!=0){
14                final.push_back("Fizz");
15            }
16
17            else if(i%3!=0 && i%5==0){
18                final.push_back("Buzz");
19            }
20
21            else{
22                string s = to_string(i);
23                final.push_back(s);
24            }
25
26        }
27
28        return final;
29        
30    }
31};