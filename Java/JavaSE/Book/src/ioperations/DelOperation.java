package ioperations;

import book.Book;
import book.BookList;

import java.util.Scanner;

public class DelOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("删除图书");

        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入你删除的书名：");
        String name = scanner.nextLine();
        int currentSize = bookList.getUsedSize();

        int pos = -1; // 要删除书的下标
        for (int i = 0; i < currentSize; i++) {
            Book book = bookList.getBook(i);
            if(book.getName().equals(name)){
                pos = i;
                break;
            }
        }

        if(pos == -1) {
            System.out.println("没有你要删除的书！");
            return;
        }
        for(int i = pos; i < currentSize - 1; i++){
            Book book = bookList.getBook(i + 1);
            bookList.setBook(i, book);
        }
        bookList.setUsedSize(currentSize - 1);
        bookList.setBook(currentSize - 1, null);
        System.out.println("删除成功！！！！");
    }
}