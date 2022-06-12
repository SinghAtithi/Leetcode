class Solution {
public:
    
    void r(int ind, string s, string ss, vector<string> &ans){
        if(ind == s.size()){
            ans.push_back(ss);
            return;
        }
        r(ind+1,s,(ss+s[ind]),ans);
        if(s[ind] >= 'a' && s[ind] <= 'z'){
            ss += s[ind] - 'a' + 'A';        
            r(ind+1,s,ss,ans);

        }
        else if(s[ind] >= 'A' && s[ind] <= 'Z'){
            ss += s[ind] - 'A' + 'a';
            r(ind+1,s,ss,ans);

        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        r(0,s,"",ans);
        return ans;
    }
};