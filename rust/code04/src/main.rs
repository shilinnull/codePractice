
#[derive(Debug)]
struct Study {
    name: String,
    target: String,
    spend: i32
}
/*实现*/
impl Study {
    fn get_spend(&self)->i32 {
        return self.spend;
    }
}

impl Study {
    fn get_instance_another(name: String, target: String, spend: i32) -> Study {
        return Study {
            name,
            target,
            spend,
        };
    }
}

fn show(s: Study) {
    println!(
        "name is :{} target is {} spend is{}",
        s.name, s.target, s.spend
    );
}

fn get_instance(name: String, target: String, spend: i32) -> Study {
    return Study {
        name,
        target,
        spend,
    };
}


// fn main() {
//     let mut s = Study {
//         name: String::from("111"),
//         target:String::from("222"),
//         spend: 3
//     };
//     s.spend = 5;
//     println!("{:?}", s);
//
//     let s3 = get_instance(
//         String::from("222"),
//         String::from("333"),
//         5,
//     );
//
//     println!("spend {}", s3.get_spend());
//
//     let pair = (String::from("1111"), 2);
//     println!("pair {:?}", pair);
//     println!("pair: 0:{} , 1: {}", pair.0, pair.1);
//
//     let (Study, spend) = pair;
//     println!("spend {}", spend);
//     println!("Study {}", Study);
// }

#[derive(Debug)]
enum RoadMap {
    你好,
    你好1,
    你好2
}

fn getDiscount(price: i32) -> Option<bool> {
    if price > 100 {
        Some(true)
    } else {
        None
    }
}
fn print_road_map(r: RoadMap) {
    match r {
        RoadMap::你好=>{
            println!("hello");
        },
        RoadMap::你好1=>{
            println!("hello1");
        },
        RoadMap::你好2=>{
            println!("hello2");
        }
    }
}

#[derive(Debug)]
enum StudyRoadMap{
    Name(String)
}

fn main() {
    let level = RoadMap::你好;
    println!("level---{:?}",level);

    let result = getDiscount(0);
    println!("result {:?}",result);

    print_road_map(RoadMap::你好);
    print_road_map(RoadMap::你好1);
    print_road_map(RoadMap::你好2);

    let level3 = StudyRoadMap::Name(String::from("111"));
    match level3 {
        StudyRoadMap::Name(val)=>{
            println!("{:?}",val);
        }
    }
}