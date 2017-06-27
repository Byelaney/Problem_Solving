Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> queue;
    unordered_map<char, int> task_freq;
    for (auto task : tasks) task_freq[task]++;
    for (unordered_map<char, int>::iterator it = task_freq.begin(); it != task_freq.end(); ++it)
        queue.push(it->second);

    int cycle = n + 1, executed = 0, intervals = 0;
    vector<int> executed_tasks;
    while (!queue.empty()) {
        executed_tasks.clear();
        executed = 0;
        for (int i = 0; i < cycle; ++i) {
            if (!queue.empty()) {
                int current_exec = queue.top();
                queue.pop();
                if (--current_exec > 0)
                    executed_tasks.push_back(current_exec);
                executed++;
            }
            else break;
        }
        intervals += (queue.empty() && executed_tasks.empty())? executed : cycle;
        for (auto left_freq : executed_tasks) queue.push(left_freq);
    }
    return intervals;
}
};
