class Solution {
public:
    // solution is the same as '698. Partition to K Equal Sum Subsets'
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        int sum = 0;
        for (const int& matchstick: matchsticks)
        {
            sum += matchstick;
        }

        if (sum % 4 != 0)
        {
            return false;
        }

        int targetSum = sum / 4;

        vector<bool> usedValues(n, false);

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return backtrack(targetSum, matchsticks, usedValues, 0, 4, 0);
    }

private:
    bool backtrack(int targetSum, vector<int>& nums, vector<bool>& usedValues, int index, int remainingBuckets, int currentBucketSum)
    {
        if (remainingBuckets == 0)
        {
            return true;
        }

        if (currentBucketSum == targetSum)
        {
            return backtrack(targetSum, nums, usedValues, 0, remainingBuckets-1, 0);
        }

        for (int j = index; j < nums.size(); j++)
        {
            if (usedValues[j] || currentBucketSum + nums[j] > targetSum || (j > 0 && nums[j] == nums[j-1] && !usedValues[j-1]))
            {
                continue;
            }

            usedValues[j] = true;

            if (backtrack(targetSum, nums, usedValues, j+1, remainingBuckets, currentBucketSum + nums[j]))
            {
                return true;
            }

            usedValues[j] = false;
        }

        return false;
    }
};