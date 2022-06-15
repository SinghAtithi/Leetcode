class Solution {
public:
    
    set<int>st;
    
    void r(int ind, string &s, vector<string>& wordDict, bool &ans){
       
        if(st.find(ind) != st.end())
            return;
        
        st.insert(ind);
        
        if(ind == s.size()){
            ans = true;
            return;            
        }
        
        int lenStr = s.size();
        
        for(string &x : wordDict){
            int lenWord = x.size();
            if(lenWord > lenStr - ind)
                continue;
            bool match = true;
            for(int i = ind; i < ind + lenWord; i++){
                if(s[i] != x[i - ind]){
                    match = false;
                    break;
                }
            }
            
            if(match == true){
                r(ind + lenWord, s, wordDict, ans);
            }
        }
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        bool ans = false;
        r(0,s,wordDict,ans);
        return ans;
    }
};