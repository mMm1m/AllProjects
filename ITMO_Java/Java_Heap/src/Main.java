import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //int n = Integer.parseInt(sc.nextLine());
        Heap heap = new Heap();
        /*for(int i = 0; i < n; ++i)
        {
            int a;
            a = sc.nextInt();
            if(a == 0) {
                int b;
                b = sc.nextInt();
                heap.insert(b);
            }
            else {System.out.println(heap.extractMin());}
        }*/
        int curr = 1;
        while(sc.hasNextLine())
        {
            String string = sc.nextLine();
            Scanner inner = new Scanner(string);
            String cmd = inner.next();
            if(cmd.equals("push"))
            {
                int num = inner.nextInt();
                heap.insert(num);
            }
            else if(cmd.equals("extract"))
                System.out.println((heap.getSize() <= 0) ? (char)heap.extractMin() : heap.extractMin());
            else
            {
                int index = inner.nextInt(), value = inner.nextInt();
                heap.decrease_key(index, value);
            }
            inner.close();
        }
        sc.close();
    }
}

class Heap
{
    private int[] arr;
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

    Heap()
    {
        this.arr = new int[1];
        this.size = 1;
        curr_size = 0;
    }

    Heap(int size)
    {
        this.arr = new int[size];
        this.size = size;
        curr_size = 0;
    }

    public void sift_up(int index)
    {
        while(index != 0 && arr[parent_index(index)] > arr[index] )
        {
            int temp = arr[parent_index(index)];
            arr[parent_index(index)] = arr[index];
            arr[index] = temp;
            index = parent_index(index);
        }
    }

    public void sift_down(int index, int heap_size)
    {
        int largest_index = index, left = left_index(index), right = right_index(index);
        if(arr[left] < arr[index] && left < heap_size)  largest_index = left;
        if(arr[right] < arr[largest_index] && right < heap_size)  largest_index = right;
        if(index != largest_index)
        {
            int temp = arr[index];
            arr[index] =  arr[largest_index];
            arr[largest_index] = temp;
            sift_down(largest_index, heap_size);
        }
    }

    public void insert(int val)
    {
        if(curr_size == size)
        {
            arr = Arrays.copyOf(arr, 2*size);
            size *= 2;
        }
        arr[curr_size] = val;
        sift_up(curr_size);
        ++curr_size;
    }

    public void decrease_key(int moment, int now)
    {
        boolean flag = false;
        int index = -1;
        for(int i = 0; i < arr.length; ++i)
            if(arr[i] == moment) {flag = true; index = i;}
        if(!flag) return;
        arr[index] = now;
        while(index > 0 && arr[index] < arr[parent_index(index)])
        {
            int temp = arr[index];
            arr[index] = arr[parent_index(index)];
            arr[parent_index(index)] = temp;
            index = parent_index(index);
        }
    }

    public int getSize()
    {
        return curr_size;
    }

    public int extractMin()
    {
        if(curr_size <= 0)  return (int)('*');
        if(curr_size == 1)
        {
            --curr_size;
            return arr[0];
        }
        int ans = arr[0];
        arr[0] = arr[curr_size-1];
        --curr_size;
        sift_down(0, curr_size);
        return ans;
    }
}