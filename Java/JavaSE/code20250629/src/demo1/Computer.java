package demo1;

import java.security.Key;

public class Computer implements USB{

    @Override
    public void openDevice() {
        System.out.println("打开笔记本");
    }

    @Override
    public void closeDevice() {
        System.out.println("关闭笔记本");
    }
    public void useDevice(USB usb){
        usb.openDevice();
        if(usb instanceof Mouse){
            Mouse mouse = (Mouse)usb;
            mouse.click();
        } else if (usb instanceof KeyBoard) {
            KeyBoard keyboard = (KeyBoard)usb;
            keyboard.inPut();
        }
        usb.closeDevice();
    }
}
