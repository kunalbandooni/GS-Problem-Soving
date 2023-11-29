// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int> mp;
        mp['U'] = 1;
        mp['D'] = -1;
        mp['R'] = 1;
        mp['L'] = -1;

        int horizontalDistance = 0, verticalDistance = 0;
        for(char ch: moves) {
            if(ch == 'R' || ch == 'L')
                horizontalDistance += mp[ch];
            else
                verticalDistance += mp[ch];
        }

        if(verticalDistance == 0 && horizontalDistance == 0)
            return true;
        return false;
    }
};
