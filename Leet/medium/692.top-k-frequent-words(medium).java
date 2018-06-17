Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> result = new ArrayList<>();
        Map<String, Integer> dict = new HashMap<>();
        for (String word : words) {
            if (dict.containsKey(word)) dict.put(word, dict.get(word) + 1);
            else dict.put(word, 1);
        }
        class t2 {
            String word;
            int occur;
            public t2(String word, int occur) {
                this.word = word;
                this.occur = occur;
            }
        }
        class MyComparator implements Comparator<t2> {
            @Override
            public int compare(t2 x, t2 y)
            {
                if (x.occur < y.occur) return 1;
                else if (x.occur > y.occur) return -1;
                else {
                    return x.word.compareTo(y.word);
                }
            }
        }
        PriorityQueue<t2> q = new PriorityQueue<>(new MyComparator());
        Iterator it = dict.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            t2 tmp = new t2((String)pair.getKey(), (int)pair.getValue());
            q.add(tmp);
        }
        for (int i = 0; i < k; ++i) result.add(q.poll().word);
        return result;
    }
}
