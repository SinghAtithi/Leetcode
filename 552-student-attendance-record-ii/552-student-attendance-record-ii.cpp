class Solution {
public:
    long long N;
    long long M = 1000000007;
    long long dp[100005][4][5];
    long long r(long long i, long long a, long long l)
    {
        if (a > 1)
            return 0;
        if (l > 2)
            return 0;
        if (i == N)
            return 1;

        if (dp[i][a][l] != -1)
        {
            return dp[i][a][l];
        }

        long long q = 0, qq = 0, qqq = 0;
        q = r(i + 1, a, 0);
        qq = r(i + 1, a + 1, 0);
        qqq = r(i + 1, a, l + 1);
        q %= M;
        qqq %= M;
        qq %= M;
        return dp[i][a][l] = ((q + qq + qqq) % M);
    }
    
    
    int checkRecord(int n) {
        N=n;
        for(int i=0;i<n+5;i++){
            for(int j=0;j<=3;j++){
                for(int k=0;k<5;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return r(0,0,0);
    }
};