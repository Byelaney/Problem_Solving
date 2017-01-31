package graph;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DepthFirstPaths {
    private boolean[] marked;    // marked[v] = is there an s-v path?
    private int[] edgeTo;        // edgeTo[v] = last edge on s-v path
    private final int s;         // source vertex
    private int diff_c = 0;

    /**
     * Computes a path between {@code s} and every other vertex in graph {@code G}.
     * @param G the graph
     * @param s the source vertex
     * @throws IllegalArgumentException unless {@code 0 <= s < V}
     */
    public DepthFirstPaths(Graph G, int s) {
        this.s = s;
        edgeTo = new int[G.V()];
        marked = new boolean[G.V()];
        validateVertex(s);
    }

    // depth first search from v
    private void dfs(Graph G, int v) {
        marked[v] = true;
        diff_c++;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }

    /**
     * Is there a path between the source vertex {@code s} and vertex {@code v}?
     * @param v the vertex
     * @return {@code true} if there is a path, {@code false} otherwise
     * @throws IllegalArgumentException unless {@code 0 <= v < V}
     */
    public boolean hasPathTo(int v) {
        validateVertex(v);
        return marked[v];
    }

    /**
     * Returns a path between the source vertex {@code s} and vertex {@code v}, or
     * {@code null} if no such path.
     * @param  v the vertex
     * @return the sequence of vertices on a path between the source vertex
     *         {@code s} and vertex {@code v}, as an Iterable
     * @throws IllegalArgumentException unless {@code 0 <= v < V}
     */
    public Iterable<Integer> pathTo(int v) {
        validateVertex(v);
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }

    // throw an IllegalArgumentException unless {@code 0 <= v < V}
    private void validateVertex(int v) {
        int V = marked.length;
        if (v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }

    public List<Integer> components(Graph g) {
        List<Integer> re = new ArrayList<Integer>();
        for (int i = 0;i<g.V();++i) {
            if (!marked[i]) {
                dfs(g, i);
                re.add(diff_c);
                diff_c = 0;
            }
        }
        return re;
    }

    public static void main(String[] args) {
        InputStream in = System.in;
        Graph G = new Graph(in);
        DepthFirstPaths dfs = new DepthFirstPaths(G, 0);
        List<Integer> re = dfs.components(G);
        long result = 0;
        long sum = re.get(re.size()-1);
        /**
         * tricky part
         * [a,b,c,d]
         * a*b + a*c + a*d + b*c + ... c*d O(n^2)
         *
         * a*(b+c+d) + b(c+d) + c*(d),  O(n)
         */
        for (int i = re.size()-2;i>=0;i--) {
            result += re.get(i) * sum;
            sum += re.get(i);
        }
        System.out.println(result);
    }
}