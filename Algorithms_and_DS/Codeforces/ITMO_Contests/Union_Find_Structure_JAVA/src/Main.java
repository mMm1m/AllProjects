import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static int find(int x, int[] link)
    {
        while(x != link[x]) x = link[x];
        return x;
    }

    public static boolean same(int a, int b, int [ ] link)
    {
        return find(a, link) == find(b, link);
    }

    public  static void unite(int a, int b, int[] link, int[] size, int[] min, int[] max)
    {
        if(same(a,b, link)) return;
        a = find(a,link);
        b = find(b,link);
        if(size[a] > size[b])
        {
            size[a] += size[b];
            link[b] = a;
            min[a] = Math.min(min[a], min[b]);
            max[a] = Math.max(max[a], max[b]);
        }
        else {
            size[b] += size[a];
            link[a] = b;
            min[b] = Math.min(min[a], min[b]);
            max[b] = Math.max(max[a], max[b]);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int[] link = new int[n+1];
        int[] size = new int[n+1];
        int[] min = new int[n+1];
        int[] max = new int[n+1];
        for(int i = 1; i <= n; ++i) {link[i] = i; size[i] = 1; min[i] = i; max[i] = i;}
        while (sc.hasNextLine())
        {
            String str = sc.nextLine();
            Scanner inner = new Scanner(str);
            String string = inner.next();
            if(string.equals("union"))
            {
                int x = inner.nextInt(), y = inner.nextInt();
                unite(x,y, link, size, min, max);
            }
            else
            {
                int x = inner.nextInt();
                System.out.println(min[find(x,link)] + " " + max[find(x,link)] + " " + size[find(x, link)]);
            }
            inner.close();
        }
        sc.close();
    }
}