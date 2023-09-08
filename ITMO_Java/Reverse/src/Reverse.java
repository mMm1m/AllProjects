import java.util.Arrays;
import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        int[][] original_array = new int[1][];
        int max_size = 0, curr_size = 0;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())
        {
            if(max_size == original_array.length) original_array = Arrays.copyOf(original_array, 2*max_size);
            String string = sc.nextLine();
            Scanner inner = new Scanner(string);
            if(string.equals("W")) break;
            int pointer = 0;
            int[] inner_array = new int[0];
            if(!string.isEmpty())
            {
                inner_array = Arrays.copyOf(inner_array, 1);
                while (inner.hasNextInt()) {
                    if (pointer == inner_array.length)
                        inner_array = Arrays.copyOf(inner_array, 2 * pointer);
                    int nextInt = inner.nextInt();

                    inner_array[pointer++] = nextInt;
                }
            }
            original_array[max_size++] = inner_array;
            curr_size++;
            inner.close();
        }
        for(int i = curr_size-1; i >= 0; --i)
        {
            for(int j = original_array[i].length-1; j >= 0; --j)
            {
                System.out.print(original_array[i][j] + " ") ;
            }
            System.out.println();
        }
        sc.close();
    }
}