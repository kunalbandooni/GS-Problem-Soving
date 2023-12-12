// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		    vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0'])
                for(auto s: result)
                    tmp.push_back(s + candidate);
            result.swap(tmp);
        }
        return result;
    }
};
