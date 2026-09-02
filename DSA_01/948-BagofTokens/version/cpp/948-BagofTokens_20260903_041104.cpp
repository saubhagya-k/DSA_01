// Last updated: 03/09/2026, 04:11:04
1class Solution {
2public:
3    int bagOfTokensScore(vector<int>& tokens, int power) {
4        int n = tokens.size();
5
6        sort(tokens.begin(),tokens.end());
7
8        int i = 0;
9        int j = n-1;
10
11        int maxScore = 0;
12
13        int score = 0;
14
15        while(i<=j){
16            if(power>=tokens[i]){
17
18                power-=tokens[i];
19
20                score++;
21                i++;
22                maxScore = max(maxScore,score);
23
24            }
25            else if(score>=1){
26                power = power+tokens[j];
27                j--;
28                score--;
29            }
30            else{
31                return maxScore;
32            }
33        }
34
35        return maxScore;
36        
37    }
38};