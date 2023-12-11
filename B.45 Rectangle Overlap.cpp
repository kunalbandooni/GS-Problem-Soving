// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // lx2 <= rx1 || ly1 >= ry2 || lx1 >= rx2 || ly2 >= ry1
        if(rec1[2] <= rec2[0] || rec1[1] >= rec2[3] 
            || rec1[0] >= rec2[2] || rec1[3] <= rec2[1])
            return false;
        return true;
    }
};
