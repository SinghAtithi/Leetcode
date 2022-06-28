class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int len = temp.size();
        vector<vector<int>> tempInd(101);
        vector<int> ind(101,0);
        
        for(int i = 0; i < len; i++){
            tempInd[temp[i]].push_back(i);
        }
        
        vector<int>ans(len, 0);
        
        for(int i = 0; i < len; i++){
            int x = 999999;
            for(int j = temp[i] + 1; j <= 100; j++){
                if(tempInd[j].size() > ind[j])
                    x = min(x, tempInd[j][ind[j]]);
            }
            if(x != 999999)
                ans[i] = x - i;
            ind[temp[i]]++;
        }
        return ans;
    }
};