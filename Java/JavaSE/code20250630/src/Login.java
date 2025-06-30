import java.util.InputMismatchException;
import java.util.Scanner;

public class Login {
    private String userName = "admin";
    private String password = "123456";

    public static void loginInfo(String userName, String password)
            throws UserNameException,PasswordException{ // 声明异常
        if (!userName.equals(userName)) {
            throw new UserNameException("用户名错误！");
        }
        if (!password.equals(password)) {
            throw new PasswordException("用户名错误！");
        }
        System.out.println("登陆成功");
    }

    public static void main(String[] args) {
        try {
            loginInfo("admin", "123456");
        } catch (UserNameException e) {
            e.printStackTrace();
        } catch (PasswordException e) {
            e.printStackTrace();
        }
        while (true) {
            try (Scanner sc = new Scanner(System.in)) {
                int data = sc.nextInt();
                System.out.println(data);
                break;
            } catch (InputMismatchException e) {
                e.printStackTrace();
            } finally {
                System.out.println("处理finally代码");
            }
        }
    }
}