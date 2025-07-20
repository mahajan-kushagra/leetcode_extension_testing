class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < target || -1 * totalSum > target ||
            (totalSum - target) % 2)
            return 0;
        int newTarget = (totalSum - target) / 2;
        vector<int> dp(newTarget + 1, 0);
        dp[0]++;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > newTarget)
                continue;
            for (int j = newTarget; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        }
        return dp.back();
    }
};