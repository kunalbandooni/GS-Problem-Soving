// https://leetcode.com/problems/combination-sum

class Solution {
    void f(int i, int target, vector<int> cd, vector<vector<int>> &res, vector<int> &tmp) {
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        if(target < 0)  return;

        for(int ind = i; ind < cd.size(); ind++) {
            tmp.push_back(cd[ind]);
            f(ind, target - cd[ind], cd, res, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> res;
        f(0, target, candidates, res, tmp);    
        return res;
    }
};
