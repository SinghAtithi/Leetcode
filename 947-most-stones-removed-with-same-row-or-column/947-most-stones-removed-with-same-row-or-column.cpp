class Solution {
public:
    
    map<pair<int, int>, bool> vis;
    map < pair<int, int>, vector<pair<int, int>>> graph;
    int cnt = 0;

    void dfs(pair<int,int>n){
        vis[n] = true;
        if(n.first!=-1 && n.second!=-1){
            cnt++;
        }
        for(auto x:graph[n]){
            if(!vis[x])
                dfs(x);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vis.clear();
        graph.clear();
        int ans = 0;
        for (auto v : stones)
        {
            pair<int, int> x;
            x.first = v[0];
            x.second = v[1];
            graph[{-1, v[1]}].push_back(x);
            graph[x].push_back({-1, v[1]});
            graph[{v[0], -1}].push_back(x);
            graph[{x}].push_back({v[0], -1});
        }
        for (int i = 0; i < 10001;i++){
            if(!vis[{-1,i}]){
                cnt = 0;
                dfs({-1, i});
            }
            if (cnt > 0)
            {
                ans += cnt - 1;
                cnt=0;
            }
            if(!vis[{i,-1}]){
                cnt = 0;
                dfs({i, -1});
            }
            if (cnt > 0)
            {
                ans += cnt - 1;
                cnt=0;
            }
        }
        return ans;
    }
};