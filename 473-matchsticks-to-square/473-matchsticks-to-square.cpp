class Solution {
public:
    bool check(int i, vector<int>& ds, vector<int>& arr, int target){
        if(i>=arr.size()){
            for(auto& x:ds) {
                if(x!=target) return false; 
            }
            return true;
        }
        for(int j=0;j<4;j++){
            if(arr[i]+ds[j]<=target){
                ds[j]+=arr[i];
                if(check(i+1,ds,arr,target)) return true;
                ds[j]-=arr[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%4!=0) return false;
        vector<int> ds(4);
        sort(arr.rbegin(),arr.rend()); 
        return check(0,ds,arr,sum/4);
    }
};