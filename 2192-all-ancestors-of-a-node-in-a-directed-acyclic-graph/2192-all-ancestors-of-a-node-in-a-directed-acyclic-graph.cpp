class Solution {
public:
    
    unordered_map<int,vector<int>> graph;
    unordered_map<int, bool>vis;
    
    void dfs(int par, int n, vector<vector<int>>&ans){
        if(vis[n])
            return;
        vis[n] = true;
        if(par != n)ans[n].push_back(par);
        for(auto x:graph[n]){
            dfs(par, x, ans);
        }
    }
    
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        graph.clear();
        int len = edges.size();
        for(int i = 0; i < len ;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>>ans(n);
        for(int i = 0; i < n; i++){
            vis.clear();
            dfs(i,i, ans);
        }
        return ans;
    }
};