import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedReader;
import java.util.*;

import static java.util.Collections.reverse;

public class Main {
    public static boolean A() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = reader.readLine().split(" ");
        for(int i = 0; i < arr.length-1; ++i)
            if(Integer.parseInt(arr[i]) >= Integer.parseInt(arr[i+1])) return false;
        return true;
    }

    public static boolean isConstant(List<Integer> list)
    {
        int curr = list.get(0);
        for(int i = 1; i < list.size(); ++i)
            if(list.get(i) != curr) return false;
        return true;
    }
    public static boolean isAscending(List<Integer> list)
    {
        int curr = list.get(0);
        for(int i = 1; i < list.size(); ++i)
        {
            if(list.get(i) <= curr) return false;
            curr = list.get(i);
        }
        return true;
    }

    public static boolean isDescending(List<Integer> list)
    {
        int curr = list.get(0);
        for(int i = 1; i < list.size(); ++i)
        {
            if(list.get(i) >= curr) return false;
            curr = list.get(i);
        }
        return true;
    }
    public static boolean isWeaklyAscending(List<Integer> list)
    {
        int curr = list.get(0);
        for(int i = 1; i < list.size(); ++i)
        {
            if(list.get(i) < curr) return false;
            curr = list.get(i);
        }
        return true;
    }
    public static boolean isWeaklyDescending(List<Integer> list)
    {
        int curr = list.get(0);
        for(int i = 1; i < list.size(); ++i)
        {
            if(list.get(i) > curr) return false;
            curr = list.get(i);
        }
        return true;
    }
    public static void B() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int a;
        List<Integer> list = new ArrayList<>();
        while( (a = Integer.parseInt(reader.readLine())) != -2000000000)
            list.add(a);
        final String CONSTANT = "CONSTANT";
        final String WEAKLY_ASCENDING = "WEAKLY ASCENDING";
        final String DESCENDING = "DESCENDING";
        final String WEAKLY_DESCENDING = "WEAKLY DESCENDING";
        final String RANDOM = "RANDOM";
        final String ASCENDING = "ASCENDING";
        if(isConstant(list)) System.out.println(CONSTANT);
        else if(isAscending(list)) System.out.println(ASCENDING);
        else if(isDescending(list)) System.out.println(DESCENDING);
        else if(isWeaklyAscending(list)) System.out.println(WEAKLY_ASCENDING);
        else if(isWeaklyDescending(list)) System.out.println(WEAKLY_DESCENDING);
        else System.out.println(RANDOM);
    }

    public static int C() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(reader.readLine());
        String[] strings = reader.readLine().split(" ");
        int goal = Integer.parseInt(reader.readLine());
        int min = Integer.MAX_VALUE, curr = -1;
        for(int i = 0; i < size; ++i)
        {
            if(Math.abs(goal-Integer.parseInt(strings[i])) < min)
            {
                curr = Integer.parseInt(strings[i]);
                min = Math.abs(goal-Integer.parseInt(strings[i]));
            }
        }
        return curr;
    }

    public static void D() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] strings = reader.readLine().split(" ");
        int c = 0;
        if(strings.length == 0 || strings.length == 1) System.out.println(0);
        else {
            for(int i = 1; i < strings.length-1; ++i)
            {
                if(Integer.parseInt(strings[i-1]) < Integer.parseInt(strings[i])
                && Integer.parseInt(strings[i+1]) < Integer.parseInt(strings[i])) ++c;
            }
            System.out.println(c);
        }
    }

    public static boolean isPalindrome(String[] arr)
    {
        int left = 0, right = arr.length-1;
        while(left <= right)
        {
            if(Integer.parseInt(arr[left]) != Integer.parseInt(arr[right])) return false;
            ++left;
            --right;
        }
        return true;
    }

    static List<Integer>  prefix_function(List<String> s) {
        int n = s.size();
        List<Integer> p = new ArrayList<>();
        for(int i = 0; i < n; ++i) p.add(0);
        for (int i = 1; i < n; i++) {
            int cur = p.get(i - 1);
            while (Integer.parseInt(s.get(i)) != Integer.parseInt(s.get(cur)) && cur > 0)
                cur = p.get(cur - 1);
            if (Integer.parseInt(s.get(i)) == Integer.parseInt(s.get(cur)))
                p.set(i , cur+1);
        }
        return p;
    }


    public static void F() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Integer.parseInt(reader.readLine());
        String[] strings = reader.readLine().split(" ");
        /*if (isPalindrome(strings)) System.out.println(0);
        else {
            List<String> stringList = new ArrayList<>(Arrays.stream(strings).toList());
            List<Integer> prefix = prefix_function(stringList);
            Collections.reverse(stringList);
            List<Integer> suffix = prefix_function(stringList);
            Collections.reverse(suffix);
            int max = 0;
            for(int i = 0; i < suffix.size(); ++i)
            {
                max = Math.max(suffix.get(i)+prefix.get(i),max );
            }
            System.out.println(prefix.size() - max);*/
        }

    public static void G() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] strings = reader.readLine().split(" ");
        List<Integer> list = new ArrayList<>();
        for(var a : strings) list.add(Integer.parseInt(a));
        Collections.sort(list);
        if(list.get(0)*list.get(1) > list.get(list.size()-1)*list.get(list.size()-2))
        {
            System.out.println(list.get(0) + " " + list.get(1));
        }
        else System.out.println(list.get(list.size()-2)+ " " + list.get(list.size()-1));
    }

    public static int isCorrect(List<Integer> list)
    {
        if(list.size() == 1) return list.get(0);
        int max = -1, max_pos = -1 , ans = -1;
        for(int i = 0; i < list.size(); ++i) {
            if(max < list.get(i))
            {
                max = Math.max(max, list.get(i));
                max_pos = i;
            }
        }
        for(int i = 0; i < list.size()-1; ++i)
        {
            if(list.get(i)%10 == 5 && max >= list.get(i) && max_pos > i && list.get(i+1) < list.get(i))
                ans = Math.max(ans, list.get(i));
        }
        return ans;
    }
    public static void E() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String[] strings = reader.readLine().split(" ");
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < strings.length; ++i) list.add(Integer.parseInt(strings[i]));
        int num = isCorrect(list);
        if(num == -1) System.out.println(0);
        else
        {
            TreeSet<Integer> set = new TreeSet<>();
            for(var a : list) set.add(a);
            int idx = 1;
            for(var a : set)
            {
                if(a == num) {
                    System.out.println(idx);
                    break;
                }
                ++idx;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        G();
    }
}