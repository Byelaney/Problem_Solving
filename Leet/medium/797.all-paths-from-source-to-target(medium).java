Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.

import java.util.List;
import java.util.ArrayList;

class Solution {
    public void dfs(int[][] graph, int node, List<Integer> path, List<List<Integer>> paths) {
        int[] gopath = graph[node];
        path.add(node);
        for (int i = 0; i < gopath.length; ++i) {
            if (gopath[i] == graph.length - 1) {
                List<Integer> tempS = new ArrayList<>(path);
                tempS.add(gopath[i]);
                paths.add(tempS);
            }
            else dfs(graph, gopath[i], new ArrayList(path), paths);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> paths = new ArrayList<>();
        dfs(graph, 0, new ArrayList<Integer>(), paths);
        return paths;
    }
}
