// Last updated: 12/10/2026, 00:24:12
1class Solution {
2public:
3    int sumOddLengthSubarrays(vector<int>& arr) {
4
5        int n = arr.size();
6
7        int result = 0;
8
9        for(int i=0;i<n;i++){
10            int start = n-i;
11            int end = i+1;
12            int total = start*end;
13            int odd = total/2;
14
15            if(total%2==1){
16                odd++;
17            }
18
19           result += odd*arr[i];
20
21
22        }
23        return result;
24        
25    }
26};