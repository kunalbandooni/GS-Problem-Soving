// https://leetcode.com/problems/trapping-rain-water

class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int rp = height.length - 1, lp = 0;
        int minL = 0, minR = 0;

        while (lp != rp) {
            if (height[lp] < height[rp]) {
                minL = Math.max(minL, height[lp]);
                ans += minL - height[lp++];
                lp++;
            } else {
                minR = Math.max(minR, height[rp]);
                ans += minR - height[rp--];
                rp--;
            }
        }

        return ans;
    }
}
