class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mini=INT_MAX;
        for(auto &x:prices){
            ans=max(ans,x-mini);
            mini=min(mini,x);
        }
        return ans;
    }
};