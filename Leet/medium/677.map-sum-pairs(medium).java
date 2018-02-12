Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5


class MapSum {

    HashMap<String, Integer> map;
    public MapSum() {
        map = new HashMap<>();
    }
    public void insert(String key, int val) {
        map.put(key, val);
    }
    public int sum(String prefix) {
        int ans = 0;
        for (String key: map.keySet()) {
            if (key.startsWith(prefix)) {
                ans += map.get(key);
            }
        }
        return ans;
    }
}

class MapSum {

    // Alphabet size (# of symbols)
    static final int ALPHABET_SIZE = 26;
    static TrieNode root;
    Map<String, Integer> dict;

    static class TrieNode {
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        int score = 0;

        TrieNode(int score) {
            for (int i = 0; i < children.length; ++i) children[i] = null;
            this.score = score;
        }
    }

    public MapSum() {
        root = new TrieNode(0);
        dict = new HashMap<>();
    }

    public void insert(String key, int val) {
        int delta = val - dict.getOrDefault(key, 0);
        dict.put(key, val);
        TrieNode pCrawl = root;
        for (int i = 0; i < key.length(); ++i) {
            int index = key.charAt(i) - 'a';
            if (pCrawl.children[index] == null)
                pCrawl.children[index] = new TrieNode(val);
            else
                pCrawl.children[index].score += delta;
            pCrawl = pCrawl.children[index];
        }
    }

    public int sum(String prefix) {
        TrieNode pCrawl = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int index = prefix.charAt(i) - 'a';
            pCrawl = pCrawl.children[index];
            if (pCrawl == null) return 0;
        }
        return pCrawl.score;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
