class Solution {
public:
        map<int,int> par;
        map<int, int> power;
    
    int findPar(int &s){
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
        for(int i = 0; i < len; i++){
            power[i] = 1;
            par[i] = i;
        }
        int ans = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len ; j++){
                string a = strs[i], b = strs[j];
                if(f(a, b)){
                    int A = findPar(i);
                    int B = findPar(j);
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
        set<int>st;
        for(int i = 0; i < len; i++){
            st.insert(findPar(i));
        }
        return st.size();
    }
};