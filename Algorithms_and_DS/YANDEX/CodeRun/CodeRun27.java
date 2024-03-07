import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static int func(int n)
    {
        if(n  <= 7) return n;
            int[] dp = new int[n+1];
            for(int i = 0; i <= 7; ++i) dp[i] = i;
            for (int i = 8; i <= n; ++i)
            {
                dp[i] = i;
                for(int j = 0; j < Math.ceil(Math.sqrt(i)); ++j)
                {
                    int temp = j*j*j;
                    if(temp > i) break;
                    else dp[i] = Math.min(dp[i], 1+dp[i-temp]); 
                }
            }
            return dp[n];
    }
    public static void main(String[] args) throws IOException {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int n = Integer.parseInt(reader.readLine());
            System.out.print(func(n));
        }
    }

}
