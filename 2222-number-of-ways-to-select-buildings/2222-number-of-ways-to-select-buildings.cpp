class Solution {
public:
    long long numberOfWays(string s) {
        ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
        long long effZeros = 0;
        long long effOnes = 0;
        long long zeros = 0, ones = 0;
        long long ans = 0;
        
        for(char &x:s){
            if(x == '0'){
                effZeros += ones;
                ans += effOnes;
                zeros++;
            }
            else{
                effOnes += zeros;
                ans += effZeros;
                ones++;
            }
        }
        return ans;
    }
};