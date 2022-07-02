class Solution {
public:
    
    int MOD = 1000000007;
    
    long long maxDist(vector<int>& v, int last){
        v.push_back(last);
        sort(v.begin(), v.end());
        int ans = v[0];
        for(int i = 0; i < v.size() - 1; i++){
            ans = max(ans , v[i + 1] - v[i]);
        }
        return ans % MOD;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long maxH = maxDist(horizontalCuts, h);
        long long maxW = maxDist(verticalCuts, w);
        return (maxH * maxW) % MOD;
        
    }
};