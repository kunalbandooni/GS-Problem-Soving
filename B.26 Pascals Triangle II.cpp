// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;

        for(int i = 1; i < row.size(); i++)
            row[i] = row[i-1] * (row.size() - i) / i;

        return row;
    }
};
