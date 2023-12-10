// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for(char ch: s)
            mp[ch]++;
        for(char ch: t)
            mp[ch]--;
        for(auto i: mp) 
            if(i.second != 0)
                return false;
        return true;
    }
};
