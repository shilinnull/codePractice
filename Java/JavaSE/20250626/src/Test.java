import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[] a = {1, 23, 765,0};
        Arrays.sort(a);


        System.out.println(Arrays.toString(a));
    }
    public static void main4(String[] args) {
        int[] arr = fun(10);
        for (int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        int[] newArr = Arrays.copyOf(arr, arr.length);
        for (int i = 0; i < newArr.length; i++)
        {
            System.out.print(newArr[i] + 1 + " ");
        }
        System.out.println();

        int[] newArr1 = Arrays.copyOfRange(arr, 1, 4);
        for (int i = 0; i < newArr1.length; i++)
        {
            System.out.print(newArr1[i] + 1 + " ");
        }
    }

    private static int[] fun(int n) {
        if(n < 0) return null;

        int[] dp = new int[n];
        dp[0] = dp[1] = 1;
        for(int i = 2; i < 10; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp;
    }

    public static void main3(String[] args) {
        int[] array1 = new int[3];
        int[] array2 = new int[]{1, 2, 3};
        for (int i = 0; i < array2.length; i++){
            System.out.println(array2[i]);
            System.out.println(array1[i]);
        }
    }

    public static String myToString(int[] array) {
        // 添加[
        String ret = "[";
        for(int i = 0; i < array.length; i++) {
            ret += array[i];

            if(i != array.length - 1)
                ret += ", ";
        }

        ret += "]";
        return ret;
    }

    public static void main2(String[] args) {
        int[] array = {1, 2, 3, 4};
        System.out.println(myToString(array));
    }
    public static void main1(String[] args) {
        int[] array = {1, 2, 3, 4};
        String ret = Arrays.toString(array);
        System.out.println(ret);
        System.out.println(array);
        System.out.println(array.length);
    }
}
