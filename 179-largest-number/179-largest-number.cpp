class Solution {
public:
    
    static bool comp(int &a, int &b){
        
        string s = to_string(a);
        string t = to_string(b);
        
        return (s+t) > (t+s);
        
    }
    
    string largestNumber(vector<int>& nums) {
        
        string ans = "";
        
        sort(nums.begin(), nums.end(), comp);
        
        for(auto x: nums){
            ans += to_string(x);
        }
        
        reverse(ans.begin(),ans.end());
        while(ans.back()=='0'){
            if(ans.size()==1)break;
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
       
        
        return ans;
        
    }
};