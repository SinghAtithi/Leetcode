class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int ans = 0;
        int i = 0, j = 0;
        int curr = 0;
        int len = nums.size();
        unordered_map<int,int>mp;
        
        while(j < len && i < len){
            int x = nums[j];
            if(mp[x] == 0){
                curr += x;
                ans = max(ans, curr);
                mp[x]++;
                j++;
            }
            else{
                while(i < j && nums[i] != x){
                    mp[nums[i]]--;
                    curr -= nums[i];
                    i++;
                }             
                mp[nums[i]]--;
                curr -= nums[i];
                i++;
            }
        }
        return ans;
    }
};