class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int len = nums.size();
        vector<int>dp(len, 0);

        
        dp[0] = 1;
        bool flag = true;
        
        for(int i = 1; i < len; i++){
            dp[i] = dp[i - 1];
            if(flag){
                if(nums[i] > nums[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                    flag = !flag;
                }
            }
            else{
                if(nums[i] < nums[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                    flag = !flag;
                }
            }
        }
        
        int x = dp[len - 1];
        flag = false;
        dp[0] = 1;
        
        for(int i = 1; i < len; i++){
            dp[i] = dp[i - 1];
            if(flag){
                if(nums[i] > nums[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                    flag = !flag;
                }
            }
            else{
                if(nums[i] < nums[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                    flag = !flag;
                }
            }
        }
        
        
        return max(x, dp[len - 1]);
    }
};