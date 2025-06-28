package domo2;

import java.awt.*;

public class Test {
    public static void main(String[] args) {
        Rect rect = new Rect();
        cycle cycle = new cycle();
        flower flower = new flower();

        shape[] shapes = {rect, cycle, flower};


        // 实现多态
        for(shape e : shapes) {
            e.draw();
        }
    }
}
