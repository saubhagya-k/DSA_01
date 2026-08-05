// Last updated: 05/08/2026, 17:00:43
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>mset(wordList.begin(),wordList.end());

        unordered_set<string>visited;

        queue<string>que;

        que.push(beginWord);

        visited.insert(beginWord);

        int count = 1;


        while(!que.empty()){
            int n = que.size();

            while(n--){
                string curr = que.front();

                que.pop();


                if(curr == endWord){
                    return count;
                }


                for(char ch :"abcdefghijklmnopqrstuvwxyz"){
                    for(int i=0;i<curr.length();i++){
                        string neighbour = curr;

                        neighbour[i] = ch;


                        if(visited.find(neighbour) == visited.end() && mset.find(neighbour) != mset.end()){
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }


            }
            count++;
        }

        return 0;
        
    }
};