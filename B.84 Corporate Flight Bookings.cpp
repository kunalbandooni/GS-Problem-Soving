// https://leetcode.com/problems/corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        // for(vector<int> it: bookings) {
        //     for(int i = it[0]; i <= it[1]; i++)
        //         res[i-1] += it[2];
        // }

        for(vector<int> it: bookings) {
            res[it[0]-1] += it[2];
            if(it[1] < n)
                res[it[1]] += -it[2];
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += res[i];
            res[i] = sum;
        }

        return res;
    }
};
