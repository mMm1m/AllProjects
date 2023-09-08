import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;


public class WordStatInput {
    static void check(Map<String, Integer> map, StringBuilder pattern)
    {
        if(!pattern.isEmpty() && pattern != null)
        {
            String ans = pattern.toString().toLowerCase();
            map.putIfAbsent(ans,0);
            map.put(ans, map.get(ans)+1);
        }
    }

    public static Map<String, Integer> solution()
    {
        Map<String, Integer> map = new LinkedHashMap<>();
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())
        {
            String str = sc.nextLine();
            if(str.equals("w")) break;
            StringBuilder pattern = new StringBuilder();
            for(int i = 0; i < str.length(); ++i)
            {
                char c = str.charAt(i);
                if(c == ' ') {
                    check(map, pattern);
                    pattern = new StringBuilder();
                }
                else  pattern.append(c);
            }
            check(map, pattern);
        }
        sc.close();
        return map;
    }
    public static void main(String[] args)
    {
        var ans = solution();
        ans.forEach((k,v) -> System.out.println(k + " " + v));
    }
}