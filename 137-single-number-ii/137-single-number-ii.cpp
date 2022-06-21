class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        int len = nums.size();
        
        for(int i = 0; i < 32; i++){
            int cnt = 0;
            for(int j = 0; j < len; j++){
                if(((nums[j]>>i) & 1) != 0){
                    cnt++;
                }
            }
            if(cnt % 3 != 0){
                ans += (1<<i);
            }
            // t*=2;
        }
        return ans;
    }
};