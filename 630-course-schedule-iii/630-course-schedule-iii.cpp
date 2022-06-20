class Solution {
public:
    
    // #define vector<int> vi
    
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        priority_queue<int> pq;
        int curr = 0;
        sort(courses.begin(), courses.end(), comp);
        int len = courses.size();
        for(int i = 0; i < len; i++){
            if(curr + courses[i][0] <= courses[i][1]){
                pq.push(courses[i][0]);
                curr += courses[i][0];
            }
            else if(pq.size() > 0){
                if(pq.top() > courses[i][0] && (curr - pq.top() + courses[i][0] < curr)){
                    int temp = curr - pq.top();
                    if(temp + courses[i][0] <= courses[i][1]){
                        pq.pop();
                        pq.push(courses[i][0]);
                        curr = temp + courses[i][0];
                    }
                }
            }
        }
        return pq.size();
    }
};