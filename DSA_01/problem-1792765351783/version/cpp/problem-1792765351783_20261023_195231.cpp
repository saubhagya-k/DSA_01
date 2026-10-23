// Last updated: 23/10/2026, 19:52:31
1class Solution {
2public:
3    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
4
5        vector<double>result;
6        multiset<double>window;
7        int n = nums.size();
8
9        for(int i=0;i<k;i++){
10            window.insert(nums[i]);
11        }
12
13        auto mid = next(window.begin(),k/2);
14
15        if(k%2!=0){
16            result.push_back(*mid);
17        }
18        else{
19            result.push_back((*mid + *prev(mid))/2.0);
20        }
21
22        for(int i=k;i<n;i++){
23
24            int incoming = nums[i];
25            int outgoing = nums[i-k];
26
27            // 1. Insert incoming and adjust mid pointer position
28            window.insert(incoming);
29            if (incoming < *mid) {
30                mid--; // New element fell into the lower half, shift mid left
31            }
32
33            // 2. Locate outgoing element and adjust mid before erasing
34            auto out_it = window.find(outgoing);
35            
36            // FIXED: Compares values instead of tree iterators directly
37            if (outgoing <= *mid) {
38                mid++; // Element leaving was in the lower half, balance mid right
39            }
40            window.erase(out_it);
41
42            // 3. Directly calculate median using your logic (No next() needed!)
43            if(k%2!=0){
44                result.push_back(*mid);
45            }
46            else{
47                result.push_back((*mid + *prev(mid))/2.0);
48            }
49        }
50
51        return result;
52    }
53};
54