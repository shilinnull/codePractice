package ioperations;

import book.Book;
import book.BookList;

import java.util.Scanner;

public class FindOperation implements IOPeration{
    @Override
    public void work(BookList bookList) {
        System.out.println("查找图书");

        // 输入
        Scanner scanner = new Scanner(System.in);
        System.out.printf("请输入你的书名：");
        String name = scanner.nextLine();

        // 遍历查找
        for (int i = 0; i < bookList.getUsedSize(); i++) {
            Book book = bookList.getBook(i);
            if(book.getName().equals(name)){
                System.out.println("找到了这本书：");
                System.out.println(book);
                return;
            }
        }
        System.out.println("没有你要找的这本书....");
    }
}