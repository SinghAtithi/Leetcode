class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int len = people.size();
        sort(people.begin(),people.end());
        multiset<int> st;
        int ans = 0;
        st.insert(1e9 + 7);
        
        for(int i = len - 1; i >= 0; i--){
            auto x = st.lower_bound(people[i]);
            if(*x != (1e9 + 7)){
                st.erase(x);
            }
            else{
                st.insert(limit - people[i]);
                ans++;
            }
        }
        return ans;
    }
};