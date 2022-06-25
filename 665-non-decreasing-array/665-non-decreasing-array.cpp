class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int modified = 0;
        int maxi = nums[0];
        int len = nums.size();
        
        int pivot = -1;
        
        for(int i = 0; i < len - 1; i++){
            if(nums[i] > nums[i + 1]){
                pivot = i;
                break;
            }
        }
        
        if(pivot == -1)
            return true;
        
        int pivElement = nums[pivot];
        
        nums[pivot] = (pivot == 0) ? INT_MIN : nums[pivot - 1];
        
        bool fixed = true;
        
        for(int i = 0; i < len - 1; i++){
            if(nums[i] > nums[i + 1]){
                fixed = false;
                break;
            }
        }
        
        if(fixed)
            return true;
        
        fixed = true;
        nums[pivot] = pivElement;
        nums[pivot + 1] = pivElement;
        
        for(int i = 0; i < len - 1; i++){
            if(nums[i] > nums[i + 1]){
                fixed = false;
                break;
            }
        }
        
        if(fixed)
            return true;
        
        return false;
        
    }
};