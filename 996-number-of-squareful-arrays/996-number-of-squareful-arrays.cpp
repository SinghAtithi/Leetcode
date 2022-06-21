class Solution {
public:
    set<vector<int>>st;
    int ans;
    bool f(int &a, int &b){
        int x = pow((a + b), 0.5);
        return (x*x) == (a+b);
    }
    
    bool check(vector<int>&v){
        int n = v.size();
        for(int i = 0; i < n - 1; i++){
            if(f(v[i], v[i+1]) == false)
                return false;
        }
        return true;
    }
    
    void r(vector<int> v, vector<int> nums){
        if(st.find(v) != st.end()){
            return;
        }
        st.insert(v);
        if(v.size() == nums.size()){
            ans++;
            return;
        }
        int ans = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == -1)
                continue;
            int x = nums[i];
            if(v.size() == 0){
                v.push_back(x);
                nums[i] = -1;
                r(v,nums);
                v.pop_back();
                nums[i] = x;
            }
            else{
                if(f(x, v.back())){
                    v.push_back(x);
                    nums[i] = -1;
                    r(v,nums);
                    v.pop_back();
                    nums[i] = x;
                }
            }
        }
    }
    
    
    int numSquarefulPerms(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        st.clear();
        r({}, nums);
        return ans;
    }
};