class Solution {
public:
    
    int dp[20][1001][2];
    
    int r(int ind, int sum, int &target, vector<int>& nums){
        
        if(ind == nums.size())
            return (sum == target) ? 1 : 0;
        
        int flag = (sum < 0) ? 1 : 0;
        
        // cout<<ind<<" "<<sum<<" "<<flag<<"\n";
        
        if(dp[ind][abs(sum)][flag] != -1)
            return dp[ind][abs(sum)][flag];
        
        int a = r(ind + 1 , sum + nums[ind], target, nums);
        int b = r(ind + 1 , sum - nums[ind], target, nums);
        
        
        
        return dp[ind][abs(sum)][flag] = a + b;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        if(nums.size() == 1)
            return (abs(nums[0]) == abs(target)) ? 1 : 0;
        
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 1001; j++)
                dp[i][j][0] = dp[i][j][1] = -1;
        
        return r(0, 0, target, nums);
    }
};