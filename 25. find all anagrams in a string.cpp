// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] cnt = new int[128];
        for (char c : p.toCharArray()) cnt[c]++;
        
        List<Integer> ans = new ArrayList<>();
        for (int r = 0, l = 0; r < s.length(); ++r) {
            char c = s.charAt(r);
            cnt[c]--;
            while (cnt[c] < 0) { 
                cnt[s.charAt(l)]++;  
                l++;
            }

            if (r - l + 1 == p.length()) { 
                ans.add(l); 
            }
        }
        return ans;
    }
}
