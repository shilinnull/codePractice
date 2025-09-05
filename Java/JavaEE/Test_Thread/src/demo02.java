public class demo02 {
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(()->{
            for (int i = 0; i < 10; i++) {
                System.out.println("hello thread");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            System.out.println("t1 结束");
        });
        t1.start();
//        System.out.println(t1.getState());
        t1.join(3000); // 等待3秒
        System.out.println(t1.getState());
        System.out.println("main 结束");
    }
}
