// https://leetcode.com/problems/palindromic-substrings

class Solution {
    int isPalindrome(string s,int i,int j){
        while(i <= j){
            if(s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                ans += isPalindrome(s, i, j);
        return ans;
    }
};
