class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int ans = 0;
        int sum = 0;
        int len = cardPoints.size();
        
        
        
        for(int i = 1; i < len; i++){
            cardPoints[i] += cardPoints[i - 1];
        }
        k = len - k;
        if(k == 0)
            return cardPoints[len - 1];
        
        sum = cardPoints[len - 1];
        ans = sum - cardPoints[k - 1];
        
        for(int i = k; i < len; i++){
            ans = max(ans, sum - (cardPoints[i] - cardPoints[i - k]) );
        }
        return ans;
    }
};