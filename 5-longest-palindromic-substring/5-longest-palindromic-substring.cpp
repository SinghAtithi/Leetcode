class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();
        string ans = "";
        
        for(int center = 0; center < len; center++){
            int temp = 1;
            int i = center - 1, j = center + 1;
            while(i >= 0 &&  j < len){
                if(s[i] != s[j])
                    break;
                temp += 2;
                i--, j++;
            }
            i++, j--;
            if(j - i + 1 > ans.size()){
                ans = "";
                for(int k = i; k <= j; k++){
                    ans += s[k];
                }
            }
        }
        for(int center = 0; center < len; center++){
            int temp = 0;
            int i = center , j = center + 1;
            while(i >= 0 &&  j < len){
                if(s[i] != s[j])
                    break;
                temp += 2;
                i--, j++;
            }
            i++, j--;
            if(j - i + 1 > ans.size()){
                ans = "";
                for(int k = i; k <= j; k++){
                    ans += s[k];
                }
            }
        }
        
        return ans;
    }
};