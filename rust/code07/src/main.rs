use std::fs;
use std::fs::{File, OpenOptions};
use std::io::{Read, Write};

fn main() {
    let  v = vec!["111", "222", "333"];
    let mut it = v.iter();
    println!("{:?}",it.next());
    println!("{:?}",it.next());
    println!("{:?}",it.next());
    println!("{:?}",it.next());

    let iter = v.iter();
    for item in iter{
        print!("{}\n",item);
    }


    let q = std::io::stdin().read_line( & mut String::new() ).unwrap();
    let file = File::open("data.txt").unwrap();
    println!("文件打开成功\n:{:?}",file);

    let file = std::fs::File::create("data1.txt").expect("create failed");
    println!("文件创建成功:{:?}",file);
    fs::remove_file(String::from("data1.txt")).expect("remove failed");

    let mut file = OpenOptions::new().append(true).open("data.txt").expect("失败");
    file.write("\n222".as_bytes()).expect("写入失败");
    println!("\n数据追加成功");

    file.write_all("Rust\n".as_bytes()).expect("create failed");

    println!("数据已写入完毕");

    let mut file = std::fs::File::open("data.txt").unwrap();
    let mut contents = String::new();
    file.read_to_string(&mut contents).unwrap();
    println!("{:?}", contents);
}




