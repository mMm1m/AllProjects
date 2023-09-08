import java.util.LinkedList;
import java.util.Scanner;

class Pair
{
    private int first;
    private int second;
    Pair(int f, int s)
    {
        this.first = f;
        this.second = s;
    }
    public int getFirst()
    {
        return first;
    }
    public int getSecond()
    {
        return second;
    }
}

public class Main
{

    public static int TaskA(int a, int b, int c)
    {
        int ans = (Math.max(a,b)-Math.min(a,b));
        return ans/(2*c) + (ans%(2*c) == 0 ? 0 : 1);
    }


    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        /*for(int i = 0; i < n; ++i)
        {
            int a = sc.nextInt();int b = sc.nextInt();int c = sc.nextInt();
            System.out.println(TaskA(a,b,c));
        }*/
        int t = sc.nextInt();
        for(int i = 0;  i < t; ++i)
        {
            int n = sc.nextInt();
            LinkedList<Pair> list = new LinkedList<>();
            for(int h = 0; h < n; ++h)
            {
                int d = sc.nextInt(); int s = sc.nextInt();
                list.add(new Pair(d,s));
                int left = 0; int right  = 1000000000;
                while(left <= right)
                {
                    int mid = left + (right-left)/2;
                    for(int j =  0; j < n; ++j)
                    {
                        if((list.get(j).getFirst()-1)+list.get(j).getSecond()
                                < 2*mid-((list.get(j).getFirst()-1)+list.get(j).getSecond()))
                        {
                            left = mid;
                        }
                        else {
                            right = mid-1;
                        }
                    }
                }
                System.out.println(left);
        }
        }
    }
}