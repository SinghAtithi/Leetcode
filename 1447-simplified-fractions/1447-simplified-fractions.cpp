class Solution {
public:    
    vector<string> simplifiedFractions(int n) {
        unordered_set<string>st;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i%j==0){
                    continue;
                }
                string s="";
                if(__gcd(i,j)!=1 && i!=1){continue;}
                s+=to_string(i);
                s+='/';
                s+=to_string(j);
                st.insert(s);
            }
        }
        vector<string>ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};