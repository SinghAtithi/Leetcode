class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int len = people.size();
        sort(people.begin(),people.end());
        reverse(people.begin(),people.end());
        multiset<int> st;
        int ans = 0;
        st.insert(1e9 + 7);
        
        for(int i = 0; i < len; i++){
            auto x = st.lower_bound(people[i]);
            // cout<<people[i]<<" "<<*x<<"\n";
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