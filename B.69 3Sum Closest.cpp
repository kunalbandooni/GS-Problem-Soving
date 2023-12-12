// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_closest = INT_MAX, sum = 0;

        for(int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1;
            while(low < high) {                
                int curr_closest = abs(target - 
                                    (nums[i] + nums[low] + nums[high]));

                if(curr_closest < min_closest) {
                    min_closest = curr_closest;
                    sum = (nums[i] + nums[low] + nums[high]);
                }

                if(nums[i] + nums[low] + nums[high] <= target)
                    low++;
                else    high--;
            }
        }
        return sum;
    }
};
