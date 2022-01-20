class Solution {
public:
    
    int r(int n){
        n++;
        return ((n-1)*(n-2))/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dumb;
        int t=1;
        int diff=-1000000;
        int n=nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]!=diff){
                cout<<i<<"\n";
                diff=nums[i]-nums[i-1];
                dumb.push_back(t);
                t=1;
            }
            else{
                t++;
            }
        }
        dumb.push_back(t);
        int ans=0;
        for(auto x:dumb){
            cout<<x<<" ";
            ans+=r(x);
        }
        return ans;
    }
};