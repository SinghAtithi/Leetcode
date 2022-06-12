class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int ans = 0;
        int i = 0, j = 0;
        int curr = 0;
        int len = nums.size();
        set<int> st;
        
        while(j < len && i < len){
            int x = nums[j];
            if(st.find(x) == st.end()){
                curr += x;
                ans = max(ans, curr);
                st.insert(x);
                j++;
            }
            else{
                while(i < j && nums[i] != x){
                    st.erase(nums[i]);
                    curr -= nums[i];
                    i++;
                }
                st.erase(nums[i]);
                curr -= nums[i];
                i++;
            }
        }
        return ans;
    }
};