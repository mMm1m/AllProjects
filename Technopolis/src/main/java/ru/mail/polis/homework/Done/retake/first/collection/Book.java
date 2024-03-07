package ru.mail.polis.homework.retake.first.collection;

import lombok.Getter;
import lombok.RequiredArgsConstructor;
import lombok.Setter;

import java.util.stream.Stream;

/**
 * Реализовать класс книги
 */
@Getter
@Setter
@RequiredArgsConstructor
public class Book {
    // книга должна хранить следующие поля:
    // автор книги, дата написания, уникальный id-шник книги
    private String author;
    private int year;
    private static int ID = 0;
    Book(String a, int y)
    {
        this.author = a;
        this.year = y;
        ++ID;
    }
    public int getID()
    {
        return ID;
    }

}
