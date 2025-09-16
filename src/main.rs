
fn main() {
    let argv: Vec<String> = std::env::args().collect();
    let _argc = argv.len();
    for (index, arg) in argv.iter().enumerate() {
        println!("arg[{}] = <{}>", index, arg);
    }
}
