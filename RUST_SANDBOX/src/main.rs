mod print;
mod vars;
mod types;
mod strings;
mod tuples;
mod arrays;
mod vectors;
mod conditionals;
mod loops;
mod functions;
mod pointer_ref;
mod structs;
mod enums;
mod cli;
mod encoder;

fn main() {
    // print::run();
    // vars::run();
    // types::run();
    // strings::run();
    // tuples::run();
    // arrays::run();
    // vectors::run();
    // conditionals::run();
    // loops::run();
    // functions::run();
    // pointer_ref::run();
    // structs::run();
    // enums::run();
    // cli::run();
    // println!("{:?}", "zt??A_r????".as_bytes());
    println!("{:?}", encoder::escape("A".as_bytes()));
    // println!("{:?}", encoder::unescape(str(\200\000\000\000\000\000\000\377\027)));
}

