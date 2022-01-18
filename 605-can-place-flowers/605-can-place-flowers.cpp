class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int k) {
        int n=v.size();
        if(k==0)return true;
        if(n==1){
            if(k>1)return false;
            if(v[0]==0 && k==1)return true;
            return false;
        }
        
        if(v[0]==0 && v.size()>1 && v[1]==0){
            v[0]=1;
            k--;
        }
        
        for(int i=1;i<n-1;i++){
            if(v[i]==0 && v[i-1]==0 && v[i+1]==0){
                v[i]=1;
                k--;
            }
        }
        if(v[n-1]==0 && v.size()>1 && v[n-2]==0){
            v[n-1]=1;
            k--;
        }
        return k<1;
    }
};