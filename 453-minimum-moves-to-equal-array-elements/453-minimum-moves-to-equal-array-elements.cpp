class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int len = nums.size();
        int ans = 0;
        long long sum = 0;
        int mini = INT_MAX;
        for(int i = 0; i < len;i++){
            mini = min(mini , nums[i]);
            sum += nums[i];
        }
        return sum - (mini * len);
    }
};