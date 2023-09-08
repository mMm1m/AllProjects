import com.sun.source.tree.Tree;

import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static java.util.stream.Collectors.*;

class Fraction_ implements Comparable<Fraction_>
{
    private int numerator;
    private int denomenator;
    Fraction_(int f, int s)
    {
        this.numerator = f;
        this.denomenator = s;
    }
    public int getNumerator() {return numerator;}
    public int getDenomenator() {return denomenator;}
    public int compareTo(Fraction_ f1)
    {
        return -Integer.compare(f1.getNumerator()*this.getDenomenator(),f1.getDenomenator()*this.getNumerator());
    }
}

class TimeMap {
    private List<Stamp<String,Integer>> list = new LinkedList<>();
    private Map<String, List<Stamp<String,Integer>>> map;

    public TimeMap() {
        map =  new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        if(map.get(key).equals(Collections.EMPTY_LIST))
        {
            
        }
        int[][] matrix = new int[3][4];
        int[] row = matrix[matrix.length-1];
        map.get(key).add(new Stamp<>(value,timestamp));
    }

    public String get(String key, int timestamp) {
        return map.get(key).get(0).value;
    }
}

class Stamp<T,V>
{
    T value;
    V timestamp;
    Stamp(T v, V t)
    {
        this.value = v;
        this.timestamp = t;
    }
}
public class Main {
    /*public static int func(int[] nums) {return 0;}
    public static void main(String[]args)
    {
        int[][] grid = new int[3][3]; int ans=  0; int n = 5;
        LinkedList<Integer> list = new LinkedList<>(;

        for(int i = 0;  i<2; ++i)
        {
            ans += func(grid[i]);
        }
        int[] nums = new int[]{4,5,2,1};
        int[] queries = new int[]{3,10,21};
        int[] ans = Sol.answerQueries(nums, queries);
        for (int a : ans) {
            System.out.println(a + " ");
        }
    }*/
    public static void main(String[] args) throws IOException {
        FileReader fr = new FileReader("/home/max/max.txt" );
        FileWriter fw = new FileWriter( "/home/max/max.txt" );
        int i = 1;
        Scanner scan = new Scanner(fr);
        List<String> list = new LinkedList<>();
        while(scan.hasNextInt())
        {
            StringBuilder stringBuilder = new StringBuilder();
            String next_string = scan.nextLine();
            Scanner inner = new Scanner(next_string);
            double a = inner.nextDouble();
            stringBuilder.append(i++);
            stringBuilder.append(" & ");

            stringBuilder.append(a);
            stringBuilder.append(" & ");

            double b = inner.nextDouble();
            stringBuilder.append(b);
            stringBuilder.append(" & ");

            double c = inner.nextDouble();
            stringBuilder.append(c);
            stringBuilder.append(" & ");

            list.add(stringBuilder.toString());
        }
        for(int k = 0; k < 2; ++k)
        {
            System.out.println(list.get(k));
        }
        //for(int k = 0; k < list.size(); ++k)
        //{
         //   fw.write(list.get(k)+'\n');
        //}
        fw.close();
        fr.close();
    }
}
