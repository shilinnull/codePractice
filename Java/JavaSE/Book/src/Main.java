import book.BookList;
import user.AdminUser;
import user.NormalUser;
import user.User;

import java.util.Scanner;

public class Main {



    public static void main(String[] args) {
        BookList bookList = new BookList();


        User user = login();
        if(user == null)
            System.out.println("未知用户！");
        while (true){
            int choice = user.menu(); // 初始化菜单

            user.doIoperation(choice, bookList); // 做操作
        }
    }

    private static User login() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入你的姓名：");
        String name = scanner.nextLine();
        System.out.println("请输入你的身份，1：管理员   2：普通用户");

        int choice = scanner.nextInt();
        if(choice == 1){
            return new AdminUser(name);
        }else if(choice == 2){
            return new NormalUser(name);
        }else{
            System.out.println("输入错误请！");
            return null;
        }
    }
}

