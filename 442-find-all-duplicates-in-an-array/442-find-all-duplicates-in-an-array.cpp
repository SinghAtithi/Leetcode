class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int len = nums.size();
        
        for(int i = 0; i < len; i++){
            int x = abs(nums[i]) - 1;
            // cout<<nums[x]<<" ";
            if(nums[x] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[x] *= -1;
            }
            
        }
        
        return ans;
    }
};