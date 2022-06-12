class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int prod = 1;
        int zeroCnt = 0;
        int len = nums.size();
        vector<int>ans(len);
        
        for(int i = 0; i < len;i++){
            if(nums[i] != 0)
                prod *= nums[i];
            else
                zeroCnt++;
        }
        
        for(int i = 0; i < len; i++){
            if(zeroCnt > 1){
                ans[i] = 0;
            }
            else{
                if(nums[i] == 0){
                    ans[i] = prod;
                }
                else if(zeroCnt > 0){
                    ans[i] = 0;
                }
                else{
                    ans[i] = prod / nums[i];
                }
            }
        }
        return ans;
    }
};