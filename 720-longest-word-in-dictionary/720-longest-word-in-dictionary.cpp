class Solution {
public:
    
    static bool comp(string &a, string &b){
        if(a.size() == b.size())
            return a > b;
        return a.size() < b.size();
    }
    
    string longestWord(vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        string ans = "";
        set<string>st;
        sort(words.begin(),words.end(),comp);
        
        st.insert("");
        
        int len = words.size();
        
        for(int i =  0; i < len; i++){
            char x = words[i].back();
            words[i].pop_back();
            // cout<<words[i] <<"\n";
            if(st.find(words[i]) != st.end()){
                words[i] += x;
                ans = words[i];
                st.insert(words[i]);
            }
        }
        
        return ans;
    }
};