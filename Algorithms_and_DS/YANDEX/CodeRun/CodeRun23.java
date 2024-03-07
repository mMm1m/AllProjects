import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(reader.readLine());
        Deque<Integer> queue1 = new ArrayDeque<>();
        Deque<Integer> pqueue1 = new ArrayDeque<>();
        int k1 = 0,  k2 = 0;
        for(int i= 0; i < n; ++i)
        {
            String[] string  = reader.readLine().split(" ");
            if(string[0].equals("-"))
            {
                writer.write(String.valueOf(queue1.pop()));
                writer.write('\n');
                --k1;
            }
            else if(string[0].equals("*")) {
                pqueue1.addFirst(Integer.parseInt(string[1]));
                ++k2;
            }
            else{
                pqueue1.add(Integer.parseInt(string[1]));
                ++k2;
            }
            if(k1 < k2)
            {
                queue1.add(pqueue1.pop());
                --k2;
                ++k1;
            }
        }
        reader.close();
        writer.close();
    }
}
