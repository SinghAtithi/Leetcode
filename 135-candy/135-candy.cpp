class Solution {
public:
    int candy(vector<int>& arr) {
    
    int n = arr.size();
    vector<int> can(n,1);
    
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[i-1])
            can[i] = 1+can[i-1];
    
    
    for(int i = n-2; i >= 0; i--)
        if(arr[i] > arr[i+1] && can[i] <= can[i+1])
            can[i] = 1+can[i+1];
    
    
    return accumulate(can.begin(),can.end(),0);
}
};