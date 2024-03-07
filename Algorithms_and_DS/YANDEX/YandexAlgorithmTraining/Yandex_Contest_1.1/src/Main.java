import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void first() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = scanner.readLine().split(" ");
        String cmd = scanner.readLine();
        switch(cmd)
        {
            case "auto":
                System.out.println(Integer.parseInt(tmp[1]));
                break;
            case "freeze":
                System.out.println(Math.min(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1])));
                break;
            case "heat":
                System.out.println(Math.max(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1])));
                break;
            default:
                System.out.println(Integer.parseInt(tmp[0]));
                break;
        }
    }

    public static boolean IsTriangle() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        int[] a = new int[3];
        a[0] = Integer.parseInt(scanner.readLine());
        a[1] = Integer.parseInt(scanner.readLine());
        a[2] = Integer.parseInt(scanner.readLine());
        Arrays.sort(a);
        return a[2] < a[1]+a[0];
    }

    public static void PhoneNumber() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        String pattern = scanner.readLine();
        pattern = pattern.replace("(", "");
        pattern = pattern.replace(")", "");
        pattern = pattern.replace("-", "");
        pattern = pattern.replace("+", "");
        int i = 3;
        while(i > 0)
        {
            String tmp = scanner.readLine();
            tmp = tmp.replace("-","");
            tmp = tmp.replace("+", "");
            pattern = pattern.replace("(", "");
            pattern = pattern.replace(")", "");
            if(pattern.length() == tmp.length())
            {
                if(pattern.substring(1,pattern.length()).equals(tmp.substring(1, tmp.length()))
                && (tmp.charAt(0) == '8' || tmp.charAt(0) == '7')) System.out.println("YES");
                else System.out.println("NO");
            }
            else {
                if(pattern.substring(4,pattern.length()).equals(tmp)) System.out.println("YES");
                else System.out.println("NO");
            }
            --i;
        }
    }

    public static void Equal() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(scanner.readLine());
        int b = Integer.parseInt(scanner.readLine());
        int c = Integer.parseInt(scanner.readLine());
        if (c < 0)
            System.out.println("NO SOLUTION");
        else if ((a + b) == c * c && (2 * a + b) == c * c)
            System.out.println("MANY SOLUTIONS");
        else {
            double d = (Math.pow(c, 2) - b) / a;
            if (a != 0 && d == (int) (d))
                System.out.println((int) (d));
            else
                System.out.println("NO SOLUTION");
        }
    }

    public static void Laptops() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = scanner.readLine().split(" ");
        int[][] map = new int[4][2];
        map[0][0] = Math.max(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[2]));
        map[0][1] = Integer.parseInt(tmp[1])+Integer.parseInt(tmp[3]);
        map[1][0] = (Math.max(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[3])));
        map[1][1] = Integer.parseInt(tmp[1])+Integer.parseInt(tmp[2]);
        map[2][0] = (Math.max(Integer.parseInt(tmp[1]), Integer.parseInt(tmp[2])) );
        map[2][1] = (Integer.parseInt(tmp[0])+Integer.parseInt(tmp[3]));
        map[3][0] = (Math.max(Integer.parseInt(tmp[1]), Integer.parseInt(tmp[3]))) ;
        map[3][1] = (Integer.parseInt(tmp[0])+Integer.parseInt(tmp[2]));
        int sq = Integer.MAX_VALUE, f = 0, s = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(sq > map[i][0]*map[i][1])
            {
                f=  map[i][0];
                s = map[i][1];
                sq = map[i][0]*map[i][1];
            }
        }
        System.out.println(f + " " + s);
    }

    public static int Details() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = scanner.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int k = Integer.parseInt(tmp[1]);
        int m = Integer.parseInt(tmp[2]);
        if(k > n || m > k) return 0;
        int remain = n, details = 0;
        while(remain >= k)
        {
            int parts = remain / k;
            int curr = parts*(k/m);
            details += curr;
            remain -= m*curr;
        }
        return details;
    }

    public static void Metro() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        int[] a = new int[4];
        a[0] = Integer.parseInt(scanner.readLine());
        a[1] = Integer.parseInt(scanner.readLine());
        a[2] = Integer.parseInt(scanner.readLine());
        a[3] = Integer.parseInt(scanner.readLine());
        int f_min = a[2]+a[0]*(a[2]-1);
        int f_max = a[2]+a[0]*(a[2]+1);

        int s_min = a[3]+a[1]*(a[3]-1);
        int s_max = a[3]+a[1]*(a[3]+1);
        int min = Math.max(f_min, s_min), max = Math.min(f_max, s_max);
        if(min > max) System.out.println(-1);
        else System.out.println(min + " " + max);
    }

    public static void IF() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[3];
        arr[0] = Integer.parseInt(scanner.readLine());
        arr[1] = Integer.parseInt(scanner.readLine());
        arr[2] = Integer.parseInt(scanner.readLine());
        int d = Integer.parseInt(scanner.readLine());
        int e = Integer.parseInt(scanner.readLine());
        Arrays.sort(arr);
        int hole_min = Math.min(d,e) , hole_max = Math.max(d,e);
        if(Math.min(hole_min, arr[0]) == arr[0] && Math.max(hole_max, arr[1]) == hole_max )
            System.out.println("YES");
        else System.out.println("NO");
    }

    public static void SystemOfLinearEquations() throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        double a = Double.parseDouble(scanner.readLine());
        double b = Double.parseDouble(scanner.readLine());
        double c = Double.parseDouble(scanner.readLine());
        double d = Double.parseDouble(scanner.readLine());
        double e = Double.parseDouble(scanner.readLine());
        double f = Double.parseDouble(scanner.readLine());
        double x,y;
        double delimiter = a*d-b*c;
        double delimiter_x = (e*d)-(b*f);
        double delimiter_y = (a*f)-(e*c);
        if(delimiter != 0)
            System.out.println(2 + " " + delimiter_x/delimiter + " " + delimiter_y/delimiter);
        else {
            if(delimiter_x == 0 && delimiter_y == 0)
            {
                if(a == 0 && c ==0 && b == 0 && d == 0)
                {
                    if(e!=0 || f!=0) System.out.println(0);
                    else System.out.println(5);
                }
                else if(a == 0 && c == 0)
                {
                    if(b != 0) y = e/b;
                    else y = f/d;
                    System.out.println(4 + " " + y);
                }
                else if(b == 0 && d == 0)
                {
                    if(a != 0) x = e/a;
                    else x = f/c;
                    System.out.println(3 + " " + x);
                }
                else
                {
                    double bi, k;

                    if (b != 0) {
                        bi = e / b;
                        k = -a / b;
                    }
                    else {
                        bi = f / d;
                        k = -c / d;
                    }
                    System.out.println(1 + " " + k + " " + bi);
                }
            }
            else {
                System.out.println(0);
            }
        }
        }

    public static void main(String[] args) throws IOException {
        PhoneNumber();
    }
}