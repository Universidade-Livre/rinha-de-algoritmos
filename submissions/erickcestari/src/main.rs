use std::{
    cmp, env,
    fs::File,
    io::{self, BufRead}, time::Instant,
};

fn knapsack(seeds: &Vec<(usize, usize)>, capacity: usize) -> usize {
    let n = seeds.len();
    let mut dp = vec![vec![0; (capacity + 1) as usize]; n + 1];

    for i in 1..=n {
        for j in 0..=capacity {
            if seeds[i - 1].0 > j {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = cmp::max(
                    dp[i - 1][j],
                    dp[i - 1][(j - seeds[i - 1].0) as usize] + seeds[i - 1].1,
                );
            }
        }
    }

    dp[n][capacity]
}

fn main(){
    let start_time = Instant::now();
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        std::process::exit(1);
    }
    let filename = &args[1];

    let path = std::path::Path::new(filename);
    let file = File::open(&path).unwrap();

    let lines: Vec<_> = io::BufReader::new(file)
        .lines()
        .map(|line| line.unwrap())
        .collect();

    let first_line: Vec<usize> = lines[0]
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let capacity = first_line[1];

    let seeds: Vec<(usize, usize)> = lines[1..]
        .iter()
        .map(|line| {
            let mut iter = line.split_whitespace();
            let space: usize = iter.next().unwrap().parse().unwrap();
            let value: usize = iter.next().unwrap().parse().unwrap();
            (space, value)
        })
        .collect();

    let result = knapsack(&seeds, capacity);
    
    println!("Maior lucro possível: {}", result);
    let elapsed_time = start_time.elapsed();
    println!("{}", elapsed_time.as_micros());
}
