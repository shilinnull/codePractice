package ioperations;

import book.BookList;

public class DelOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("删除图书");
    }
}