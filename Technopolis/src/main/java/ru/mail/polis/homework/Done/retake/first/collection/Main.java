package ru.mail.polis.homework.retake.first.collection;

public class Main {
    public static void main(String[] args)
    {
        String w1 = "horse";
        String w2 = "ros";

    }
    public static int minDistance(String word1, String word2) {
        if(word1.length() == 0 && word2.length() == 0
                || word1.equals(word2)) return 0;

        if(!word1.isEmpty() && word2.isEmpty() || !word2.isEmpty() && word1.isEmpty())
            return Math.max(word1.length(), word2.length());

        // если собираемся:
        // удалять букву(dp[i-1][j])
        // добалять букву(dp[i][j-1])
        // менять букву местами(dp[i-1][j-1])

        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m+1][n+1];
        dp[0][0] = 0;
        for(int i = 0; i <= m; ++i)
            for(int j = 0; j <= n; ++j)
                dp[i][j] = Integer.MAX_VALUE;

        for(int i = 0; i <= m; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                // delete
                if(i != 0)
                {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j]+1);
                }
                // insert
                if(j != 0)
                {
                    dp[i][j] = Math.min(dp[i][j], dp[i][j-1]+1);
                }
                // replace
                if(i != 0 && j != 0)
                {
                    int add = (word1.charAt(i-1) != word2.charAt(j-1)) ? 1 : 0;
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]+add);
                }
            }
        }
        for(int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j)
            {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        return dp[m][n];
    }
}
