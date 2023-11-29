// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int preSum = 0, cnt = 0;
        
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            preSum += nums[i];
            int remove = preSum - k;
        
            cnt += mp[remove];
        
            mp[preSum]++;
        }

        return cnt;
    }
};
