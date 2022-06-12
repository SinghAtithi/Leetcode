class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        unordered_map<int,bool>mp;        
        int len = nums.size();

        for(int i = 0; i < len; i++){
            mp[nums[i]] = true;
        }
        
        int ans = 0;
        
        for(int i = 0; i < len; i++){
            int res = 0;
            int x = nums[i];
            int y = x - 1;
            while(mp[x] == true){
                res++;
                mp[x] = false;
                x++;
            }
            while(mp[y] == true){
                res++;
                mp[y] = false;
                y--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};