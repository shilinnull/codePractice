package ioperations;

import book.Book;
import book.BookList;

import java.util.Scanner;

public class AddOperation implements IOPeration{

    @Override
    public void work(BookList bookList) {
        System.out.println("添加图书");

        // 1. 判满
        if(bookList.getUsedSize() == bookList.getBooks().length){
            System.out.println("书架满了 不能放了.....");
            return;
        }

        //2. 构建对象
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入书名：");
        String name = scanner.nextLine();

        System.out.println("请输入作者：");
        String author = scanner.nextLine();

        System.out.println("请输入书的类型：");
        String type = scanner.nextLine();

        System.out.println("请输入价格：");
        int price = scanner.nextInt();
        Book newBook = new Book(name,author,price,type);

        //3. 判断书架有没有这本书
        for (int i = 0; i < bookList.getUsedSize(); i++) {
            Book book = bookList.getBook(i);
            if(book.getName().equals(name)) {
                System.out.println("有这本书不能插入！");
                return;
            }
        }
        bookList.setBook(bookList.getUsedSize(), newBook);
        bookList.setUsedSize(bookList.getUsedSize() + 1);
        System.out.println("新增图书成功！！！");
    }
}
