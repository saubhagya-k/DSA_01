// Last updated: 25/09/2026, 22:56:58
1class Solution {
2    string expression;
3    int idx;
4
5    // item -> letter | { expr }
6    set<string> item() {
7        set<string> ret;
8        if (expression[idx] == '{') {
9            idx++;
10            ret = expr();
11        } else {
12            ret = {string(1, expression[idx])};
13        }
14        idx++;
15        return move(ret);
16    }
17
18    // term -> item | item term
19    set<string> term() {
20        // Initialize an empty set and take its Cartesian product with
21        // subsequent results
22        set<string> ret = {""};
23        // An item starts with { or a lowercase letter; continue matching only
24        // when this condition is met
25        while (idx < expression.size() &&
26               (expression[idx] == '{' || isalpha(expression[idx]))) {
27            auto sub = item();
28            set<string> tmp;
29            for (auto& left : ret) {
30                for (auto& right : sub) {
31                    tmp.insert(left + right);
32                }
33            }
34            ret = move(tmp);
35        }
36        return move(ret);
37    }
38
39    // expr -> term | term, expr
40    set<string> expr() {
41        set<string> ret;
42        while (true) {
43            // Take the union with the result of term()
44            ret.merge(term());
45            // Continue if a comma is matched; otherwise, stop matching
46            if (idx < expression.size() && expression[idx] == ',') {
47                idx++;
48                continue;
49            } else {
50                break;
51            }
52        }
53        return move(ret);
54    }
55
56public:
57    vector<string> braceExpansionII(string expression) {
58        this->expression = expression;
59        this->idx = 0;
60        auto ret = expr();
61        return {ret.begin(), ret.end()};
62    }
63};