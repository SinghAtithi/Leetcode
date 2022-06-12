class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int ans = 0;
        int i = 0, j = 0;
        int curr = 0;
        int len = nums.size();
        unordered_map<int,int>mp;
        
        for(; i < len && j < len;){
            if(mp[nums[j]] == 0){
                curr += nums[j];
                ans = max(ans, curr);
                mp[nums[j]]++;
                j++;
            }
            else{
                while(i < j && nums[i] != nums[j]){
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