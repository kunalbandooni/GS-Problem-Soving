// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = 0, lsum = 0;
        for(int n: nums)
            rsum += n;
        
        for(int i = 0; i < nums.size(); i++) {
            rsum -= nums[i];
            if(rsum == lsum)
                return i;
            lsum += nums[i];
        }

        return -1;
    }
};
