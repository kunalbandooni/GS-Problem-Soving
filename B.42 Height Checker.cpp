// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v;
        for(int n: heights)
            v.push_back(n);
        
        sort(v.begin(), v.end());

        int i = 0, count = 0;
        for(int n: v) {
            if(n != heights[i++])
                count++;
        }

        return count;
    }
};
