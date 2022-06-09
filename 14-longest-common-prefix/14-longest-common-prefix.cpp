class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int ind = 0;
        
        while(true){
            // cout<<ind<<" ";
            char ch = strs[0][ind];
            for(auto &x:strs){
                if(x.size() == ind)
                    return ans;
                if(x[ind] != ch)
                    return ans;
            }
            ans+=ch;
            ind++;
        }
        
        return "";
    }
};