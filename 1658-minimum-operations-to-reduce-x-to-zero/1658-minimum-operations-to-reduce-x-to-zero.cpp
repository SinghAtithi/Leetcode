class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        
        int ans = -1;
        int len = nums.size();
        
        for(int ind = 1; ind < len; ind++){
            nums[ind] += nums[ind - 1];
        }
        
        int sum = nums[len - 1];
        int target = sum - x;
        unordered_map<int,int> mp;
        
        if(nums[len - 1] == x){
            ans = 0;
        }
            
        // cout<<target<<"\n";
        
        for(int ind = 0; ind < len; ind++){
            // cout<<nums[ind]<<" ";
            int z = mp[nums[ind] - target];
            if(z > 0){
                ans = max(ans,ind + 2 - z);
            }
            if(nums[ind] == target){
                ans = max(ans, ind + 1);
            }
            mp[nums[ind]] = ind + 2;
        }
        
        // cout<<"\n";
        
        if(ans == -1)
            return ans;
        return len - ans;
            
    }
};