class Solution {
public:
    
    int minMoves(vector<int>& nums, int len , int x){
        int ans = 0;
        for(int i = 0; i < len ;i++){
            ans += abs(x - nums[i]);
        }
        return ans;
    }
    
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int ans = minMoves(nums, len , nums[(len - 1)/2]);
        if(len % 2 == 0){
            ans = min(ans, minMoves(nums, len, nums[len / 2]));
        }
        return ans;
    }   
};