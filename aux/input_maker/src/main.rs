use rand::seq::SliceRandom;
use rand::thread_rng;

const DEFAULT_SIZE: i32 = 50;

fn main() {
    let sz: i32 = std::env::args()
        .next()
        .map(|s| s.parse().ok())
        .flatten()
        .unwrap_or(DEFAULT_SIZE);

    let mut range: Vec<i32> = (-sz..sz).collect();
    let mut rng = thread_rng();
    range.shuffle(&mut rng);

    let out: String = range
        .iter()
        .take(sz as usize)
        .map(|num| num.to_string())
        .collect::<Vec<String>>()
        .join(" ");
    println!("{}", out);
}
