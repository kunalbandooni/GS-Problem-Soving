// https://leetcode.com/problems/house-robber

class Solution {
    int sum(int i, vector<int> nums, vector<int> &dp) {
        if(i < 0)   return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + sum(i-2, nums, dp);
        int notPick = sum(i-1, nums, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return sum(n-1, nums, dp);
    }
};
