use std::collections::{HashMap, HashSet};

fn main() {
    let mut v1 = vec![1, 2, 3, 4, 5, 6, 7, 8];
    let mut v2 = Vec::new();
    v2.push("111");
    v2.push("222");
    v2.push("333");
    println!("{:?}", v2);
    if v2.contains(&"222") {
        println!("找到了");
    }
    let mut h1 = HashMap::new();
    h1.insert("111", 1);
    h1.insert("222", 2);
    h1.insert("333", 3);
    match h1.get(&"111"){
        Some(v)=>{
            println!("HashMap v:{}", v);
        }
        None=>{
            println!("找不到");
        }
    }
    for (k, v) in h1.iter() {
        println!("k: {} v: {}", k, v);
    }

    let mut studySet = HashSet::new();
    studySet.insert("111");
    studySet.insert("222");
    studySet.insert("333");
    println!("{:?}", studySet);

    studySet.insert("444");
    println!("{:?}", studySet);
}
