// Last updated: 10/11/2026, 02:25:26
1/*
2// Definition for Employee.
3class Employee {
4public:
5    int id;
6    int importance;
7    vector<int> subordinates;
8};
9*/
10
11class Solution {
12public:
13    int getImportance(vector<Employee*> employees, int id) {
14
15        unordered_map<int,Employee*> empMap;
16
17        for(auto emp : employees){
18            empMap[emp->id] = emp;
19        }
20
21        queue<int>q;
22
23        int ans = 0;
24
25        q.push(id);
26
27        while(!q.empty()){
28            int currentId = q.front();
29            q.pop();
30
31            Employee* currEmp = empMap[currentId];
32
33            ans += currEmp->importance;
34
35            for(int subId : currEmp->subordinates){
36                q.push(subId);
37            }
38        }
39
40        return ans;
41
42
43
44
45        
46    }
47};