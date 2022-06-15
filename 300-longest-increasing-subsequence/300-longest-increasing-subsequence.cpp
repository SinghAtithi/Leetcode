class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int INF = 1e9 + 7;
        set<int>st;
        st.insert(INF);
        // reverse(nums.begin(), nums.end());
        
        for(int &x: nums){
            int t = *st.lower_bound(x);
            if(t != INF){
                st.erase(t);
                st.insert(x);
            }
            else{
                st.insert(x);
            }
        }
        return st.size() - 1;
    }
};