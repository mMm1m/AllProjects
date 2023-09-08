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

    public  static void unite(int a, int b, int[] link, int[] size)
    {
        if(same(a,b, link)) return;
        a = find(a,link);
        b = find(b,link);
        if(size[a] > size[b])
        {
            size[a] += size[b];
            link[b] = a;
        }
        else {
            size[b] += size[a];
            link[a] = b;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String string = sc.nextLine();
        Scanner scanner = new Scanner(string);
        int n = scanner.nextInt(), m = scanner.nextInt();
        scanner.close();
        int[] link = new int[n+1];
        int[] size = new int[n+1];
        int[] exp = new int[n+1];
        for(int i = 1; i <= n; ++i) {link[i] = i; size[i] = 1; exp[i] = 0;}
        while (sc.hasNextLine())
        {
            String str = sc.nextLine();
            Scanner inner = new Scanner(str);
            String string_ = inner.next();
            if(string_.equals("W"));
            if(string_.equals("add"))
            {
                int target = inner.nextInt(), coins = inner.nextInt();
                for(int i = 1; i <= n; ++i)
                {
                    if(link[find(link[i], link)] == target)  exp[i] += coins;
                }

            }
            else if(string_.equals("join"))
            {
                int left = inner.nextInt(), right = inner.nextInt();
                unite(left, right, link, size);
            }
            else if(string_.equals("get")){
                int idx = sc.nextInt();
                System.out.println(exp[idx]);
            }
            inner.close();
        }
        for(var a : exp)
            System.out.println(a + " ");
        sc.close();
    }
}