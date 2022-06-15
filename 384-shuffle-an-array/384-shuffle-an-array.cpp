class Solution {
public:
    
    vector<int> arr;
    
    Solution(vector<int>& nums) {
        
        arr.clear();
        
        for(int &x:nums){
            arr.push_back(x);
        }    
        
    }
    
    vector<int> reset() {
        vector<int> ans = arr;
        return arr;
    }
    
    vector<int> shuffle() {
        
        int len = arr.size();
        
        vector<int>ans = arr;
        
        for(int i = 0; i < len; i++){
            int x = rand() % len;
            swap(ans[i],ans[x]);
        }
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */