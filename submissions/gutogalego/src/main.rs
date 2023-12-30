use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::time::Instant;

fn knapsack(items: &[(usize, usize)], capacity: usize) -> usize {
    let mut dp = vec![0; capacity + 1];

    for &(weight, value) in items {
        for w in (weight..=capacity).rev() {
            dp[w] = std::cmp::max(dp[w], dp[w - weight] + value);
        }
    }

    dp[capacity]
}

fn main() -> io::Result<()> {
    let start = Instant::now();
    let path = Path::new("exemplo_03.txt");
    let file = File::open(&path)?;

    let lines: Vec<String> = io::BufReader::new(file).lines().filter_map(|line| line.ok()).collect();
    let capacity: usize = lines[0].split_whitespace().nth(1).unwrap().parse().unwrap();

    let items: Vec<(usize, usize)> = lines[1..]
        .iter()
        .map(|line| {
            let parts: Vec<&str> = line.split_whitespace().collect();
            let weight: usize = parts[0].parse().unwrap();
            let value: usize = parts[1].parse().unwrap();
            (weight, value)
        })
        .collect();

    let max_value = knapsack(&items, capacity);
    let duration = start.elapsed();

    println!("Solution: {}", max_value);
    println!("Time taken: {:?}", duration);

    Ok(())
}
