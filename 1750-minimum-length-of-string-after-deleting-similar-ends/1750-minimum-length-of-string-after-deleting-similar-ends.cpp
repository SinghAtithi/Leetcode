class Solution {
public:
    int minimumLength(string s) {
        deque<char>dq;
        for(auto &x:s){
            dq.push_back(x);
        }
        while(true){
            if(dq.size()<=1)return dq.size();
            if(dq.front()!=dq.back()){
                return dq.size();
            }
            char c=dq.front();
            while(dq.front()==c){
                dq.pop_front();
                if(dq.size()<=0)return dq.size();
            }
            while(dq.back()==c){
                dq.pop_back();
                if(dq.size()<=0)return dq.size();
            }
        }
        return 0;
    }
};