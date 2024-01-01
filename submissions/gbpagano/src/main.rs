use std::env;
use std::fs::File;
use std::io::{self, BufRead};

fn main() {
    let args: Vec<_> = env::args().collect();
    let file = File::open(&args[1]).unwrap();

    let lines: Vec<_> = io::BufReader::new(file)
        .lines()
        .map(|line| line.unwrap())
        .collect();

    let capacity = lines[0]
        .split_whitespace()
        .nth(1)
        .unwrap()
        .parse::<usize>()
        .unwrap();

    let items: Vec<(usize, usize)> = lines[1..]
        .iter()
        .map(|line| {
            let parts = line.split_whitespace().collect::<Vec<_>>();
            (parts[0].parse().unwrap(), parts[1].parse().unwrap())
        })
        .collect();

    let mut max_values = vec![0; capacity + 1];

    for (weight, value) in items {
        for w in (weight..=capacity).rev() {
            max_values[w] = max_values[w].max(max_values[w - weight] + value);
        }
    }

    println!("result: {}", max_values[capacity]);
}
