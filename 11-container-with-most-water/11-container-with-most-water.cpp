class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1;
        int ans = 0;
        
        while(i < j){
            int curr = min(height[i] , height[j]) * (j - i);
            ans = max(ans, curr);
            height[i] < height[j] ? i++ : j--;
        }
        
        return ans;
        
    }
};