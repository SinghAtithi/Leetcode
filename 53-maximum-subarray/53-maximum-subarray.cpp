class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN;
        int len = nums.size();
        int temp = 0;
        
        for(auto num : nums){
            temp += num;
            ans = max({ans, temp, num});
            if(temp < 0)
                temp = 0;
        }
        
        return ans;
    }
};