class Solution {
public:
    int numSquares(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int dp[n+1];
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            int x = 1;
            dp[i] = INT_MAX;
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