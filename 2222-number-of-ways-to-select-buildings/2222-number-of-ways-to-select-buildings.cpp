class Solution {
public:
    long long numberOfWays(string s) {
        
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