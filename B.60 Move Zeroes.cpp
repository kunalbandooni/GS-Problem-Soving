// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int left = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] == 0)
                continue;
            nums[left++] = nums[i];
        }
        for (int i = left; i < length; i++)
            nums[i] = 0;
    }
};
