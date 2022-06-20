class Solution {
public:
    
    static bool comp(string &s, string &ss){
        return s.size() < ss.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string>st;
        int len = words.size();
        int ans = 0;
        
        sort(words.begin(), words.end(), comp);
        
        for(int i = 0; i < len; i++){
            ans += words[i].size() + 1;
            string s = "";
            for(int j = words[i].size() - 1; j >= 0; j--){
                s += words[i][j];
                if(st.find(s) != st.end()){
                    st.erase(s);
                    ans -= s.size() + 1;
                }
            }
            st.insert(s);
            // cout<<ans<<"\n";
        }
        return ans;
    }
};