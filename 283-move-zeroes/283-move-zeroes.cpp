class Solution {
public:
      
    void moveZeroes(vector<int>& nums) {
        
        int zeroInd = 0, ind = 0, len = nums.size();
        
        for(;ind < len; ind++){
            while(nums[zeroInd] != 0 && zeroInd < len - 1){
                zeroInd++;
            }
            if(nums[ind] != 0 && ind > zeroInd){
                swap(nums[ind], nums[zeroInd]);
            }
        }
        
    }
};