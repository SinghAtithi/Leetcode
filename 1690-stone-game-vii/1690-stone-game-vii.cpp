class Solution {
public:
    int n;
    // bool flag;
    int dp[1001][1001];
    int r(int i, int j, vector<int>&v, int sum){
        if(j<i)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(true){
            int q=abs(sum-v[i]-r(i+1,j,v,sum-v[i]));
            int qq=abs(sum-v[j]-r(i,j-1,v,sum-v[j]));
            ans=max(q,qq);
        }
        return dp[i][j]= ans;
        
    }
    
    int stoneGameVII(vector<int>& stones) {
        n=stones.size(); 
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        int sum=0;
        for(auto &x:stones){
            sum+=x;
        }
        int ans=r(0,n-1,stones,sum);
        return ans;
    }
};