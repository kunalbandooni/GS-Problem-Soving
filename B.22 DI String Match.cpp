// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.length();
        int n = 0;
        vector<int> res(size+1);

        for(int i=0; i<size; i++) {
            if(s[i] == 'I')
                res[i] = n++;
        }

        res[size] = n++;

        for(int i=size;i>=0;i--) {
            if(s[i] == 'D')
                res[i] = n++;
        }

        return res;
    }
};
