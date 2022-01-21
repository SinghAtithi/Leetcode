class Solution {
public:
    
        
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    int M = 1000000;
    vector<int> p(n, 0);
    vector<int> pp(n, 0);
    int ans = 0;
    int buy = 1000000;
    for (int i = 0; i < n; i++)
    {
        buy=min(buy,prices[i]);
        p[i] = max(p[i], prices[i] - buy);
        if(i!=0){
            p[i]=max(p[i],p[i-1]);
        }
    }

    buy = -M;

    for(int i=n-1;i>=0;i--)
    {
        buy=max(buy,prices[i]);
        pp[i] = max(pp[i], buy - prices[i]);
        if(i!=n-1){
            pp[i]=max(pp[i],pp[i+1]);
        }
        ans = max(ans, p[i] + pp[i]);
    }
    return ans;
    }
};