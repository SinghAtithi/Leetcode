class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // int maxi=INT_MIN;
        int mini=INT_MAX;
        bool ans=false;
        int M=1000000007;
        int n=nums.size();
        vector<int>aagese(n+5,M);
        vector<int>peechese(n+5,M);
        
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x>mini)aagese[i]=mini;
            mini=min(mini,x);
        }
        mini=INT_MAX;
        set<int>st;
        st.insert(M);
        
        for(int i=n-1;i>=0;i--){
            int x=nums[i];
            int t=*st.upper_bound(-x);
            if(t==M){
                st.insert(-x);
                continue;
            }
            t*=-1;
            int a=aagese[i];
            // cout<<x<<" "<<t<<" "<<a<<"\n";
            
            if(x>a && x>t && t>a){
                ans=true;
            }
            st.insert(-x);
        }
        
        return ans;
    }
};