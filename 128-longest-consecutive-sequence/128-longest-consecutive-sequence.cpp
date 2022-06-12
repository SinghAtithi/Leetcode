class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
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
                // cout<<x<<" ";
                mp.erase(x);
                x++;
            }
            while(mp.find(y) != mp.end()){
                res++;
                // cout<<y<<" ";
                mp.erase(x);
                y--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};