class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int len = nums.size();
        vector<int>dpp(len, 0);
        vector<int>dp(len, 0);

        
        dp[0] = dpp[0] = 1;
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
        
        
        flag = false;
        
        for(int i = 1; i < len; i++){
            dpp[i] = dpp[i - 1];
            if(flag){
                if(nums[i] > nums[i - 1]){
                    dpp[i] = dpp[i - 1] + 1;
                    flag = !flag;
                }
            }
            else{
                if(nums[i] < nums[i - 1]){
                    dpp[i] = dpp[i - 1] + 1;
                    flag = !flag;
                }
            }
        }
        
        
        return max(dp[len - 1], dpp[len - 1]);
    }
};