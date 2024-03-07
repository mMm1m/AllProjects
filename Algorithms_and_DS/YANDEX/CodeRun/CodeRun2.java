import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    /*
	Для чтения входных данных необходимо получить их
	из стандартного потока ввода (System.in).
	Данные во входном потоке соответствуют описанному
	в условии формату. Обычно входные данные состоят
	из нескольких строк. Можно использовать более производительные
	и удобные классы BufferedReader, BufferedWriter, Scanner, PrintWriter.

	С помощью BufferedReader можно прочитать из стандартного потока:
	* строку -- reader.readLine()
	* число -- int n = Integer.parseInt(reader.readLine());
	* массив чисел известной длины (во входном потоке каждое число на новой строке) --
	int[] nums = new int[len];
    for (int i = 0; i < len; i++) {
        nums[i] = Integer.parseInt(reader.readLine());
    }
	* последовательность слов в строке --
	String[] parts = reader.readLine().split(" ");

	Чтобы вывести результат в стандартный поток вывода (System.out),
	Через BufferedWriter можно использовать методы
	writer.write("Строка"), writer.write('A') и writer.newLine().

	Возможное решение задачи "Вычислите сумму чисел в строке":
	int sum = 0;
    String[] parts = reader.readLine().split(" ");
    for (int i = 0; i < parts.length; i++) {
        int num = Integer.parseInt(parts[i]);
        sum += num;
    }
    writer.write(String.valueOf(sum));
	*/

    public static int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0 && j > 0)
                grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                grid[i][0] += grid[i - 1][0];
                else if (j > 0)
                grid[0][j] += grid[0][j - 1];
            }
        }
    return grid[m - 1][n - 1];
    }
    
    public static void main(String[] args) throws IOException {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out)))
        {
            String[] int_parts = reader.readLine().split(" ");
            int n = Integer.parseInt(int_parts[0]);
            int m = Integer.parseInt(int_parts[1]);
            int[][] dp = new int[n][m];
            for(int i = 0; i < n; ++i)
            {
                String[] parts = reader.readLine().split(" ");
                for(int j = 0; j < parts.length; ++j)
                {
                    int curr = Integer.parseInt(parts[j]);
                    dp[i][j] = curr;
                }
            }
            System.out.print(minPathSum(dp));
        }
    }

}
