class Solution {
public:
    
    
    void dfs(int n, stack<int>& topo, bool &isCycle, vector<vector<int>>& adj, vector<int>&vis){
        vis[n] = 1;
        
        if(isCycle)
            return;
        
        for(auto x: adj[n]){
            if(vis[x] == 1)
                isCycle = true;
            else if(vis[x] == 0)
                dfs(x, topo, isCycle, adj, vis);
        }
        vis[n] = 2;
        topo.push(n);

    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>> adj(n);
        
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
        }
        
        stack<int>topo;
        vector<int>vis(n, 0);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                bool isCycle = false;
                dfs(i, topo, isCycle, adj, vis);
                if(isCycle)
                    return -1;
            }
        }
        
        stack<int>temp;
        while(topo.size()){
            temp.push(topo.top());
            topo.pop();
        }
        
        topo = temp;
        
        vector<vector<int>>dp(n, vector<int>(26,0));
        while(topo.size()){
            int curr = topo.top();
            dp[curr][colors[curr] - 'a'] = 1;
            ans = max(ans, 1);
            
            for(int x: adj[curr]){
                for(int i = 0; i < 26; i++){
                    dp[curr][i] = max(dp[curr][i], dp[x][i] + ((colors[curr] - 'a') == i));
                    ans = max(ans, dp[curr][i]);
                }
            }
            topo.pop();
        }
        return ans;
        
    }
};