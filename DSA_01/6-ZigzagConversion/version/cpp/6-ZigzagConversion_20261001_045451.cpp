// Last updated: 01/10/2026, 04:54:51
1class Solution {
2public:
3    string convert(string s, int numRows) {
4
5        if(numRows<= 1 || numRows>=s.length()){
6            return s;
7        }
8
9        vector<string>collector(numRows);
10
11        int currentRow = 0;
12        bool goingdown = false;
13
14        for(char c:s){
15            collector[currentRow] += c;
16
17            if(currentRow == 0 || currentRow == numRows-1){
18                goingdown = !goingdown;
19            } 
20
21            currentRow += goingdown ? 1 : -1;
22        }
23
24        string final = "";
25
26        for(string &s : collector){
27            final+=s;
28        }
29
30        return final;
31        
32    }
33};