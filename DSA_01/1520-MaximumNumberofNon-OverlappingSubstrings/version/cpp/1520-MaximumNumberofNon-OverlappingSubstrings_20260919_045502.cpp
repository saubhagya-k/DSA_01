// Last updated: 19/09/2026, 04:55:02
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4
5        int n = arr.size();
6
7        int i=0;
8        int j = 0;
9
10        vector<int>arri(n,INT_MAX);
11
12        int currSum = 0;
13        int minLength = INT_MAX;
14
15        int result = INT_MAX;
16
17
18        while(j<n){
19            currSum+=arr[j];
20            while(i<=j && currSum>target){
21                currSum-=arr[i++];
22
23            }
24
25
26                if(currSum == target){
27                 int   len = j-i+1;
28
29
30                    if(i>0 && arri[i-1] != INT_MAX){
31                    result = min(result,len+arri[i-1]);
32
33                    }
34
35                    minLength = min(minLength,len);
36
37                  
38                }
39
40                arri[j] = minLength;
41              
42            
43            j++;
44        }
45
46        return result == INT_MAX?-1:result;
47        
48    }
49};