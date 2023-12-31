use std::env;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() -> io::Result<()> {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        std::process::exit(1);
    }
    let filename = &args[1];

    let path = Path::new(filename);
    let file = File::open(&path)?;

    let lines: Vec<String> = io::BufReader::new(file).lines().filter_map(|line| line.ok()).collect();
    let capacity: usize = lines[0].split_whitespace().nth(1).unwrap().parse().unwrap();

    let mut items: Vec<(usize, usize, f64)> = lines[1..]
        .iter()
        .map(|line| {
            let parts: Vec<&str> = line.split_whitespace().collect();
            let weight: usize = parts[0].parse().unwrap();
            let value: usize = parts[1].parse().unwrap();
            let ratio: f64 = value as f64 / weight as f64;
            (weight, value, ratio)
        })
        .collect();

    items.sort_by(|a, b| b.2.partial_cmp(&a.2).unwrap());

    let mut max_value: f64 = 0.0;
    let mut remaining_capacity = capacity;

    for &(weight, value, _) in &items {
        if weight <= remaining_capacity {
            max_value += value as f64;
            remaining_capacity -= weight;
        } else {
            max_value += value as f64 * (remaining_capacity as f64 / weight as f64);
            break;
        }
    }

    println!("Solution: {}", max_value);

    Ok(())
}