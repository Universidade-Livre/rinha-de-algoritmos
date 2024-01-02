package main

import (
	"bufio"
	"fmt"
	"os"
)

func knapsack(totalItems int, maxCapacity int, values []int, weights []int) int {
	if totalItems <= 0 || maxCapacity <= 0 {
		return 0
	}

	dp := make([]int, maxCapacity+1)

	for item := 1; item <= totalItems; item++ {
		currentWeight := weights[item-1]
		currentValue := values[item-1]

		for capacity := maxCapacity; capacity >= currentWeight; capacity-- {
			dp[capacity] = max(dp[capacity], dp[capacity-currentWeight] + currentValue)
		}
	}

	return dp[maxCapacity]
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, W, v, w := readInput(reader)
	maxProfit := knapsack(n, W, v, w)
	fmt.Printf("Maximum Profit: %d\n", maxProfit)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func readInput(reader *bufio.Reader) (int, int, []int, []int) {
	var n, W int
	fmt.Fscan(reader, &n, &W)

	v, w := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &w[i], &v[i])
	}

	return n, W, v, w
}
