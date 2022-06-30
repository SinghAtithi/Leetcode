class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int len = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len;i++){
            ans += nums[i] - nums[0];
        }
        return ans;
    }
};