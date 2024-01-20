use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn knapsack(space: i64, array: &[(i64, i64, f64)]) -> i64 {
    let n = array.len();
    let mut dp = vec![0; (space + 1) as usize];

    for i in 0..n {
        let (wi, vi, _) = array[i];
        for j in (wi..=space).rev() {
            dp[j as usize] = dp[j as usize].max(vi + dp[(j - wi) as usize]);
        }
    }

    dp[space as usize]
}

fn execute_algorithm(file_path: &str) -> i64 {
    let file = File::open(file_path).unwrap();
    let reader = BufReader::new(file);

    let mut lines = reader.lines();
    let first_line = lines.next().unwrap().unwrap();
    let mut values = first_line.split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let _n = values.next().unwrap();
    let w = values.next().unwrap();

    let mut file_array = Vec::new();

    for line in lines {
        let mut row: Vec<f64> = line.unwrap()
            .split_whitespace()
            .map(|x| x.parse::<f64>().unwrap())
            .collect();
        let ratio = row[1] / row[0];
        row.push(ratio);
        file_array.push((row[0] as i64, row[1] as i64, ratio));
    }

    knapsack(w, &file_array)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let file_path = &args[1];
    println!("{:>10}", execute_algorithm(file_path));
}