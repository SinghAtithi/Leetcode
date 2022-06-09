class Solution {
public:
    
    int r(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size() - 1)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int ans = 1000000;
        for(int i = ind+1; i <= ind+nums[ind];i++){
            ans = min(ans, r(i,nums,dp)+1);
        }
        return dp[ind] = ans;
    }
    
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int>dp(len,-1);
        return r(0,nums,dp);
    }
};