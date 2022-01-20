class Solution {
public:
    bool check(long long k, vector<int>&v, int h){
        long long ans=0;
        for(auto &x:v){
            ans+=(x+k-1)/k;
        }
        return ans<=h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1,high=100000000000000;
        while(low<high){
            long long mid=(low+high)/2;
            cout<<mid<<"\n";
            if(check(mid,piles,h)){
                high=mid;
            }    
            else{
                low=mid+1;
            }
        }
        return high;
    }
};