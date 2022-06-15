class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        s += " ";
        string temp = "";
        
        for(auto &x: s){
            if(x == ' '){
                if(temp.size() > 0){
                    st.push(temp);
                }
                temp = "";
            }
            else{
                temp += x;
            }
        }
        string ans = "";
        while(st.size()){
            ans += st.top();
            ans += ' ';
            st.pop();
        }
        if(ans.size()>0){
            ans.pop_back();
        }
        return ans;
    }
};