class Solution {
public:
    
    // void deb(priority_queue<int> pq){
    //     while(pq.size()){
    //         cout<<pq.top()<<" ";
    //         pq.pop();
    //     }cout<<"\n";
    // }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int len = nums.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < len; i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            // deb(pq);
        }
        return pq.top();
    }
};