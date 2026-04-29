

use mylib::add_salary::study;

fn main() {
    study("你好".to_string());
}

pub mod mod1{
    pub mod mod2{
        pub mod mod3{
            pub mod mod4{
                //
            }
        }
    }
}

pub mod public_model {
    pub fn public_function() {
        // 公开的方法
    }
    fn private_function() {
       // 私有
    }
}

mod private_module {
    fn function() {
        // 私有
    }
}

use public_model::public_function;
