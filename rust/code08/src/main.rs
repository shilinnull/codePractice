use std::thread;
use std::time::Duration;

fn main() {
    let double = |x| { x * 2 };

    let add = |a, b| { a + b };
    let x = add(2, 4);
    println!("{}", x);

    let y = double(5);
    println!("{}", y);

    let v = 3;
    let add2 = |x| { v + x };
    println!("{}", add2(4));

    let h = std::thread::spawn(|| {
       for i in 1..10 {
           println!("子线程：{}", i);
           thread::sleep(Duration::from_millis(1));
       }
    });
    for i in 1..5 {
        println!("主线程：{}", i);
        thread::sleep(Duration::from_millis(1));
    }
    // 等待子线程
    h.join().unwrap();

}
