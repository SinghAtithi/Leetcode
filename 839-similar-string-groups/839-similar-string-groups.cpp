class Solution {
public:
        
    
    int findPar(int &s, vector<int> &par){
        if(par[s] == s)
            return s;
        else return findPar(par[s], par);
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
        vector<int>par(len), power(len);
        for(int i = 0; i < len; i++){
            power[i] = 1;
            par[i] = i;
        }
        int ans = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len ; j++){
                string a = strs[i], b = strs[j];
                if(f(a, b)){
                    int A = findPar(i, par);
                    int B = findPar(j, par);
                    int x = power[i];
                    int y = power[j];
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
        unordered_set<int>st;
        for(int i = 0; i < len; i++){
            st.insert(findPar(i, par));
        }
        return st.size();
    }
};