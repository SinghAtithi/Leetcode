class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        unordered_map<int,bool>mp;
        for(auto &x : nums){
            mp[x] = true;
        }
        
        int ans = 0;
        
        for(auto &x: nums){
            int res = 0;
            int y = x - 1;
            while(mp.find(x) != mp.end()){
                res++;
                mp.erase(x);
                x++;
            }
            while(mp.find(y) != mp.end()){
                res++;
                mp.erase(x);
                y--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};