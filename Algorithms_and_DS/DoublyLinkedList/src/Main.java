import java.util.*;
import java.util.function.Consumer;

class Node
{
    public int val;
    public Node next;
    public Node prev;
    /*Node(int v, Node prev, Node next)
    {
        this.next = next;
        this.prev = prev;
        this.val = v;
    }*/
    Node(int v)
    {
        this.val = v;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node head;
    Node tail;
    private int size;
    private Map<Integer, Node> map;
    DoublyLinkedList()
    {
        this.size = 0;
        this.head = null;
        this.tail = null;
        map = new HashMap<>();
    }

    public void insertFront(int new_data)
    {
        Node new_Node = new Node(new_data);
        if(this.size == 0) this.head = this.tail = new_Node;
        else {
            this.head.prev = new_Node;
            new_Node.next = this.head;
            this.head = new_Node;
        }
        ++this.size;
        map.put(new_data, new_Node);
    }


    public void insertBack(int data) {
        Node new_Node = new Node(data);
        if(this.head == null) {
            this.head = new_Node;
            this.tail = new_Node;
        } else {
            this.tail.next = new_Node;
            new_Node.prev = this.tail;
            this.tail = new_Node;
        }
        this.size++;
        map.put(data, new_Node);
    }

    public void insert(int idx, int data) {
        if(idx < 0 || idx > this.size) throw new ConcurrentModificationException();
        Node node = new Node(data);
        if(idx == 0 || this.size == 0) insertFront(data);
        else if(idx == this.size) insertBack(data);
        else {

            Node curr = this.head;
            int curr_idx = 0;
            while(curr_idx != idx-1)
            {
                curr=  curr.next;
                ++curr_idx;
            }

            node.next = curr.next;
            curr.next = node;
            node.prev = curr;
            if (node.next != null)
                node.next.prev = node;
            map.put(data, node);
        }
        ++this.size;
    }

    public void remove(Node del) {
        if (head == null || del == null)  return;
        if (head == del) head = del.next;
        else if(tail == del) tail = del.prev;
        if (del.next != null) del.next.prev = del.prev;
        if (del.prev != null) del.prev.next = del.next;
        map.remove(del.val);
    }
    public void print(Node h)
    {
        Node curr = h;
        while(curr != null)
        {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}



public class Main {
    public static void main(String[] args) {
            DoublyLinkedList list = new DoublyLinkedList();
            try {
                list.insert(0, 3);
                list.insert(1, 5);
                list.remove(list.tail);
            }
            catch (ConcurrentModificationException e)
            {
                e.printStackTrace();
            }
            list.print(list.head);

    }
}