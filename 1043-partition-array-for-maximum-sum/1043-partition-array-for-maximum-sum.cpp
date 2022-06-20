class Solution {
public:
    
    int dp[501];
    
    int r(int ind, vector<int>& arr, int &k){
        if(ind == arr.size()){
            return 0;
        }
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int x = 0;
        int maxi = INT_MIN;
        int ans = 0;
        
        for(int i = ind; i < ind + k; i++){
            if(i == arr.size())
                break;
            maxi = max(maxi , arr[i]);
            int temp = (i - ind + 1) * maxi;
            temp += r(i + 1, arr, k);
            ans = max(ans, temp);
        }
        return dp[ind] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        for(int i = 0; i <= arr.size();i++)
            dp[i] = -1;
        return r(0 , arr, k);
    }
};