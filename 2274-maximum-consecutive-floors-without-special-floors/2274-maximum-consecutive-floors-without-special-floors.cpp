class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spl) {
        int ans = 0;
        sort(spl.begin(),spl.end());
        for(int i=1;i<spl.size();i++){
            ans = max(ans, spl[i] - spl[i-1] - 1);
        }
        return max({ans, spl[0] - bottom, top - spl[spl.size() - 1]});
    }
};