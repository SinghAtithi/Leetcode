class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> mp;
        int len = strs.size();
        
        for(int ind = 0; ind < len; ind++){
            string s = strs[ind];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[ind]);
        }
        
        vector<vector<string>>ans;
        
        for(auto &x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};