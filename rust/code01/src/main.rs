
// fn main() {
//     println!("u128 = {}", std::u128::MAX);
//     println!("i128 = {}", std::i128::MAX);
//
//     let price = 10;
//     let price1 = 10.0;
//     let price2 = "hello";
//     println!("price: {}, price1: {}, price2: {}", price, price1, price2);
//     println!("Hello, world!");
// }

fn main() {
    let price = 100;    // i32 默认
    let price2:u32 = 200;
    let price3:i32 = -300;
    let price4:isize = 400;
    let price5:usize = 500;
    let check:bool = false;
    let ch: char = 'A';
    println!("{}", check);
    println!("{}", check);

    let mut price = 188;
    price=288;
    println!("{}",price);

    const PI:f64 = 3.1415926;
    println!("{}", PI);

    static BOOK:&'static str = "hello";
    println!("{}", BOOK);
    let s1= String::new();
    let mut s2 = String::from("hello");
    s2.push('c');
    println!("{} {}", s1.len(), s2);
    let s3 = "hello".to_string();
    println!("{}", s3);

    let s11="hello".to_string();
    let s12 = "111".to_string();
    let result2= s11 + &s12;
    println!("{}",result2);

    let code = "10010";
    let choose = match code {
        "10010" => "联通",
        "10086" => "移动",
        _ => "Unknown"
    };
    println!("选择 {}", choose);

    let code = "80010";
    let choose = match code {
        "10010" => "联通",
        "10086" => "移动",
        _ => "Unknown"
    };
    println!("选择 {}", choose);
    for i in 1..10 {
        println!("{}", i);
    }

    for i in 1..=5 {
        println!("{}", i);
    }

    // let studyList = vec![
    //     "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11",
    // ];
    // for s in studyList.iter() {
    //     match s {
    //         &"1" => println!("1: {}", studyList[1]),
    //         &"2" => println!("2: {}", studyList[2]),
    //         &"3" => println!("3: {}", studyList[3]),
    //         _ => println!("other")
    //     }
    // }
    // let studyList = vec![
    //     "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11",
    // ];
    // for s in studyList.into_iter() {
    //     match s {
    //         "1" => println!("1: {}", 1),
    //         "2" => println!("2: {}", 2),
    //         "3" => println!("3: {}", 3),
    //         _ => println!("other")
    //     }
    // }

    println!("=======================");

    let mut studyList = vec![
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11",
    ];
    for s in studyList.iter_mut() {
        *s = match s {
            &mut "1" => {"222"}
            _ => {"333"}
        };
        println!("{}", s);
    }

    let mut num = 1;
    loop {
        if num > 20{
            break;
        }
        println!("num is {}",num);
        num= num*3;
    }
}