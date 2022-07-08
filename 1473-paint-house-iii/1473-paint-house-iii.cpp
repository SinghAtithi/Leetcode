class Solution {
public:
    int memo[100][100][21];
    int rec(vector<int>&houses, vector<vector<int>>&cost, int &target, int &m, int &n, int cnt, int ind, int prevCol)
    {
        if(ind==m){
            // cout<<cnt<<endl;
            if(cnt==target)
                return 0;
            return 1e7;
        }
        
        if(memo[cnt][ind][prevCol]!=-1)
            return memo[cnt][ind][prevCol];
        
        if(houses[ind]!=0)
        {
            int curr=houses[ind];
            while(ind<m && houses[ind]==curr)
                ind++;
            int temp=0;
            if(curr!=prevCol)
                temp++;
            return memo[cnt][ind][prevCol]=rec(houses,cost,target,m,n,cnt+temp,ind,curr);
        }
        else
        {
            int ans=1e7;
            
            for(int i=1;i<=n;i++)       
            {
                if(i==prevCol)
                    continue;
                ans=min(ans,cost[ind][i-1]+rec(houses,cost,target,m,n,cnt+1,ind+1,i));
            }
            
            if(prevCol!=0)
                ans=min(ans,cost[ind][prevCol-1]+rec(houses,cost,target,m,n,cnt,ind+1,prevCol));
            
            return memo[cnt][ind][prevCol]=ans;
        }        
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo,-1,sizeof(memo));
        int val=rec(houses,cost,target,m,n,0,0,0);
        if(val==1e7)
            return -1;
        return val;
    }
};