package ioperations;

import book.BookList;

public class ReturnOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("归还图书");
    }
}