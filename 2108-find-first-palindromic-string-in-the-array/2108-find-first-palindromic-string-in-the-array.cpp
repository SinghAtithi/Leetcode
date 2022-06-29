class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        int len = words.size();
        for(int i = 0; i < len; i++){
            int l = 0, r = words[i].size() - 1;
            while(l < r){
                if(words[i][l] != words[i][r])
                    break;
                l++;
                r--;
            }
            if(l >= r)
                return words[i];
        }
        return "";
    }
};