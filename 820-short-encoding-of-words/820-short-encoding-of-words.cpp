class Solution {
public:
    
    static bool comp(string &s, string &ss){
        return s.size() < ss.size();
    }
    
    bool check(string s, string ss){
        while(s.size()){
            if(s.back() == ss.back()){
                s.pop_back();
                ss.pop_back();
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int ans= 0;
        int len = words.size();
        sort(words.begin(), words.end(), comp);
                cout<<0;

        for(int i = 0; i < len; i++){
            ans++;
            ans += words[i].size();
            for(int j = i + 1; j < len;j++){
                if(check(words[i], words[j])){
                    ans--;
                    ans -= words[i].size();
                    // cout<<words[i]<<" "<<words[j]<<"\n";
                    break;
                }
            }
        }
        
        
        return ans;
    }
};