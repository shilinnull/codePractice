

class myThread extends Thread {
    @Override
    public void run() {
        while (true) {
            System.out.println("Thread run");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

class Runable1 implements Runnable {
    @Override
    public void run() {
        while (true) {
            System.out.println("thread runable run");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

public class demo01 {
    public static void main(String[] args) throws InterruptedException {
        myThread t1 = new myThread();
        t1.start();

        myThread t2 = new myThread() {
            @Override
            public void run() {
                while (true) {
                    System.out.println("thread 内部");
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
        };
        t2.start();


        Runable1 t3 = new Runable1();
        t3.run();

        while (true) {
            System.out.println("main-thread");
            Thread.sleep(1000);
        }
    }
}
