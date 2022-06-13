class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        int ans;
        int row = triangle.size();
        
        if(row == 1){
            return triangle[0][0];
        }
        
        for(int i = 1; i < row; i++){
            int temp = INT_MAX;
            ans = INT_MAX;
            for(int j = 0; j <= i; j++){
                int x = INT_MAX;
                if(j != 0){
                    x = min(x, triangle[i-1][j-1]);
                }
                if(j != i){
                    x = min(x, triangle[i-1][j]);
                }
                triangle[i][j] += x;
                ans = min(ans,triangle[i][j]);
            }
        }
        return ans;
    }
};