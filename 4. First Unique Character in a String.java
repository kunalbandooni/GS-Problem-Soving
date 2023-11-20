//  https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
    public int firstUniqChar(String s) {
        HashSet<Character> set = new HashSet<>();
        HashSet<Character> alphabet = new HashSet<>();

        for (char ch: s.toCharArray()) {
            alphabet.add(ch);
            if (set.contains(ch)) 
                alphabet.remove(ch);
            set.add(ch);
        }

        if (alphabet.isEmpty())
            return -1;
        
        int i = 0;
        for (char ch: s.toCharArray()) {
            if (alphabet.contains(ch))
                return i;
            i++;
        }

        return -1;
    }
}
