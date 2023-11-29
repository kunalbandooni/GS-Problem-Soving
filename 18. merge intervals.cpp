//  https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        for(auto data: intervals) {
            if(res.empty() || res.back()[1] < data[0])
                res.push_back(data);
            else
                res.back()[1] = max(res.back()[1], data[1]);
        }
        
        return res;
    }
};
