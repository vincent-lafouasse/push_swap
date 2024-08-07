use rand::seq::SliceRandom;
use rand::thread_rng;

const DEFAULT_SIZE: i32 = 1000;

fn main() {
    let mut rng = thread_rng();
    let mut y: Vec<i32> = (1..5).collect();
    println!("Unshuffled: {:?}", y);
    y.shuffle(&mut rng);
    println!("Shuffled:   {:?}", y);
}
