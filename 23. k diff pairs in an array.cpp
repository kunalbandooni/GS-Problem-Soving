// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
    int mapMethod(vector<int> nums, int k) {
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
public:
    int findPairs(vector<int>& nums, int k) {
        return mapMethod(nums, k);
        // int n = nums.size();
        // int i = 0, j = 1;
        // int res = 0;
        // sort(nums.begin(), nums.end());

        // while (i < n && j < n) {
        //     if (nums[j] - nums[i] == k) {
        //         res++;
        //         i++;
        //         j++;
        //         while(j < n && nums[j] == nums[j-1])
        //             j++;
        //     } else if (nums[j] - nums[i] > k) {
        //         i++;
        //         if (j - i == 0)
        //             j++;
        //     } else {
        //         j++;
        //     }
        // }
        // return res;
    }
};
