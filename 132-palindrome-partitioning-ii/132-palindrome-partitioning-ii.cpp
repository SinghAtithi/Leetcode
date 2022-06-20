class Solution {
public:
    bool check(int i,int j,string &s)
     { 
        for(;i<j;i++,j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }

    int r(int ind,string &s,vector<int> &dp)
    {
        if(ind==s.size())
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];

        int mini = 1e9;
        for(int j=ind;j<s.size();j++)
        {
            if(check(ind,j,s))
                mini = min(mini,1+r(j+1,s,dp));
        }
        return dp[ind] = mini;
    }

    int minCut(string &s) 
    {
        vector<int> dp(s.size(),-1);
        return r(0,s,dp)-1;
    }
};