class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);
        // cout.tie(0);
    }
    
    bool book(int start, int end) {
        auto it = s.lower_bound({start,end});
        bool ans;
        if(it==s.end()){
            if(s.size()){
            auto it1=it;
            it1--;
            if(start>=(*it1).second) ans=true;
            else ans =false;
            }else
            ans=true;
        }
        else if(it==s.begin()){
            if(end<=(*it).first) ans= true;
            else ans=false;
        }else{
            auto it1=it;
            it1--;
            if(end<=(*it).first&&start>=(*it1).second) ans=true;
            else ans =false;
        }
        if(ans)
        s.insert({start,end});
        return ans;
    }
};