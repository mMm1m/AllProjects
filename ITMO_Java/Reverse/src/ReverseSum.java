import java.util.Arrays;
import java.util.Scanner;

public class ReverseSum {
    public static void main(String[] args) {
        int[][] original_array = new int[1][];
        int[] col = new int[1];
        int[] str = new int[1];
        int height = 0, max_col_length = 0;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())
        {
            if(height == str.length) str = Arrays.copyOf(str, 2*str.length);
            if(height == original_array.length) original_array = Arrays.copyOf(original_array, 2*original_array.length);
            String string = sc.nextLine();
            Scanner inner = new Scanner(string);
            if(string.equals("W")) break;
            int pointer = 0;
            int[] inner_array = new int[0];
            if(!string.isEmpty())
            {
                inner_array = Arrays.copyOf(inner_array, 1);
                while (inner.hasNextInt()) {
                    if(pointer == col.length) col = Arrays.copyOf(col, 2*col.length);
                    if (pointer == inner_array.length)
                        inner_array = Arrays.copyOf(inner_array, 2 * pointer);
                    int nextInt = inner.nextInt();
                    str[height] += nextInt;
                    col[pointer] += nextInt;
                    inner_array[pointer++] = nextInt;
                }
            }
            original_array[height++] = Arrays.copyOf(inner_array,pointer);
            max_col_length = Math.max(max_col_length, pointer);
            inner.close();
        }
        str = Arrays.copyOf(str, height);
        col = Arrays.copyOf(col, max_col_length);
        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < original_array[i].length; ++j)
            {
                System.out.print(str[i] + col[j] - original_array[i][j] + " ") ;
            }
            System.out.println();
        }
        sc.close();
    }
}