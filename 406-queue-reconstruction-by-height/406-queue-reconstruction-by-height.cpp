class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int len = people.size();
        vector<vector<int>> ans(len);
        
        sort(people.begin(), people.end(), comp);
        
        vector<int> taken(len, 0);
        
        for(auto &x: people){
            int z = 0;
            for(int i = 0; i < len; i++){
                if(taken[i] == 0 && z == x[1]){
                    ans[i] = x;
                    taken[i] =1;
                    break;
                }
                if(taken[i] == 0)
                    z++;
            }
        }
        return ans;
    }
};