class Solution {
public:
        map<string,string> par;
        map<string, int> power;
    
    string findPar(string &s){
        if(par[s] == s)
            return s;
        else return findPar(par[s]);
    }
    
    bool f(string &a, string &b){
        int n = a.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i])
                cnt++;
        }
        return (cnt == 2 || cnt == 0);
    }
    
    int numSimilarGroups(vector<string>& strs) {
            
        
        int len = strs.size();
        for(auto &s: strs){
            par[s] = s;
            power[s] = 1;
        }
        int ans = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len ; j++){
                string a = strs[i], b = strs[j];
                if(f(a, b)){
                    string A = findPar(a);
                    string B = findPar(b);
                    int x = power[a];
                    int y = power[b];
                    if(A == B){
                        power[A]++;
                    }
                    else if(x > y){
                        par[B] = A;
                        power[A] += power[B];
                    }
                    else{
                        par[A] = B;
                        power[B] += power[A];
                    }
                    ans = max({ans, power[A], power[B]});
                }
            }
        }
        set<string>st;
        for(int i = 0; i < len; i++){
            st.insert(findPar(strs[i]));
        }
        return st.size();
    }
};