import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int count = 0;
        for (int i = 101; i <= 200; i++) {
            boolean flag = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
                System.out.println(i + "数字是质数");
            }
        }
        System.out.println("质数:" + count + "个");
    }
}

