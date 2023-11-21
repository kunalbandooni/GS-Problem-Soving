//  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int N = nums.length, res = N + 1;
        long[] B = new long[N + 1];
        Deque<Integer> d = new ArrayDeque<>();
        
        for (int i = 0; i < N; i++)
            B[i + 1] = B[i] + nums[i];
        
        for (int i = 0; i < N + 1; i++) {
            while (d.size() > 0 && B[i] - B[d.getFirst()] >=  k)
                res = Math.min(res, i - d.pollFirst());
            while (d.size() > 0 && B[i] <= B[d.getLast()])
                d.pollLast();
            d.addLast(i);
        }

        return res <= N ? res : -1;
    }
}
