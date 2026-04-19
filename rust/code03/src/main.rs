fn main() {
    let mut v = vec![1, 2, 3];
    show_v(&mut v);
    println!("{:?}",v);

    let mut v1 = Vec::new();
    v1.push("111");
    v1.push("222");
    v1.push("333");
    println!("{:?}",v1.len());
    let s2 = &v1[1..2];
    println!("{:?}",s2);

    let mut v2 = Vec::new();
    v2.push("111");
    v2.push("222");
    v2.push("333");
    show_v1(&mut v2[1..3]);
}
fn show_v(v: &mut Vec<i32>){
    v[0] = 100;
    println!("{:?}",v);
}

fn show_v1(v: &mut [&str]){
    v[0] = "1000";
    println!("{:?}",v);
}

