class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int len = nums.size();
        int ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i < len; i++){
            mini = min(mini, nums[i]);
        }
        for(int i = 0; i < len;i++){
            ans += nums[i] - mini;
        }
        return ans;
    }
};