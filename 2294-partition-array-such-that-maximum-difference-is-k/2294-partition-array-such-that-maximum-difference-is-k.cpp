class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int len = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int curr = 0;
        for(int i =0; i < len; i++){
            if(nums[i]-nums[curr]<=k)
                continue;
            else {ans++;curr=i;}
        }
        return ans+1;
    }
};