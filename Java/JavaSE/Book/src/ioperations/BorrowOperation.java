package ioperations;

import book.BookList;

public class BorrowOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("借阅图书");
    }
}
