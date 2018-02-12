Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.

class MagicDictionary {

    // Alphabet size (# of symbols)
    static final int ALPHABET_SIZE = 26;

    static class TrieNode {
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];

        // isEndOfWord is true if the node represents
        // end of a word
        boolean isEndOfWord;

        TrieNode() {
            for (int i = 0; i < children.length; ++i) children[i] = null;
            isEndOfWord = false;
        }
    }

    static TrieNode root;

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode pCrawl = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word.charAt(i) - 'a';
            if (pCrawl.children[index] == null)
                pCrawl.children[index] = new TrieNode();;
            pCrawl = pCrawl.children[index];
        }
        pCrawl.isEndOfWord = true;
    }

    /** Initialize your data structure here. */
    public MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String word : dict) insert(word);
    }

    public boolean find(TrieNode node, String word) {
        TrieNode pCrawl = node;
        for (int i = 0; i < word.length(); ++i) {
            int index = word.charAt(i) - 'a';
            if (pCrawl.children[index] == null) return false;
            pCrawl = pCrawl.children[index];
        }
        return (pCrawl != null && pCrawl.isEndOfWord);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        TrieNode pCrawl = root;
        int k = 0;
        while (pCrawl != null) {
            if (k == word.length()) return false;
            int index = word.charAt(k) - 'a';
            for (int i = 0; i < 26; ++i) {
                if (i == index) continue;;
                if (pCrawl.children[i] != null && find(pCrawl.children[i], word.substring(k+1, word.length()))) return true;
            }
            k++;
            pCrawl = pCrawl.children[index];
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */

 class MagicDictionary {

    /** Initialize your data structure here. */
    Map<Integer, Set<String>> ump;
    public MagicDictionary() {
        ump = new HashMap<>();
    }

    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String word : dict) {
            if (ump.containsKey(word.length())) ump.get(word.length()).add(word);
            else {
                Set<String> s = new HashSet<>();
                s.add(word);
                ump.put(word.length(), s);
            }
        }
    }

    boolean afterModify(String word, String cand) {
        if (word.equals(cand)) return false;
        int diffId = 0;
        for (; diffId < word.length(); ++diffId) {
            if (word.charAt(diffId) != cand.charAt(diffId)) break;
        }
        boolean left = (word.substring(0, diffId).equals(cand.substring(0, diffId)));
        boolean right = (word.substring(diffId+1, word.length()).equals(cand.substring(diffId+1, cand.length())));
        return (left && right);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        if (!ump.containsKey(word.length())) return false;
        Set<String> words = ump.get(word.length());
        for (String cand : words) {
            if (afterModify(word, cand)) return true;
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
