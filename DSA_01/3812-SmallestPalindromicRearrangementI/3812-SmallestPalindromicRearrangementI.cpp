// Last updated: 05/08/2026, 16:51:48
class Solution {
public:
    string smallestPalindrome(string s) {

       string t = "";

       string u = "";


        int n = s.length();
        int a = n/2;

        if(n==1){
            return s;
        }

        if(n%2 == 0){
            for(int i=0;i<a;i++){

                t += s[i];
                }

                sort(t.begin(),t.end());

                u = t;

                reverse(u.begin(),u.end());

                for(int i=0;i<a;i++){

                    t+=u[i];

                }
                
                return t;
                }



                else {
                    for(int i=0;i<=a-1;i++){
                        t += s[i];
                    }
                    sort(t.begin(),t.end());

                    u = t;
                    reverse(u.begin(),u.end());

                    t+=s[a];

                    for(int i=0;i<=a-1;i++){

                        t+=u[i];

                    }

                    return t;
                    
                }
        
    }
};