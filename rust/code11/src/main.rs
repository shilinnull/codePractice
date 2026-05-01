fn main() {
    // 获得一个 `i32` 类型的引用。`&` 表示取引用。
    let num = &100;

    match num {
        // 用 `&val` 这个模式去匹配 `num`
        &val => println!("&val 是: {:?}", val),
    }

    // 如果不想用 `&`，需要在匹配前解引用。
    match *num {
        val => println!("val 是: {:?}", val),
    }

    // Rust 对这种情况提供了 `ref`。它更改了赋值行为，从而可以对具体值创建引用。
    // 下面这行将得到一个引用。
    let ref num3 = 66;

    // 相应地，定义两个非引用的变量，通过 `ref` 和 `ref mut` 仍可取得其引用。
    let num4 = 5;
    let mut mut_num4 = 7;

    // 使用 `ref` 关键字来创建引用。
    // 下面的 r 是 `&i32` 类型，它像 `i32` 一样可以直接打印，因此用法上
    // 似乎看不出什么区别。但读者可以把 `println!` 中的 `r` 改成 `*r`，仍然能
    // 正常运行。前面例子中的 `println!` 里就不能是 `*val`，因为不能对整数解
    // 引用。
    match num4 {
        ref r => println!("num4 r is: {:?}", r),
    }

    // 类似地使用 `ref mut`。
    match mut_num4 {
        ref mut m => {
            // 已经获得了 `mut_value` 的引用，先要解引用，才能改变它的值。
            *m += 10;
            println!("`mut_value`: {:?}", m);
        }
    }
    main1();

    main2();

    main3();

    main4();

    main5();

    main6();

    main7();

}


fn do1<F>(f: F, x: i32) -> impl Fn(i32) -> i32
where
    F: Fn(i32, i32) -> i32{
    move |y| f(x, y)
}

fn do2<F, X, Y, Z>(f: F, x: X) -> impl Fn(Y) -> Z
where
    F: Fn(X, Y) -> Z,
    X: Copy{
    move |y| f(x, y)
}

fn main7() {
    let add = |x, y| x + y;
    let result = do1(add, 5);
    println!("result(1) => {}", result(1));

    let add = |x, y| x + y;
    let result = do2(add, 5);
    println!("result(2) => {}", result(2));
}

fn returns_closure() -> impl Fn(i32) -> i32 {
    |x| x + 6
}

fn main6() {
    let closure = returns_closure();
    println!("返回闭包 => {}", closure(1));
}

fn receives_closure2<F>(closure:F)
where
    F:Fn(i32)->i32{
    let result = closure(1);
    println!("closure(1) => {}", result);
}

fn main5() {
    let y = 2;
    receives_closure2(|x| x + y);

    let y = 3;
    receives_closure2(|x| x + y);
}

fn receives_closure<F>(closure: F)
where
    F: Fn(i32, i32) -> i32,
{
    let result = closure(3, 5);
    println!("闭包作为参数执行结果 => {}", result);
}

fn main4() {
    let add = |x, y| x + y;
    receives_closure(add);
}

fn main3(){
    let add = |x, y| x + y;
    let result = add(3, 4);
    println!("{}", result);



}

struct Study {
    name: String,
    target: String,
    spend: u32,
}

fn main1(){
    let s = Study {
        name: String::from("111"),
        target: String::from("222"),
        spend: 3,
    };

    let Study {
        name: name,
        target: target,
        spend: spend,
    } = s;

    println!("name = {}, target = {},  spend = {} ", name, target, spend);
    let s2 = Study {
        name: String::from("111"),
        target: String::from("222"),
        spend: 5,
    };
    // 也可以忽略某些变量
    let Study { name, .. } = s2;
    println!("name = {}", name);
}
fn main2(){
    let s = Some("111");
    let s1: Option<i32> = None;
    let s2: Option<i32> = None;

    // 如果 `let` 将 `s` 解构成 `Some(i)`，则执行语句块（`{}`）
    if let Some(i) = s {
        println!("已上车 {:?}!", i);
    }

    // 如果要指明失败情形，就使用 else：
    if let Some(i) = s1 {
        println!("Matched {:?}!", i);
    } else {
        // 解构失败。切换到失败情形。
        println!("不匹配。");
    };

    // 提供另一种失败情况下的条件。
    let flag = false;
    if let Some(i) = s2 {
        println!("Matched {:?}!", i);
    // 解构失败。使用 `else if` 来判断是否满足上面提供的条件。
    } else if flag {
        println!("不匹配s2");
    } else {
        // 条件的值为 false。于是以下是默认的分支：
        println!("默认分支");
    };



    // 将 `optional` 设为 `Option<i32>` 类型
    let mut num = Some(0);

    // 当 `let` 将 `optional` 解构成 `Some(i)` 时，就
    // 执行语句块（`{}`）。否则就 `break`。
    while let Some(i) = num {
        if i > 9 {
            println!("{},quit!",i);
            num = None;
        } else {
            println!("`i` is `{:?}`. Try again.", i);
            num = Some(i + 1);
        }
    }
}