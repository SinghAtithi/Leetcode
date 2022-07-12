class Solution {
public:
    
    bool isEdgePresent(int x, int y, vector<vector<int>>& edges){
        vector edge({x, y});
        int ind = lower_bound(edges.begin(), edges.end(), edge) - edges.begin();
        if(ind < edges.size())
            return edge == edges[ind];
        return false;
    }
    
    int dfs(int root, int par, vector<vector<int>>& graph, vector<vector<int>>& edges){
        // cout<<root<<" "<<par<<"\n";
        int isEdge = (isEdgePresent( par, root, edges)) ? 1 : 0;
        int ans = isEdge;
        
        for(int &child : graph[root]){
            if(child != par){
                ans += dfs(child, root, graph, edges);
            }
        }
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int> >graph(n);
        
        for(auto &edge : connections){        
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
        }
        
        sort(connections.begin(), connections.end());
        
        return dfs(0, 0, graph, connections);
        
    }
};