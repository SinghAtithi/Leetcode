

class Solution {
public:
    
    int dp[200][20001];
    
    bool radhe(vector<int> &nums, int ind, int sum, int remsum)
    {
        if(ind == 0) {
            if((sum + nums[0]) == remsum - nums[0]) return true;
            else if(sum == remsum) return true;
            return false;
        }
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        //take
        bool take = false;
        if((sum + nums[ind] )<= (remsum-nums[ind])) take = radhe(nums, ind-1, sum +             nums[ind], remsum - nums[ind]); 

        //ntake
        bool ntake = radhe(nums,ind - 1, sum, remsum);

          return dp[ind][sum] = take | ntake;
    }
    
    bool canPartition(vector<int>& nums) {
        int remsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            remsum += nums[i];
        }
        for(int i = 0; i < nums.size();i++){
            for(int j = 0;  j <= nums.size()*100;j++){
                dp[i][j] = -1;
            }
        }
        return radhe(nums, nums.size()-1, 0, remsum);
    }
};