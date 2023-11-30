// https://leetcode.com/problems/pascals-triangle

class Solution {
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;

        for(int i = 1; i < row.size(); i++)
            row[i] = row[i-1] * (row.size() - i) / i;

        return row;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
      
        for(int i = 0; i < numRows; i++)
            res.push_back(getRow(i));

        return res;
    }
};
