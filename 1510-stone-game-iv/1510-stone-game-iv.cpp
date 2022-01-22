class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1);
        dp[0]=false;
        for(int i=1;i<=n;i++){
            bool ans=false;
            int t=1;
            while(true){
                int x=t*t;
                if(i-x<0)break;
                if(dp[i-x]==false)ans=true;
                t++;
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};