import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        int[] arr1 = new int[]{1, 2, 3};
        int[] arr2;
        arr2 = new int[]{1, 2, 3};
        int[] arr3;
//        arr3 = {1， 2， 3};
        for(int i = 0;i < arr1.length; i++){
            System.out.println(arr1[i]);
        }

        for(int e : arr2){
            System.out.println(e);
        }
    }
    public static void main10(String[] args) {
        for(int i = 0 ; i < 999999; i++) {
            // 求出位数
            int count = 0;
            int tmp = i;
            while(tmp != 0)
            {
                count++;
                tmp /= 10;
            }
            // 再算多少
            tmp = i;
            int sum = 0;
            while(tmp != 0)
            {
                sum += Math.pow(tmp % 10, count);
                tmp /= 10;
            }
            if(sum == i){
                System.out.println(i);
            }
        }
    }

    public static void main9(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNextInt()) {
            int a = in.nextInt();
            System.out.println(a);
        }
    }
    public static void main8(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入你的姓名");
        String name = sc.nextLine();
        System.out.println(name);
        sc.close();
    }

    public static void main7(String[] args) {
        int a = 10;
        int b = 20;
        System.out.println(a | b);
        int c = 0xa;
        System.out.printf("%x\n", c);
    }

    public static int sum(int n) {
        if(n == 1) return 1;
        return n + sum(n - 1);
    }
    public static int sum1(int n) {
        if(n < 10) return n;
        return n % 10 + sum1(n / 10);
    }
    public static void main6(String[] args) {
        int i = 1;
        while (i <= 100) {
            if (i % 3 == 0 && i % 5 == 0)
                System.out.println(i);
            i++;
        }
        int n = sum(10);
        System.out.println(n);
//        System.out.println(i);
    }

    public static void main5(String[] args) {
        char a = '张';
        boolean b = true;
        System.out.println(b);
        String c = "hello";
        String d = "world";
        System.out.println(c + " " + d);

        int num = 100;
        String arr = String.valueOf(num);
        System.out.println(arr);

        String arr1 = "200";
//        int f = Integer.parseInt(arr1);
        int f = Integer.valueOf(arr1);
        System.out.println(f);

    }

    public static void main4(String[] args) {
        byte a = 10;
        System.out.println(a);
        System.out.println(Byte.MAX_VALUE);
        System.out.println(Byte.MIN_VALUE);
        System.out.println(10 / 1.2);
    }

    public static void main3(String[] args) {
        short a = 10;
        System.out.println(a);
        System.out.println(Short.MAX_VALUE);
        System.out.println(Short.MIN_VALUE);
    }

    public static void main2(String[] args) {
        long a = 10L;
        System.out.println(a);
        System.out.println(Long.MAX_VALUE);
        System.out.println(Long.MIN_VALUE);
    }

    public static void main1(String[] args) {
        int a = 10;
        System.out.println(a);
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);
    }
}
