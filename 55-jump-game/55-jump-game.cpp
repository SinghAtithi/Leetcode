class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int len = nums.size();
        int maxDis = 1;
        
        for(int i = 0; i < len;i++){
            if(maxDis == 0)
                return false;
            maxDis--;
            maxDis = max(maxDis, nums[i]);
        }
        return true;
    }
};