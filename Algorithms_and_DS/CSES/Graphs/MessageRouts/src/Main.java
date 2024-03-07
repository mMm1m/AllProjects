import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] variables = scanner.nextLine().split(" ");
        int n = Integer.parseInt(variables[0]) , m = Integer.parseInt(variables[1]);

        int[][] input = new int[m][2];
        for(int i = 0; i < m; ++i)
        {
            String[] strings = scanner.nextLine().split(" ");
            input[i][0] = Integer.parseInt(strings[0]);
            input[i][1] = Integer.parseInt(strings[1]);
        }

        List<List<Integer>> adj = new ArrayList<>(n+1);
        for(int i = 0;  i <= n; ++i) adj.add(new ArrayList<>());
        addEdges(adj , input , n);
        int[] parents = new int[n+1];
        int[] dist = new int[n+1];
        printPath(adj, 1, n, n, parents, dist);
        for(var a : adj)
        {
            for (var b : a) System.out.print(a + "  " + b);
            System.out.println();
        }
        scanner.close();
    }

    public static void addEdges(List<List<Integer>> adj  , int[][] input, int n)
    {
        for(int i = 0; i < n; ++i)
        {
            adj.get(input[i][0]).add(input[i][1]);
            adj.get(input[i][1]).add(input[i][0]);
        }
    }

    public static boolean BFS(List<List<Integer>> adj , int src , int dest , int n , int[] parents, int[] dist)
    {
        boolean[] vis = new boolean[n+1];
        Queue<Integer> queue = new LinkedList<>();

        for(int i = 0; i <= n; ++i)
        {
            vis[i] = false;
            parents[i] = -1;
            dist[i] = Integer.MAX_VALUE;
        }

        vis[src] = true;
        dist[src] = 0;

        queue.add(src);
        while(!queue.isEmpty())
        {
            int tmp = queue.poll();
            for(var a : adj.get(tmp))
            {
                if(vis[a]) continue;
                vis[a] = true;
                dist[a] = dist[tmp]+1;
                parents[a] = tmp;
                queue.add(a);
                if(a == dest) return true;
            }
        }
        for(var a : vis) System.out.print(a + " ");
        System.out.println();
        for(var a : parents) System.out.print(a + " ");
        System.out.println();
        for(var a: dist) System.out.print(a + " ");
        System.out.println();
        return false;
    }

    public static void printPath(List<List<Integer>> adj , int src , int dest , int n , int[] parents, int[] dist)
    {
        if(!BFS(adj , src ,  dest , n ,  parents, dist))
        {
            System.out.println("IMPOSSIBLE");
            return;
        }
        List<Integer> list = new ArrayList<>();
        System.out.println(dist[dest]);
        int parent = n;
        while(parents[parent] != -1)
        {
            list.add(parents[parent]);
            parent = parents[parent];
        }
        for(int i = list.size()-1; i >= 0; --i)
            System.out.print(list.get(i) + " ");
    }

}