// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i: nums)
            mp[i]++;

        int res = 0;
        for(auto x: mp) {
            if(k == 0) {
                if(x.second > 1)
                    res++;
            }
            else if(mp.find(x.first + k) != mp.end())
                res++;
        }
        return res;
    }
};
