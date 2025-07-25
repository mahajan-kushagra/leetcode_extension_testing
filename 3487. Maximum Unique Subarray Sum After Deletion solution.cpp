class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.back() <= 0)
            return nums.back();
        int sum = 0, smallestVal = nums.back() + 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < smallestVal) {
                if (nums[i] <= 0)
                    break;
                sum += nums[i];
                smallestVal = nums[i];
            }
        }
        return sum;
    }
};