class Solution {
public:
    
    int rec(int ind1, int ind2, string word1, string word2, vector<vector<int>>& dp){
        
        if(ind1 == word1.size() && ind2 == word2.size())
            return 0;
    
        if(ind1 == word1.size() || ind2 == word2.size())
            return word1.size() - ind1 + word2.size() - ind2;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] =  rec(ind1 + 1, ind2 + 1, word1, word2 , dp); 
        }
        
        return dp[ind1][ind2] = 1 + min(rec(ind1 + 1, ind2, word1, word2, dp), rec(ind1, ind2 + 1, word1,                                                                        word2, dp));
    
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return rec(0, 0, word1, word2, dp);
    }
};