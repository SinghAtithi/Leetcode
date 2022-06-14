class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        
        int n = numCourses;
        if(numCourses == 1) return true;
        vector<vector<int>> graph(n);
        vector<int> indeg(n,0);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> pq;
        for(int i=0;i<n;i++){
            if(indeg[i] ==0){
                pq.push(i);
            }
        }
        int cnt = 0;
        vector<int> ans;
        while(!pq.empty()){
            cnt++;
            int x =pq.front();
            pq.pop();
            ans.push_back(x);
            for(auto it:graph[x]){
                indeg[it]--;
                if(indeg[it] == 0){
                    pq.push(it);
                }
            }
        }
        return (ans.size() == numCourses);

    }
};