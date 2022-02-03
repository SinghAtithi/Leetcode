class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        
        set<int>st;
        for(int i=0;i<n;i++){
            if(st.find(target-nums[i])!=st.end()){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            st.insert(nums[i]);
            mp[nums[i]]=i;
        }
        return ans;
    }
};