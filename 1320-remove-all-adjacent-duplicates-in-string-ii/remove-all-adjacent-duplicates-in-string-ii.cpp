class Solution {
public:
    string removeDuplicates(string s, int k) {

        //here we need to use vector as a stack for eaiser string reconstruction at the end

        vector<pair<char,int>>stack;

        for(char c: s){
            if(!stack.empty() && stack.back().first == c){
                stack.back().second++;
            }
            else{
                stack.push_back({c,1});
            }


            if(stack.back().second == k){
                stack.pop_back();
            }
        }

        string f = "";

        for(auto &x:stack){
           f.append(x.second,x.first);
        }


        return f;

        
        
    }
};