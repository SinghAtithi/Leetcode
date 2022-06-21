class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int len = heights.size();
        priority_queue<int> pq;
        
        int i = 0;

        for(; i < len - 1; i++){
            // cout<<i<<" "<<bricks<<" "<<ladders<<"\n";
            int diff = heights[i + 1] - heights[i];
            if(diff <= 0)
                continue;
            if(diff <= bricks){
                pq.push(diff);
                bricks -= diff;
            }
            else{
                if(ladders == 0)
                    break;
                ladders--;
                int x = 0;
                if(pq.size()) {
                    x = pq.top();
                    pq.pop();
                    bricks += x;
                }
                bricks -= min(diff, x);
                pq.push(min(diff, x));
            }
        }
        
        return i;
    }
};