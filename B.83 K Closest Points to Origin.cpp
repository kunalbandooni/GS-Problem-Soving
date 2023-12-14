// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> v; 
        for(int i = 0; i < points.size(); i++){
            int s = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({s, {points[i][0], points[i][1]}});
        }

        sort(v.begin(), v.end());

        int j = 0;
        vector<vector<int>> res;        
        while(k > 0) {
            res.push_back(v[j].second);
            j++;
            k--;
        }

        return res;
    }
};
