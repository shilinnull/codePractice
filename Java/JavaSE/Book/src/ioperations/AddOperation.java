package ioperations;

import book.BookList;

public class AddOperation implements IOPeration{

    @Override
    public void work(BookList bookList) {
        System.out.println("添加图书");
    }
}
