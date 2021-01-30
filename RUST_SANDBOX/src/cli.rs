use std::env;

pub fn run() {
    let args: Vec<String> = env::args().collect();
    let command = args[1].clone();
    let name = "Brad";

    // println!("Args: {:?}", args);
    println!("Command: {}", command);

    if command == "hello" {
        println!("Hi {}, how are you?", name);
    }
}