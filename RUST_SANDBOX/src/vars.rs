// Varialbes hold primitive data or references to data
// Variables are immutable by default
// Rust is a block-scoped language
// mut keyword is used for mutable variables

pub fn run() {
    let name = "Brad";
    let mut age = 37;
    println!("My name is {} and I am {}", name, age);
    age = 38;
    println!("My name is {} and I am {}", name, age);

    // Define constant
    const ID: i32 = 001;
    println!("ID: {}", ID);

    // Assign multiple vars 
    let (my_name, my_age) = ("Bard", "37");
    println!("{} is {}", my_name, my_age);
}