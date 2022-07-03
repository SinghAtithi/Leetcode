class Solution {
public:
    
    int dp[70][70][70];
    
    int maxPickup(int ax,int ay, int by, int &rows, int &cols,           vector<vector<int>>& grid){
        
        if(ax == rows || ay < 0 || by < 0 || ay >= cols || by >= cols)
            return 0;
        
        if(dp[ax][ay][by] != -1)
            return dp[ax][ay][by];
        
        int curr = grid[ax][ay];
        if(by != ay) curr += grid[ax][by];
        int ans = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                ans = max(ans, maxPickup(ax + 1, ay + i, by + j, rows, cols, grid));
            }
        }
        return dp[ax][ay][by] = ans + curr;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0; i < 70; i++){
            for(int j = 0; j < 70; j++){
                for(int k = 0; k < 70; k++)dp[i][j][k] = -1;
            }
        }
        
        return maxPickup(0,0,cols - 1, rows, cols, grid);
        
    }
};