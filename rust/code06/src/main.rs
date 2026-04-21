use std::fmt::{Display, Formatter};
use std::io::Write;

struct Data<T> {
    value: T
}


struct Book {
    name: String,
    id: u32,
    author: String,
}

trait ShowBook {
    fn show_book(&self);
}
impl ShowBook for Book {
    fn show_book(&self) {
        println!("Id:{},Name:{},Author:{}",self.id,self.name,self.author);
    }
}

fn show2<T:Display>(t:T){
    println!("{}",t);
}

impl Display for Book{
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        println!("Id:{},Name:{},Author:{}",self.id,self.name,self.author);
        let r=Result::Ok(());
        return r;
    }
}

fn main() {
    let input_args = std::env::args();
    for arg in input_args{
        println!("命令行参数:[{}]",arg);
    }
    
    let mut in_word = String::new();
    let result = std::io::stdin().read_line(&mut in_word).unwrap();
    println!("您的输入是: {}", in_word);
    println!("读取的字节数为: {}", result);

    let result1 = std::io::stdout().write("1111".as_bytes()).unwrap();
    println!("写入的字节数为: {}\n", result1);

    println!("==================================================");
    let book = Book {
        id: 1, name: String::from("1111"), author: String::from("222")
    };
    book.show_book();
    show2(book);

    let mut v:Vec<i32> = vec![1,2,3,4,5,6,7,8,9];
    v.push(111);
    let t:Data<i32> = Data{value:100};
    println!("t.value : {}", t.value);

}
