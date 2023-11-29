// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, n=nums.size()-1, end=n, i=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[n])
                i=max(i,mid);
            
            if(nums[mid] > nums[n])start=mid+1;
            else end=mid-1; 
        }
        return nums[i+1];
    }
};
