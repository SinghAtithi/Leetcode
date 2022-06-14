class Solution {
public:
    string decodeString(string s) {
        
        int len = s.size();
        stack<char>st;
        string ans = "";
        
        for(int i = 0; i < len; i++){
            if(s[i] == ']'){
                ans = "";
                string x = "";
                while(st.top() != '['){
                    x += st.top();
                    st.pop();
                }
                st.pop();
                reverse(x.begin(), x.end());
                string n = "";
                while(st.top() >= '0' && st.top() <='9'){
                    n.push_back(st.top());
                    st.pop();
                    if(st.size() == 0)
                        break;
                }
                int cnt = 0;
                while(n.size()){
                    cnt *= 10;
                    cnt += n.back() - '0';
                    n.pop_back();
                }
                while(cnt--){
                    ans += x;
                }
                for(auto &it : ans){
                    st.push(it);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        ans = "";
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};