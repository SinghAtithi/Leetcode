class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int len = nums.size();
        unordered_set<int>elements;
        vector<int>ans(2);
        ans[0] = -100000, ans[1] = 1000000;
        
        for(int i  = 0; i < len; i++){
            for(int j = 0; j < nums[i].size();j++){
                elements.insert(nums[i][j]);
            }
            nums[i].push_back(10000000);
        }
        
        for(int x: elements){
            int mini = x, maxi = -1000000;
            for(int i = 0; i < len; i++){
                int z = *lower_bound(nums[i].begin(), nums[i].end(), x);
                maxi = max(maxi , z);
            }
            if(maxi - x < ans[1] - ans[0])
                ans[1] = maxi, ans[0] = mini;
            else if(maxi - mini == ans[1] -  ans[0])
                if(ans[0] > mini)
                    ans[0] = mini, ans[1] = maxi;
        }
        return ans;
    }
};