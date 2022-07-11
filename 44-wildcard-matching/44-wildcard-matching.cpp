class Solution {
public:
    
    int rec(int sInd, int pInd, string &s, string &p, vector<vector<int>>& dp){
        // cout<<sInd<<" "<<pInd<<"\n";
        if(sInd == s.size() && pInd == p.size())
            return true;
        if(sInd == s.size()){
            if(pInd < p.size() && p[pInd] == '*')
                return rec(sInd, pInd + 1, s, p, dp);
            return false;
        }
        
        if(dp[sInd][pInd] != -1)
            return dp[sInd][pInd];
        
        if(p[pInd] == '?')
            return dp[sInd][pInd] =  rec(sInd + 1, pInd + 1, s, p, dp);
        else if(p[pInd] == '*'){
            bool ans = false;
            ans |= rec(sInd, pInd + 1, s, p, dp);
            ans |= rec(sInd + 1, pInd, s, p, dp);
            ans |= rec(sInd + 1, pInd + 1, s, p, dp);
            return dp[sInd][pInd] = ans;
        }
        else if(p[pInd] == s[sInd])
            return dp[sInd][pInd] = rec(sInd + 1, pInd + 1, s, p, dp);
        else return dp[sInd][pInd] = false;
        
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        int ans = rec(0, 0, s, p, dp);
        cout<<ans<<"\n";
        return (ans == 0) ? false : true;
    }
};