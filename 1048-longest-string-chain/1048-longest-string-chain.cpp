class Solution {
public:
    
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }
    
    bool check(string &s, string &t){
        
        // ios_base :: sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        
        int cnt = 0;
        int n = s.size();
        int m = t.size();
        
        if((m - n) != 1)
            return false;
        
        for(int i = 0; i < n; i++){
            if(s[i]!=t[i + cnt]){
                cnt++;
                i--;
                if(cnt > 1)
                    return false;
            }
        }
        return true;
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        int len = words.size();
        vector<int>dp(len,0);
        int ans = INT_MIN;
        
        sort(words.begin(), words.end(), comp);
        
        for(int i = 0; i < len; i++){
            dp[i] = max(dp[i] , 1);
            for(int j = i + 1; j < len; j++){
                if(check(words[i], words[j])){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};