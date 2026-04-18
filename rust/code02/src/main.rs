

fn get_name() -> String {
    return String::from("rust");
}

fn get_name2() -> String {
    String::from("rust2")
}

fn show_name(name:&mut String){
    let mut s:char = 'c';
    name.push(s);
    println!("{}",*name);
}
fn show_tuple(tuple:(&str,&str)){
    println!("{:?}",tuple);
}

fn main() {
    let arr1:[&str;3]=["1","2","3"];

    let arr2=["1","2","3"];

    let arr3:[&str;3]=["";3];
    println!("长度：{}",arr1.len());

    for item in arr1{
        print!("数字 :{}\n",item);
    }



    // let t:(&str,&str) = ("1","2");
    // println!("{:?}",t); // 调试打印格式
    // println!("{}",t.0);
    // println!("{}",t.1);

    // println!("r1:{}", get_name());
    // println!("r2:{}", get_name2());
    // let mut name:String = String::from("c++");
    // println!("{}", name);
    // show_name(&mut name);
    // println!("{}", name);
}