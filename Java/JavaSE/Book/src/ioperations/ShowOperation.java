package ioperations;

import book.BookList;

public class ShowOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("显示图书");
    }
}