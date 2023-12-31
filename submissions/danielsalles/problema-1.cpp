#include <iostream>
#include <vector>
#include <algorithm>

struct Seed {
    int cost;
    int profit;
    int space;
    Seed(int c, int p, int s) : cost(c), profit(p), space(s) {}
};

int calculateMaxProfit(const std::vector<Seed>& seeds, int availableSpace) {
    int n = seeds.size();
    std::vector<int> dp(availableSpace + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = availableSpace; j >= seeds[i].space; j--) {
            dp[j] = std::max(dp[j], dp[j - seeds[i].space] + seeds[i].profit);
        }
    }

    return dp[availableSpace];
}

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<Seed> seeds;
    seeds.reserve(N);

    for(int i = 0; i < N; i++) {
        int cost, profit, space;
        std::cin >> space >> profit;
        cost = 0;
        seeds.push_back(Seed(cost, profit, space));
    }

    int maxProfit = calculateMaxProfit(seeds, W);
    std::cout << maxProfit << std::endl;

    return 0;
}
