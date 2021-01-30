/*
Primitive Types--
Integers: u8, i8, u16, i16, u32, i32 (number of bits they take in memory)
Floats: f32, f64
Boolean (bool)
Characters (char)
Tuples
Arrays
*/

pub fn run() {
    // Default is "i32"
    let x = 1;

    // Default is "f64"
    let y = 2.5;

    // Add explicit type
    let z: i64 = 454545454545;

    // Find max size 
    println!("Max i32: {}", std::i32::MAX);
    println!("Max i64: {}", std::i64::MAX);

    // let is_active = true;
    // let is_active: bool = true;
    let is_active: bool = 10 > 5;
    println!("{:?}", (x, y, z, is_active));

    let a1 = 'a';
    let face = '\u{1F600}';

    println!("{:?}", (x, y, z, is_active, a1, face));
}