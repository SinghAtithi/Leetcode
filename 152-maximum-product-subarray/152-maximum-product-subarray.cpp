class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int len = nums.size();
        int curr = 1;
        
        for(int i = 0 ; i < len ; i++){
            curr *= nums[i];
            res = max(res, curr);
            if(curr == 0)
                curr = 1;
        }
        
        curr = 1;
        
        for(int i = len-1 ; i >= 0; i--){
            curr *= nums[i];
            res = max(res, curr);
            if(curr == 0)
                curr = 1;
        }
        
        return res;
    }
};