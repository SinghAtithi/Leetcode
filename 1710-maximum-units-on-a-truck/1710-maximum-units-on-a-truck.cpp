class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int> &b){
        return (a[1] > b[1]);
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int len = boxTypes.size();
        int ans = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        for(int i = 0; i < len; i++){
            if(truckSize == 0)
                break;
            int cap = min(boxTypes[i][0], truckSize);
            ans += cap * boxTypes[i][1];
            truckSize -= cap;
        }
        return ans;
    }
};