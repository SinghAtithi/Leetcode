class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            int x = 1;
            while(true){
                if(i - (x * x) < 0)
                    break;
                dp[i] = min(dp[i], dp[i - (x * x)] + 1);
                x++;
            }
        }
        return dp[n];
    }
};