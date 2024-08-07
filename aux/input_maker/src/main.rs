use rand::seq::SliceRandom;
use rand::thread_rng;

const DEFAULT_SIZE: i32 = 50;

fn main() {
    let mut rng = thread_rng();
    let args: Vec<String> = std::env::args().collect();

    let sz: i32 = match args.len() {
        2 => args[1].parse().unwrap(),
        _ => DEFAULT_SIZE,
    };

    let mut range: Vec<i32> = (-sz..sz).collect();
    range.shuffle(&mut rng);

    let sz: usize = sz.try_into().unwrap();
    let slice = &range[..sz];

    let out: String = slice
        .iter()
        .map(|num| num.to_string())
        .collect::<Vec<String>>()
        .join(" ");
    println!("{}", out);
}
