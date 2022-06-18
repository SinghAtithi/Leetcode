class WordFilter {
public:
    
    
    unordered_map<string, int> mp;
    
    WordFilter(vector<string>& words) {
        mp.clear();
        int len = words.size();
        
        for(int i = 0; i < len; i++){
            
            string word = words[i];
            int n = word.size();
            
            for(int ii = 1; ii <= n; ii++){
                string s = word.substr(0, ii );
                s += '.';
                
                for(int j = n - 1; j >= 0; j--){
                    s += word[j];
                    mp[s] = i;
                }
                
            }
            
        }
         
    }
    
    int f(string prefix, string suffix) {
        prefix += '.';
        reverse(suffix.begin(), suffix.end());
        prefix += suffix;
        if(mp.find(prefix) == mp.end())
            return -1;
        return mp[prefix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */