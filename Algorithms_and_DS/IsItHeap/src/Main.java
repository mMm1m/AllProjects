import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static int parent_index(int child_index)
    {
        return (child_index-1)/2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), temp;
        List<Integer> list = new LinkedList<>();
        for(int i = 0; i < n; ++i)
        {
            temp = sc.nextInt();
            list.add(temp);
        }
        boolean flag = true;
        for(int i = n-1; i >= 0; --i)
        {
            int curr = i;
            while(parent_index(curr) >= 0 && curr > 0)
            {
                if(list.get(parent_index(curr)) > list.get(curr))  flag = false;
                curr = parent_index(curr);
            }
            if(!flag) break;
        }
        System.out.print((!flag ? "NO" : "YES"));
        sc.close();
    }
}