class Solution {
public:
    int trap(vector<int>& height) {
        
        int len = height.size();
        vector<int>dp(len);
        int maxi = INT_MIN;
        
        for(int i = 0; i < len; i++){
            maxi = max(maxi, height[i]);
            dp[i] = maxi;
        }
        
        maxi = INT_MIN;
        
        int ans = 0;
        
        for(int i = len - 1; i >=0 ; i--){
            maxi = max(maxi, height[i]);
            dp[i] = min(maxi,dp[i]);
            ans += max(0,dp[i]-height[i]);
        }
        
        return ans;
        
    }
};