fn main() {
    let spend = 1;
    {
        let target = "111";
        println!("inner short: {}", target);
        let spend = 2.0;
        println!("inner long: {}", spend);
    }
    // println!("outer short: {}", target);
    println!("outer long: {}", spend);
    let spend = String::from("222");
    println!("outer spend: {}", spend);


    let spend;
    {
        let x = 2;
        spend = x * x;
    }
    println!("spend: {}", spend);

    let spend2;
    // 未初始化变量不能使用
    // println!("spend2: {}", spend2);
    spend2 = 1;
    println!("another binding: {}", spend2);

    println!("====================================");
    let mut spend4 = Box::new(1);
    let spend5 = &spend4;
    // spend4= Box::new(100);  // 冻结
    println!("{}", spend4);
    println!("{}", spend5);

    let spend = 1;
    let cost:f64 = spend as f64;    // 可以显示转换

    let x = 1u8;
    let y = 2.1f32;

    let study = String::from("hello");

    let mut vec = Vec::new();
    vec.push(x);
    println!("{:?}", vec);

    // ======================
    // 别名
    type MyU64 = u64;
    type OtherU64 = u64;
    type ThirdU64 = u64;

    let MyU64: MyU64 = 5 as ThirdU64;
    let otherU64: OtherU64 = 2 as ThirdU64;
    println!(
        "{} MyU64 + {} OtherU64es = {} unit?",
        MyU64,
        otherU64,
        MyU64 + otherU64
    );
    // ============
    let s1 = "1111111";
    let s2 = String::from(s1);

    let my_number = MyNumber{num:1};
    println!("{:?}", my_number);

    // let spend = 3;
    // let my_spend: MyNumber = spend.into();
    // println!("{:?}", my_spend);

    let cost: i32 = "5".parse().unwrap();
    println!("{}", cost);

}
#[derive(Debug)]
struct MyNumber {
    num: i32,
}

impl MyNumber {
    fn from(item: i32) ->Self{
        MyNumber{num: item}
    }
}

