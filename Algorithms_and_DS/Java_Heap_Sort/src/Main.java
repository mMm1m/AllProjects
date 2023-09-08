import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Heap heap = new Heap(n);
        for(int i = 0; i < n; ++i)
        {
            int a = in.nextInt();
            heap.insert(a);
            for(int j = 0; j < n; ++j)
            {
                System.out.print(heap.arr[j] + " ");
            }
            System.out.println();
        }
        while(!heap.isEmpty()) System.out.print(heap.extractMin() + " ");
        in.close();
    }
}

class Heap
{
    public int[] arr;
    private int size;
    private int curr_size;
    public int parent_index(int idx)
    {
        return (idx-1)/2;
    }
    public int left_index(int root)
    {
        return 2*root+1;
    }

    public int right_index(int root)
    {
        return 2*root+2;
    }

    Heap(int size)
    {
        this.arr = new int[size];
        this.size = size;
        curr_size = 0;
    }

    boolean isEmpty() {return curr_size == 0;}

    void sift_up(int index)
    {
        while(index != 0 && arr[parent_index(index)] > arr[index] )
        {
            int temp = arr[parent_index(index)];
            arr[parent_index(index)] = arr[index];
            arr[index] = temp;
            index = parent_index(index);
        }
    }

    void sift_down(int index, int heap_size)
    {
        int largest_index = index, left = left_index(index), right = right_index(index);
        if(arr[left] < arr[index] && left < heap_size)  largest_index = left;
        if(arr[right] < arr[largest_index] && right < heap_size)  largest_index = right;
        if(index != largest_index)
        {
            int temp = arr[index];
            arr[index] = arr[largest_index];
            arr[largest_index] = temp;
            sift_down(largest_index, heap_size);
        }
    }

    void insert(int val)
    {
        arr[curr_size] = val;
        sift_up(curr_size);
        ++curr_size;
    }

    /*int extractMax()
    {
        int ans = arr[0];
        int temp = arr[0];
        arr[0] = arr[curr_size-1];
        arr[curr_size-1] = temp;
        --curr_size;
        sift_down(0, curr_size);
        return ans;
    }*/

    int extractMin()
    {
        int ans = arr[0], temp = arr[0];
        arr[0] = arr[curr_size-1];
        arr[curr_size-1] = temp;
        --curr_size;
        sift_down(0, curr_size);
        return ans;
    }
}