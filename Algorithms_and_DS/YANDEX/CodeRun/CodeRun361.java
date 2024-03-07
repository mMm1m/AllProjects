import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

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

    public static int sum(int n, int[] arr)
    {
        if(n == 2) return arr[1]-arr[0];
        if(n == 3) return arr[2]-arr[0];

        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = arr[1]-arr[0];
        dp[2] = arr[2]-arr[0];
        for(int i = 3; i < n; ++i)
        {
            int curr = (arr[i]-arr[i-1]);
            dp[i] = Math.min(dp[i-2] + curr, dp[i-1]+curr);
        }
        return dp[n-1];
    }

    public static void main(String[] args) throws IOException {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out)))
        {
            int n = Integer.parseInt(reader.readLine());
            String[] parts = reader.readLine().split(" ");
            int[] arr = new int[n];
            for(int i = 0; i < n; ++i)
                arr[i] = Integer.parseInt(parts[i]);
            Arrays.sort(arr);

            System.out.println(sum(n,arr));
        }
    }

}

