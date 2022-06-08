class Solution {
public:
    int removePalindromeSub(string s) {
        // bool pal = true;
        int len = s.size();
        int i = 0, j = len - 1;
        while(i < j){
            if(s[i] != s[j])
                return 2;
            i++,j--;
        }
        return 1;
    }
};