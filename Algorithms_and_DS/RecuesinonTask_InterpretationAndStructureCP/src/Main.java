import java.util.*;
import java.io.*;
public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        String string =sc.readLine();
        string = string.replace("-", "");
        string = string.replace("(", "");
        string = string.replace(")", "");
        if(string.startsWith("+7")) {string = string.replace("+7","8");}
        for(int i = 0; i < 3; ++i)
        {
            String str = sc.readLine();
            str = str.replace("-", "");
            str = str.replace("(", "");
            str = str.replace(")", "");
            if(str.startsWith("+7")) {str = str.replace("+7","8");}
            if(str.length() == 7)
            {
                str = ("8495"+str);
                System.out.println(str);
                if(string.equals(str))
                {
                    System.out.println("YES");
                    continue;
                }
            }
            else if(str.length() > 7)
            {
                //if(string.substring(string.length()-7, string.length()).equals(str.substring(str.length()-7, str.length()))
                //&& (string.substring(0,4).equals(str.substring(0,4))))
                if(string.equals(str))
                {
                    System.out.println("YES");
                    continue;
                }
            }
            System.out.println("NO");
        }
        sc.close();
    }
}
