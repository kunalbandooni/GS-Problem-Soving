// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
    /*int f(int i, int buy, vector<int> p){
        if(i==p.size())  return 0;
        
        int profit = 0;
        if(buy)
            profit = max( -p[i] + f(i+1, 0, p),
                        0 + f(i+1, 1, p));
        else
            profit = max( p[i] + f(i+1, 1, p),
                        0 + f(i+1, 0, p));
        
        return profit;
    }*/
public:
    int maxProfit(vector<int>& prices) {
        //return f(0,1,prices);
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int i = n-1;i >= 0; i--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy)
                    profit = max( -prices[i] + dp[i+1][0],
                        0 + dp[i+1][1]);
                else
                    profit = max( prices[i] + dp[i+1][1],
                        0 + dp[i+1][0]);
                dp[i][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};
