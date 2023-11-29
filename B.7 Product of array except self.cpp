// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> lp(n);
        vector<int> rp(n);

        lp[0] = 1;
        for(int i=1;i<n;i++)
            lp[i] = lp[i-1] * nums[i-1];

        rp[n-1] = 1;
        for(int i=n-2;i>=0;i--)
            rp[i] = rp[i+1] * nums[i+1];

        for(int i=0;i<n;i++)
            res[i] = lp[i] * rp[i];

        return res;
    }
};
