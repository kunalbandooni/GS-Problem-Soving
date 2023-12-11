// https://leetcode.com/problems/subsets

class Solution {
    void permute(int ind, vector<int> a, vector<int> nums, vector<vector<int>> &res) {
        res.push_back(a);
        for(int i = ind; i < nums.size(); i++) {
            a.push_back(nums[i]);
            permute(i+1, a, nums, res);
            a.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> a;

        permute(0, a, nums, res);

        return res;
    }
};
