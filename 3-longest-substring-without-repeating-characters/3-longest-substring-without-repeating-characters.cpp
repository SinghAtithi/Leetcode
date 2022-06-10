class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.size();
        unordered_map<char,int> lastOccur;
        
        int temp = 0;
        int ans = 0;
        
        for(int i = 0; i < len; i++){
            
            char ch = s[i];
            if(temp <= lastOccur[ch])
                temp = lastOccur[ch] + 1;
            
            ans = max(ans,(i + 1) -  temp + 1);
            
            lastOccur[ch] = i+1;
            
        }
        return ans;
    }
};