package ru.mail.polis.homework.retake.first.collection;

import java.util.*;
import java.util.function.BiPredicate;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Реализовать класс библиотеки, которая в себе хранит книги.
 * Книги в библиотеку можно добавлять и удалять из нее.
 *
 *
 */
public class Library implements Iterable<Book> {
    List<Book> bookList;
    HashMap<String, List<Book>> author_map;
    HashMap<Integer, List<Book>> date_map;
    private int curr_size = 0;
    Library()
    {
        bookList = new LinkedList<>();
        //  trie = new TrieNode();
        author_map = new HashMap<>();
        date_map = new HashMap<>();
    }

    public int CustomBinarySearch(List<Book> book, int left, int right, int curr_ID)
    {
        while(left <= right)
        {
            int mid = left + (right-left)>>1;
            if(this.bookList.get(mid).getID() ==  curr_ID) return mid;
            else if(this.bookList.get(mid).getID() <  curr_ID){
                left = mid+1;
            }
            else right = mid-1;
        }
        return -left-1;
    }

    public boolean addBook(Book book) {
        if(bookList.contains(book)) return false;
        bookList.add(book);
        ++curr_size;
        // (?)
        author_map.put(book.getAuthor(), author_map.getOrDefault(author_map.get(book.getAuthor()).add(book), new LinkedList<>()));
        date_map.put(book.getYear(), date_map.getOrDefault(date_map.get(book.getYear()).add(book), new LinkedList<>()));
        return true;
    }

    public boolean removeBook(Book book) {
        int index = CustomBinarySearch(bookList,0,bookList.size()-1, book.getID());
        if(index < 0) return false;
        bookList.remove(index);
        if(author_map.get(book.getAuthor()).size() == 1)
        {
            author_map.remove(book.getAuthor());
        }
        else{
            author_map.get(book.getAuthor()).remove(book);
        }

        if(date_map.get(book.getYear()).size() == 1)
        {
            date_map.remove(book.getYear());
        }
        else{
            date_map.get(book.getYear()).remove(book);
        }
        --curr_size;
        return true;
    }

    public List<Book> getBooksByAuthor(String author) {
        // создать хэш-таблицу, ключом которой является String author,
        // значением List<Books>
        return author_map.get(author);
    }

    public List<Book> getBooksByDate(int year) {
        return date_map.get(year);
    }

    public Book getLastBook() {
        return bookList.get(bookList.size()-1);
    }

    class CustomIterator implements Iterator<Book> {
        private int curr_pos;
        private int step;
        private int temp = curr_size;

        CustomIterator(int start_pos, int step) {
            this.curr_pos = start_pos;
            this.step = step;
        }

        @Override
        public boolean hasNext() {
            return curr_pos < bookList.size();
        }

        @Override
        public Book next() {
            if (temp != curr_size) throw new ConcurrentModificationException();
            Book ans = bookList.get(curr_pos);
            curr_pos += step;
            return ans;
        }
    }

    public Iterator<Book> iterator(Predicate<Book> predicate) {
        return bookList.stream().filter(predicate::test).iterator();
    }

    @Override
    public Iterator<Book> iterator() {
        return new CustomIterator(0,1);
    }

    public Iterator<Book> iterator(BiPredicate<Integer, Book> predicate) {
        return IntStream.range(0,bookList.size()-1)
                .filter(idx -> predicate.test(idx, bookList.get(idx)))
                .mapToObj(bookList::get).iterator();
    }
}
