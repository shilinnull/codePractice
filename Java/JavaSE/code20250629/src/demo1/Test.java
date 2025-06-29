package demo1;

public class Test {
    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.openDevice();

        computer.useDevice(new Mouse()); // 使用鼠标
        computer.useDevice(new KeyBoard()); // 使用键盘

        computer.closeDevice();
    }
}
