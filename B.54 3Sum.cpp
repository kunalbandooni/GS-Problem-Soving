// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int front = 0, back = nums.size() - 1, sum;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break; 
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            front = i + 1;
            back = nums.size() - 1;
            sum = 0;
            while(front < back){
                sum = nums[i] + nums[front] + nums[back];
                if(sum > 0)
                    back--;
                else if(sum < 0)
                    front++;
                else {
                    result.push_back({nums[i], nums[front], nums[back]});
                    int front_last = nums[front], back_last = nums[back];
                    while(front < back && nums[front] == front_last) 
                        front++;
                    while(front < back && nums[back] == back_last) 
                        back--;
                }
            }
        }
        return result;

    }
};
