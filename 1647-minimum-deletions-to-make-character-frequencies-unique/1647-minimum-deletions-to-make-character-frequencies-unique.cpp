class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26, 0);
        int len = s.size();
        int ans = 0;
        for(int i = 0; i < len; i++){
            freq[s[i] - 'a']++;
        }
        
        unordered_set<int> st;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0)
                continue;
            
            while(true){
                if(st.find(freq[i]) == st.end()){
                    st.insert(freq[i]);
                    break;
                }
                ans++;
                freq[i]--;
                if(freq[i] == 0)
                    break;
            }
            
        }
        return ans;
        
    }
};