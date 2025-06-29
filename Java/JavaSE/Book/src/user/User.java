package user;

import book.BookList;
import ioperations.IOPeration;

public abstract class User {
    protected String name;
    protected IOPeration[] ioPerations; // 操作方法集

    // 子类初始化父类的成员
    public User(String name) {
        this.name = name;
    }

    // 让不同的用户显示不同的菜单
    public abstract int menu();
    public void doIoperation(int choice, BookList bookList){
        ioPerations[choice].work(bookList); // 传递参数让执行任务
    }

}
