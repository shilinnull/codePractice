import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

class Config {
    File file;

    public void openConfig(String filename) throws FileNotFoundException {
        if (!filename.equals("config.ini")) {
            throw new FileNotFoundException("配置文件名字不对");
        }
// 打开文件
    }

    public void readConfig() {
    }

    public static void main(String[] args) {
        Config config = new Config();
        try {
            config.openConfig("config.txt");
            System.out.println("文件打开成功");
        } catch (IOException e) {
// 异常的处理方式
//System.out.println(e.getMessage()); // 只打印异常信息
//System.out.println(e); // 打印异常类型：异常信息
            e.printStackTrace(); // 打印调用栈
        }finally {

        }
// 一旦异常被捕获处理了，此处的代码会执行
        System.out.println("异常如果被处理了，这里的代码也可以执行");
    }
}


public class Test {

    public static void main(String[] args) {
        func();

        System.out.println("after try catch");
    }
    public static void func() {
        int[] arr = {1, 2, 3};
        try{
            System.out.println(arr[100]);

        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("try catch");
        }
    }
    public static void main2(String[] args) {
        String s = "hello";
// 字符串转数组
        char[] ch = s.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            System.out.print(ch[i]);
        }
        System.out.println();
// 数组转字符串
        String s2 = new String(ch);
        System.out.println(s2);
    }

    public static void main1(String[] args) {
        String s1 = "hello";
        String s2 = new String("world");
        System.out.println(s1.charAt(1));

        String s3 = String.valueOf(111);
        System.out.println(s3);

        int a = Integer.parseInt("222");
        System.out.println(a);
    }


}
