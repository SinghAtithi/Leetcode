class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int a=0,b=0;
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==maxi){
                a=i;
                break;
            }
            if(i>0 && arr[i]<=arr[i-1])return false;
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==maxi){
                b=i;
                break;
            }
            if(i!=n-1 && arr[i]<=arr[i+1])return false;
        }
        return (a==b && a!=0 && b!=n-1);
    }
};