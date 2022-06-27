class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       
        int ans = 0;
        set<int> st;
        set<pair<int,int>>found;
        int len = nums.size();
        
        for(int i = 0; i < len; i++){
            int x = nums[i];
            if(st.find(x + k) != st.end())
                found.insert({x,x + k});
            if(k != 0 && st.find(x - k) != st.end())
                found.insert({x - k,x});
            st.insert(x);
            // cout<<ans<<" ";
        }
        return found.size();
    }
};