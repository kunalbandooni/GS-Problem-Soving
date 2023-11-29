// https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        if(n == 1 || n == 0)
            return 0;
        
        vector<bool> prime(n, true);
        prime[1] = prime[0] = false;

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                int j = 2*i;
                while(j < n) {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return count;
    }
};
