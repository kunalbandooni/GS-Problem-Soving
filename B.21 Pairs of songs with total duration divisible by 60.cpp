// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        
        int arr[61]={0};
        
        for(int i=0;i<time.size();i++){
            int a=time[i]%60;
            if(a==0)
                ans+=arr[0];
            else
                ans+=arr[60-a];
            arr[a]++;
        }
        
        return ans;
    }
};
