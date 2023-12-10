// https://leetcode.com/problems/permutations

class Solution {
    void getPerms(int idx, vector<int> &nums, set<vector<int>> &ans) {
        if(idx >= nums.size()) return;
        ans.insert(nums);
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPerms(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        set<vector<int>> ans;
        getPerms (0,nums,ans);
        for (auto v:ans)
            vec.push_back(v);
        return vec;
    }
};
