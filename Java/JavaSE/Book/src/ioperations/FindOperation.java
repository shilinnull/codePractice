package ioperations;

import book.BookList;

public class FindOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("查找图书");
    }
}