class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& prod, string p) {
        
        map<string,set<string>>mp;
        
        int len = prod.size();
        for(int i = 0; i < len; i++){
            string s = "";
            for(char &c:prod[i]){
                s+=c;
                mp[s].insert(prod[i]);
            }
        }
        
        vector<vector<string>>ans;
        
        string s = "";
        // int i = 0;
        for(char &c:p){
            s+=c;
            vector<string>temp;
            for(string x:mp[s]){
                temp.push_back(x);
                if(temp.size() == 3)
                    break;
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};