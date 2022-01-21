class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,totCost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            totGas+=gas[i];
            totCost+=cost[i];
        }
        if(totGas<totCost){
            return -1;
        }
        int ans=-1;
        
        vector<int>dp(n);
        int tot=0;
        
        for(int i=0;i<n;i++){
            tot+=gas[i]-cost[i];
            if(tot<0){
                tot=0;
                ans=i;
            }
        }
        ans++;
        ans%=n;
        return ans;
        
        return ans;
    }
};