// Last updated: 05/08/2026, 16:57:59
class Solution {
public:
    void reverseString(vector<char>& s) {

        int n = s.size();

        int left = 0;
        int right = n-1;


        while(right>left){
            swap(s[left],s[right]);
            right--;
            left++;
        }
        
    }
};