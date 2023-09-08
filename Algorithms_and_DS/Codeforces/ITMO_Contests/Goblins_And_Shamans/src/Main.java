import java.util.*;

class CustomLinkedList {

    private Node head;
    private Node tail;
    private Stack<Node> stack = new Stack<>();
    public int curr_major_pos;
    private Node curr_major_pos_node;
    private int curr_size;
    CustomLinkedList()
    {
        head = curr_major_pos_node = tail = null;
        curr_size = 0;
        curr_major_pos = 0;
    }
    public int size() {
        return curr_size;
    }

    public void add(int value) {
        Node node = new Node(value);
        if(head == null) {head = tail = curr_major_pos_node = node; ++curr_size;}
        else {
            tail.setNext(node);
            tail = node;
            tail.setNext(null);
            ++curr_size;
        }
        stack.push(node);
    }

    public void addInTheMiddle(int value) {
        int curr_= curr_major_pos;
        Node curr = curr_major_pos_node;
        Node node = new Node(value);
        if(size() == 1 || size() == 0 || size() == 2)  add(value);
        else
        {
            while(curr_ != (size()-1)/2)
            {
                curr = curr.next;
                ++curr_;
            }
            Node tmp = curr.next;
            curr.setNext(node);
            node.setNext(tmp);
            ++curr_size;
        }
        if(curr_major_pos != curr_)  {
            curr_major_pos = curr_;
            curr_major_pos_node = curr_major_pos_node.next;
        }
        stack.push(node);
    }

    public void removeElement() {
        if(size() == 0) throw new NoSuchElementException();
        else if(size() == 1)  head = tail = curr_major_pos_node = null;
        else {
            head = head.next;
            --curr_size;
            if(curr_major_pos != (size()-1)/2)
            {
                curr_major_pos = (size()-1)/2;
                //curr_major_pos_node = curr_major_pos_node.prev;
                int i = 0;
                Node curr = head;
                while(i != curr_major_pos)
                {
                    curr = curr.next;
                    ++i;
                }
                curr_major_pos_node = curr;
            }
        }
    }

    public int get(int index) {
        int curr_ = 0;
        Node curr = head;
        while(index != curr_)
        {
            curr = curr.next;
            ++curr_;
        }
        return curr.value;
    }

    private static class Node {
        private int value;
        private Node next;
        private Node prev;
        public Node(int value) {
            this.value = value;
        }

        public void setNext(Node next) {
            this.next = next;
        }
    }
}

public class Main {
    public static void main(String[] args) {
       // Scanner sc = new Scanner(System.in);
       // int n = sc.nextInt();
        CustomLinkedList list = new CustomLinkedList();
        list.add(4);
        list.addInTheMiddle(5);
        list.add(6);
        list.addInTheMiddle(1);
        list.addInTheMiddle(2);
        list.add(7);
        list.removeElement();
        list.addInTheMiddle(19);
        for(int i = 0; i < list.size(); ++i) System.out.print(list.get(i) + " " );
        /*for(int i = 0; i < n; ++i)
        {
            String c = sc.next();
            if(c.charAt(0) == '+')
            {
                int temp = sc.nextInt();
                list.add(temp);
            }
            else if(c.charAt(0) == '-')
            {
                System.out.println(list.get(0));
                list.removeElement();
            }
            else {
                int temp = sc.nextInt();
                list.addInTheMiddle(temp);
            }
        }
        sc.close();
    }*/
    }
}