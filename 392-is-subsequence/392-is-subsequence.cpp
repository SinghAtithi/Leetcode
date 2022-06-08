class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len = s.size();
        int i = 0;
        for(auto &x:t){
            if(x ==  s[i])
                i++;
        }
        // cout<<i<<" ";
        return i == len;
    }
};