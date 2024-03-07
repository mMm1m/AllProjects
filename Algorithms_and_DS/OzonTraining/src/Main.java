import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


//1 task
/*BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int test = Integer.parseInt(reader.readLine());
        int[] ships = new int[5];
        int [] arr = new int[10];
        for(int i = 0; i < test; ++i) {
            Arrays.fill(ships, 0);
            String[] parts = reader.readLine().split(" ");
            for(int j = 0; j < 10; ++j)
            {
                arr[j] = Integer.parseInt(parts[j]);
                ships[arr[j]]++;
            }
            boolean b = true;
           for(int k = 1; k < 5; ++k)
           {
               if(k + ships[k] != 5) {
                   System.out.println("NO");
                   b = false;
                   break;
               }
           }
            if(b) System.out.println("YES");
        }
        reader.close();
        writer.close();*/

// 2 task
/*class Year
{
    int day;
    int month;
    int year;
    public Year(int d, int m, int y)
    {
        this.day = d;
        this.month = m;
        this.year = y;
    }
    public int getYear() {
        return year;
    }
    public int getMonth()
    {
        return month;
    }

    public int getDay() {
        return day;
    }
}

BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        int [] one = new int[]{1,3,5,7,8,10,12};
        int[] zero = new int[]{4,6,9,11};
        for(int i = 0; i < tests; ++i)
        {
            String[] parts = reader.readLine().split(" ");
            Year year = new Year(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
            boolean leap = false;
            if((year.getYear() % 4 ==0 && year.getYear() % 100 != 0) || year.getYear() % 400 == 0) leap = true;

            if(leap)
            {
                if(year.getMonth() == 2 && year.getDay() > 29) System.out.println("NO");
                else if(year.getMonth() == 2 && year.getDay() <= 29) System.out.println("YES");
            }
            else {
                if (year.getMonth() == 2 && year.getDay() > 28) System.out.println("NO");
                else if (year.getMonth() == 2 && year.getDay() <= 28) System.out.println("YES");
            }

            for(var a : zero)
            {
                if(year.getMonth() == a && year.getDay() > 30) System.out.println("NO");
                else if(year.getMonth() == a && year.getDay() <= 30) System.out.println("YES");
            }

            for(var a : one)
            {
                if(year.getMonth() == a && year.getDay() > 31) System.out.println("NO");
                else if(year.getMonth() == a && year.getDay() <= 31) System.out.println("YES");
            }
        }

        reader.close();
        writer.close();
    }
*/

//4 task
/*BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        for(int i = 0; i < tests; ++i)
        {
            int temp = Integer.parseInt(reader.readLine());
            int left = 15, right = 30;
            for(int j = 0; j < temp; ++j)
            {
                String[] parts = reader.readLine().split(" ");
                if(parts[0].equals(">=")) left = Math.max(left , Integer.parseInt(parts[1]));
                if(parts[0].equals("<=")) right = Math.min(right, Integer.parseInt(parts[1]));
                if(left > right)
                {
                    System.out.println(-1);
                }
                else System.out.println(left);
            }
            System.out.println();
        }
        reader.close();
        writer.close();*/

//3 task
/*public static boolean check(String string)
    {
        for(int i =0 ; i < 15; ++i)
            for(int j = 0; j < 15; ++j)
                if(4*i + 5*j == string.length()) return true;
        return false;
    }

    public static boolean checkFour(String string)
    {
        if(Character.isDigit(string.charAt(1)) && Character.isLetter(string.charAt(0))  && Character.isLetter(string.charAt(2))
                && Character.isLetter(string.charAt(3))) return true;
        return false;
    }

    public static boolean checkFive(String string)
    {
        if(Character.isDigit(string.charAt(1)) && Character.isLetter(string.charAt(0))  && Character.isDigit(string.charAt(2))
                && Character.isLetter(string.charAt(3)) && Character.isLetter(string.charAt(4))) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        for(int i = 0; i < tests; ++i)
        {
            String string = reader.readLine();
            if(!check(string)) System.out.println("-");
            else {
                int curr_pos = 0;
                StringBuilder builder = new StringBuilder();
                while(curr_pos != string.length()) {
                    if(string.length()-curr_pos < 4) break;
                    String tmp = string.substring(curr_pos, curr_pos + 4);
                    boolean f = false;
                    boolean s = false;
                    if (string.length() - curr_pos >= 4) {
                    if (checkFour(tmp)) {
                        builder.append(tmp + " ");
                        curr_pos += 4;
                        f = true;
                    }
                }
                    if(string.length() - curr_pos >= 5) {
                        tmp = string.substring(curr_pos, curr_pos + 5);
                        if (checkFive(tmp)) {
                            builder.append(tmp + " ");
                            curr_pos += 5;
                            s = true;
                        }
                    }

                    if(!f && !s) {
                        break;
                    }
                }
                if(curr_pos == string.length()) System.out.println(builder.toString());
                else System.out.println("-");
            }
        }
        reader.close();
        writer.close();
    }*/

//5 task
/*public static short changeFlag(String[] parts, int idx)
    {
        if(Integer.parseInt(parts[idx-1]) - Integer.parseInt(parts[idx]) == 1) return 0;
        else if(Integer.parseInt(parts[idx-1]) - Integer.parseInt(parts[idx]) == -1) return 2;
        return 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        for(int i = 0; i < tests; ++i)
        {
            int temp = Integer.parseInt(reader.readLine());
            String[] parts = reader.readLine().split(" ");
            if(parts.length == 1) {
                System.out.println(2);
                System.out.println(Integer.parseInt(parts[0]) + " " + 0);
                continue;
            }
            short flag = changeFlag(parts,1);

            List<List<Integer>> list = new ArrayList<>();
            List<Integer> tmp = new ArrayList<>(); tmp.add(Integer.parseInt(parts[0]));
            for(int j = 1; j < parts.length; ++j)
            {
                if(!((flag == 0 && changeFlag(parts, j)==2) || (flag == 2 && changeFlag(parts, j)==0)))flag = changeFlag(parts, j);
                if(flag == changeFlag(parts, j) && (flag == 0 || flag == 2)) tmp.add(Integer.parseInt(parts[j]));
                else if(((flag == 0 && changeFlag(parts, j)==2) || (flag == 2 && changeFlag(parts, j)==0)) && tmp.size() == 1)
                {
                    tmp.add(Integer.parseInt(parts[j]));
                }
                else {
                    list.add(tmp);
                    tmp = new ArrayList<>();
                    tmp.add(Integer.parseInt(parts[j]));
                }
                flag = changeFlag(parts, j);
            }
            list.add(tmp);
            List<Integer> ans = new ArrayList<>();
            for(var a : list)
            {
                ans.add(a.get(0));
                ans.add(a.get(a.size()-1)-a.get(0));
            }

           // System.out.println(flag);
           // System.out.println(tmp);

            System.out.println(ans.size());
            for(var a : ans) System.out.print(a + " ");
            System.out.println();
        }
        reader.close();
        writer.close();
    }*/

// 6 task
/*BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        // L,R,U,D,B,E,N
        for(int i = 0; i < tests; ++i)
        {
            String string = reader.readLine();
            // control index with curr_y
            List<StringBuilder> field = new ArrayList<>();
            int curr_x = 0, curr_y = 0;
            field.add(new StringBuilder());
            for(int j = 0; j < string.length(); ++j) {
                if (string.charAt(j) == 'L') {
                    if (curr_x > 0) --curr_x;
                } else if (string.charAt(j) == 'R') {
                    if (curr_x < field.get(curr_y).length()) ++curr_x;
                } else if (string.charAt(j) == 'U') {
                    if (curr_y > 0) --curr_y;
                    if (curr_x > field.get(curr_y).length()) curr_x = field.get(curr_y).length();
                } else if (string.charAt(j) == 'D') {
                    if (curr_y < field.size() - 1) ++curr_y;
                    if (curr_x > field.get(curr_y).length()) curr_x = field.get(curr_y).length();
                } else if (string.charAt(j) == 'B') curr_x = 0;
                else if (string.charAt(j) == 'E') {
                    curr_x = field.get(curr_y).length();
                }
                // добавить новый элемент в список
                else if (string.charAt(j) == 'N') {
                    field.add(curr_y + 1, new StringBuilder(field.get(curr_y).substring(curr_x, field.get(curr_y).length())));
                    field.get(curr_y).delete(curr_x, field.get(curr_y).length());
                    curr_x = 0;
                    ++curr_y;
                } else {
                    field.get(curr_y).insert(curr_x, string.charAt(j));
                    ++curr_x;
                }
            }

            for(var a : field) System.out.println(a.toString());
            System.out.println("-");
        }
        reader.close();
        writer.close();
    }*/

// 7 task
/*BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        for(int i = 0; i < tests; ++i)
        {
            int pages = Integer.parseInt(reader.readLine());
            char[] arr = new char[pages+1];
            String[] parts = reader.readLine().split(",");
            List<List<Integer>> list = new ArrayList<>();
            List<Integer> tmp = new ArrayList<>();
            for(var a : parts)
            {
                if(!a.contains("-")) arr[Integer.parseInt(a)] = 'c';
                else {
                    for(int j = Integer.parseInt(a.substring(0,a.lastIndexOf("-"))); j <= Integer.parseInt(a.substring(a.lastIndexOf("-")+1,a.length())); ++j) arr[j] = 'c';
                }
            }
            for(int j = 1; j <= pages; ++j)
            {
                if(arr[j] != 'c') tmp.add(j);
                else
                {
                    list.add(tmp);
                    tmp = new ArrayList<>();
                }
            }
            list.add(tmp);
            StringBuilder builder = new StringBuilder();
            for(var a : list)
            {
                if(a.size() == 1) {
                    builder.append(a.get(0));
                    builder.append(",");
                }
                else if(a.isEmpty()) continue;
                else {
                    builder.append(a.get(0));
                    builder.append("-");
                    builder.append(a.get(a.size()-1));
                    builder.append(",");
                }
            }
            builder.delete(builder.length()-1, builder.length());
            System.out.println(builder.toString());
        }
        reader.close();
        writer.close();
    }*/

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int tests = Integer.parseInt(reader.readLine());
        for(int i = 0; i < tests; ++i)
        {
            int players = Integer.parseInt(reader.readLine());

            Map<Character, Integer> cards = new HashMap<>();
            for(int j = 2; j <= 9; ++j)
                cards.put((char)(j+'0'),j);
            cards.put('T',10);
            cards.put('J',11);
            cards.put('Q',12);
            cards.put('K',13);
            cards.put('A',14);

            Map<Integer , List<Integer>> map = new LinkedHashMap<>();
            int [] Spades = new int[13];
            int[] Clubs  = new int[13];
            int[] Diamonds = new int[13];
            int[] Hearts = new int[13];
            Arrays.fill(Spades,4);
            Arrays.fill(Clubs,4);
            Arrays.fill(Diamonds,4);
            Arrays.fill(Hearts,4);

            for(int j = 0;  j < players; ++j)
            {
                String[] parts = reader.readLine().split(" ");
                map.putIfAbsent(j+1, new ArrayList<>());
                List<Integer> list = new ArrayList<>();
                list.add(cards.get(parts[0].charAt(0)));
                list.add(cards.get(parts[1].charAt(0)));
                map.put(j+1, list);

            }
            for(var a : map.entrySet()) System.out.println(a.getKey() + " " + a.getValue() );
            if(map.get(1).get(0) == map.get(1).get(1))
            {
                for(var a : map.entrySet())
                {
                    if(a.getKey() != 1)
                    {
                        if(a.getValue().get(0) == a.getValue().get(1) && a.getValue().get(0) > map.get(1).get(0) )
                        {
                            System.out.println(0);
                            break;
                        }
                    }
                }
            }
            else {
                int card = Math.max(map.get(1).get(0) , map.get(1).get(1));
                for(var a : map.entrySet())
                {
                    if(a.getKey() != 1)
                    {
                        if((a.getValue().get(0) == a.getValue().get(1) && a.getValue().get(0) == card )
                        || (a.getValue().get(0) == a.getValue().get(1) && a.getValue().get(0) != card && a.getValue().get(0) > card ))
                        {
                            System.out.println(0);
                            break;
                        }
                    }
                }
            }
            System.out.println("YES");
        }
        reader.close();
        writer.close();
    }
}