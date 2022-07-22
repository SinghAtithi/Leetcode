class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans = 0;
        int len = nums.size();
        
        for(int i = 0; i < len; i++){
            ans ^= (i^nums[i]);
        }
        
        ans^=len;
        
        return ans;
        
    }
};